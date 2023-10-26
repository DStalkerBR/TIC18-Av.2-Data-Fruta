#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
	static int dia, mes, ano;
	public:
	
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		if(d1.ano == d2.ano && d1.mes == d2.mes && d1.dia == d2.dia){
			return 0;
		}
		else if(d1.ano > d2.ano || d1.mes > d2.mes || d1.dia > d2.dia){
			return -1;
		}
		else{
			return 1;	
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

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes : public Lista{
	vector<string> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int quant;string nome;
		cout<<"Quantos elementos tera na lista?"<<endl;cin>>quant;
		for(int i=0;i<quant;i++){
			cout<<"Digite o nome: "<<endl;cin>>nome;
			lista.push_back(nome);
		}
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
		if(lista.size()%2 == 0){
			cout<<"Mediana: "<<lista[lista.size()/2]<<endl;
		}
		else{
			cout<<"Mediana: "<<lista[(lista.size()/2)+1]<<endl;
		}
	}
	
	void mostraMenor() {
		string menor;
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
		for(int i = 0;i<lista.size();i++){
			if(lista[i] < lista[i+1]){
				menor = lista[i];
			}
		}
		cout<<menor<<endl;
	}
	void mostraMaior() {
		string maior;
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
		for(int i = 0;i<lista.size();i++){
			if(lista[i] > lista[i+1]){
				maior = lista[i];
			}
		}
		cout<<maior<<endl;
	}
};

class ListaDatas :public Lista {
	vector<Data> lista;
	
	public:
		
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int quant;Data data;
		cout<<"Quantos elementos tera na lista?"<<endl;cin>>quant;
		for(int i=0;i<quant;i++){
			cout<<"Digite o dia: "<<endl;cin>>data.dia;
			cout<<"Digite o mes: "<<endl;cin>>data.mes;
			cout<<"Digite o ano: "<<endl;cin>>data.ano;
			lista.push_back(data);
		}
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
		if(lista.size()%2 == 0){
			cout<<"Mediana: "<<lista[lista.size()/2].toString()<<endl;
		}
		else{
			cout<<"Mediana: "<<lista[(lista.size()/2)+1].toString()<<endl;
		}
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
		for(auto l:lista){
			if(Data::compara(l,lista[0]) == -1){
				cout<<"Menor: "<<l.toString()<<endl;
			}
		}
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
		for(auto l:lista){
			if(Data::compara(l,lista[0]) == 1){
				cout<<"Maior: "<<l.toString()<<endl;
			}
		}
	}
};

class ListaSalarios :public Lista {
	vector<float> lista;
	
	public:
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int quant;float salario;
		cout<<"Quantos elementos tera na lista?"<<endl;cin>>quant;
		for(int i=0;i<quant;i++){
			cout<<"Digite o salario: "<<endl;cin>>salario;
			lista.push_back(salario);
		}
	}
			
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
		if(lista.size()%2 == 0){
			cout<<"Mediana: "<<lista[lista.size()/2]<<endl;
		}
		else{
			cout<<"Mediana: "<<lista[(lista.size()/2)+1]<<endl;
		}
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
		for(auto l:lista){
			if(l < lista[0]){
				cout<<"Menor: "<<l<<endl;
			}
		}
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o maior dos salarios" << endl;
		for(auto l:lista){
			if(l > lista[0]){
				cout<<"Maior: "<<l<<endl;
			}
		}
	}
};


class ListaIdades : public Lista {
	vector<int> lista;
	
	public:
		
		/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() {
		int qunt,idade;
		cout<<"Quantos elementos tera na lista?"<<endl;cin>>qunt;
		for(int i=0;i<qunt;i++){
			cout<<"Digite a idade: "<<endl;cin>>idade;
			lista.push_back(idade);
		}
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
		if(lista.size()%2 == 0){
			cout<<"Mediana: "<<lista[lista.size()/2]<<endl;
		}
		else{
			cout<<"Mediana: "<<lista[(lista.size()/2)+1]<<endl;
		}
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
		for(auto l:lista){
			if(l < lista[0]){
				cout<<"Menor: "<<l<<endl;
			}
		}

	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
		for(auto l:lista){
			if(l > lista[0]){
				cout<<"Maior: "<<l<<endl;
			}
		}
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
    

