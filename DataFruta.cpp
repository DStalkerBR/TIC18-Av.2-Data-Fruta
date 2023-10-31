#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O método abaixo retornará -1 se d1 é anterior a d2
	Retornará 0 se d1 = d2
	Retornará +1 se d1 é posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		if(d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia){
			return 0;
		}
		else if(d1.ano > d2.ano || d1.mes > d2.mes || d1.dia > d2.dia){
			return 1;
		}
		else{
			return -1;	
		}
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}

	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class ListaNomes : public Lista{
	vector<string> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() override{
		int quant;string nome;
		cout<<"Quantos elementos tera na lista de nomes? : ";cin>>quant;
		for(int i=0;i<quant;i++){
			cout<<"Digite o "<<i+1<<" nome: ";cin>>nome;
			lista.push_back(nome);
		}
		sort(lista.begin(), lista.end());
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
		
		if(lista.size()%2 == 0){
			cout<<"Mediana: "<<lista[(lista.size()/2)-1]<<endl;
		}
		else{
			cout<<"Mediana: "<<lista[(lista.size()/2)]<<endl;
		}
	}
	
	void mostraMenor() {
		string menor;
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
		cout<<"Menor: "<<lista[0]<<endl;
	}
	void mostraMaior() {
		string maior;
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
		cout<<"Maior: "<<lista[lista.size()-1]<<endl;
	}
};

class ListaDatas :public Lista {
	vector<Data> lista_datas;
	
	public:
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		int quant;
		int dia,mes,ano;
		cout<<"Quantos elementos tera na lista de datas? : ";cin>>quant;
		for(int i=0;i<quant;i++){
			cout<<"Digite o dia da "<<i+1<<" data: ";cin>>dia;
			cout<<"Digite o mes da "<<i+1<<" data: ";cin>>mes;
			cout<<"Digite o ano da "<<i+1<<" data: ";cin>>ano;
			Data data(dia,mes,ano);
			this->lista_datas.push_back(data);
			cout << "Data [" << i << "]: " << data.toString() << " incluida na lista de datas." << endl; 
		}
	}
	
	void mostraMediana() {
		if (!this->lista_datas.empty()) {
				// Copiando a lista de datas para uma nova lista temporária onde as datas
				// aerao ordenadas cronologicamente
				vector<Data> datasOrdenadas = this->lista_datas;


				for (size_t i = 1; i < datasOrdenadas.size(); i++) {
					// Iniciando um loop para percorrer as datas não ordenadas.
					
					Data dataChave = datasOrdenadas[i]; // Copiando a data atual que será inserida na lista ordenada.
					int j = i - 1;

					// Loop para comparar 'dataChave' com as datas anteriores na lista ordenada.
					// E mover datas maiores que a data Chave a direita
					while (j >= 0 && (Data::compara(datasOrdenadas[j], dataChave) == 1)) {
						datasOrdenadas[j + 1] = datasOrdenadas[j];
						j--;
					}
					
					// Movendo a data Chave pra posição a anterior as datas que foram movidas a direita
					datasOrdenadas[j + 1] = dataChave;
				}

				// Calcula o índice da mediana
				size_t tamanhoLista = datasOrdenadas.size();
				size_t indiceMediana = tamanhoLista / 2;

				// Obtém a data mediana (a primeira data se o tamanho for par)
				cout << "A mediana da lista de datas: ";
				if(tamanhoLista%2 == 0){
					cout << datasOrdenadas[indiceMediana - 1].toString() << endl;
				}
				else{
					cout << datasOrdenadas[indiceMediana].toString() << endl;
				}
			}
		else {
			cout << "A lista de datas está vazia." << endl;
		}
	}
	
	void mostraMenor() {
		if (!this->lista_datas.empty()) {
			// Inicializa a primeiraData com o primeiro elemento da lista
			Data primeiraData = this->lista_datas.front();

			// Itera por todas as datas na lista
			for(auto data_atual:this->lista_datas){
				// Compara a data atual com a primeira data na iteração atual
				if(Data::compara(data_atual, primeiraData) == -1){
					// Se a data atual for anterior à primeiraData, atualiza primeiraData
					primeiraData = data_atual;
				}
			}
			cout << "A primeira data cronologicamente e: "<<primeiraData.toString() << endl;
		}
		else {
			cout << "A lista de datas está vazia." << endl;
		}
	}

	void mostraMaior() {
		if (!this->lista_datas.empty()) {
			// Inicializa a ultima_data com o primeiro elemento da lista
			Data ultimaData = this->lista_datas.front();

			// Itera por todas as datas na lista
			for(auto data_atual:this->lista_datas){
				// Compara a data atual com a primeira data na iteração atual
				if(Data::compara(data_atual, ultimaData) == 1){

					// Se a data atual for posterior à ultimaData, atualiza ultimaData
					ultimaData = data_atual;
					
				}
			}
			cout << "A Ultima data cronologicamente e: "<< ultimaData.toString() << endl;
		}
		else {
			cout << "A lista de datas esta vazia." << std::endl;
		}
	}
};

class ListaSalarios : public Lista {
    vector<float> lista;

public:
    void entradaDeDados() override {
        int quant;
        float salario;
        cout << "Quantos elementos terá na lista de salários? : ";
        cin >> quant;
        for (int i = 0; i < quant; i++) {
            cout << "Digite o salário: ";
            cin >> salario;
            lista.push_back(salario);
        }
        sort(lista.begin(), lista.end());
    }

    void mostraMediana() override {
        int n = lista.size();
        if (n % 2 == 0) {
            // Se o número de elementos for par, calcular a mediana como a média dos dois valores do meio.
            float mediana = (lista[n / 2 - 1] + lista[n / 2]) / 2.0;
            cout << "Mediana da lista de salários: " << mediana << endl;
        } else {
            // Se o número de elementos for ímpar, a mediana é o valor do meio.
            cout << "Mediana da lista de salários: " << lista[n / 2] << endl;
        }
    }

    void mostraMenor() override {
        cout << "Menor salário: " << lista[0] << endl;
    }

    void mostraMaior() override {
        cout << "Maior salário: " << lista[lista.size() - 1] << endl;
    }
};


class ListaIdades : public Lista {
    vector<int> lista;

public:
    void entradaDeDados() override {
        int quant, idade;
        cout << "Quantos elementos terá na lista de idades? : ";
        cin >> quant;
        for (int i = 0; i < quant; i++) {
            cout << "Digite a idade: ";
            cin >> idade;
            lista.push_back(idade);
        }
        sort(lista.begin(), lista.end());
    }
//Mostrar a mediana, conforme definido no problema, para um número par
    void mostraMediana() override {
        if(lista.size()%2 == 1){
            cout << "Mediana da lista de idades: " << lista[lista.size() / 2] << endl;
        }
        else{
            cout << "Mediana da lista de idades: " << ((double)lista[lista.size() / 2]+(double)lista[(lista.size() / 2)-1])/2 << endl;
        }
    }

    void mostraMenor() override {
        cout << "Menor idade: " << lista[0] << endl;
    }

    void mostraMaior() override {
        cout << "Maior idade: " << lista[lista.size() - 1] << endl;
    }
};
 
int main () {
	vector<Lista*> listaDeListas;

	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
	
}
    