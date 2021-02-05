#include <iostream>
#include <vector>
#include <string>
#include <array>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

vector<char> ejercicio1(string cad){
	vector<char> cad1;
	for(int i = 0;i<cad.length();i++){
		int cont = 0;
		char aux = cad.at(i);
		if(cad1.empty()){
			cad1.push_back(aux);
		}else{
			for(int j = 0; j<cad1.size();j++){
				if(cad1[j]==aux){
				cont++;
				}
			}
			if(cont==0){
				cad1.push_back(aux);	
			}
		}		
	}
	return cad1;
}

int* ejercicio2 (vector<char> vl, string cad,int tamano){
	int* resp = new int[tamano];
	for(int i = 0; i<tamano;i++){
		int cont = 0;
		for(int j = 0;j<cad.length();j++){
			if(vl[i] == cad.at(j)){
				cont++;
			}
		}
		resp[i] = cont;
	}
	return resp;
	delete[]resp;
}

int* ejercicio3 (int*numeros,int tamal){
	int mayor = 0,cont2 = 0;
	int*resp = new int[tamal];
	for(int i = 0; i<tamal;i++){
		for(int j = 0;j<tamal;j++){
			if(numeros[j]>=numeros[i]){
				mayor = numeros[j];
				cont2 = mayor;
			}
		}
	}
	int cont=0;
	for(int p = 0; p<tamal;p++){
		for(int k = 0;k<tamal;k++){
			if(numeros[k]==cont2){
				int numa = k;
				resp[cont]=numa;
				cont++;
			}
		}
		cont2--;
	}
	return resp;
	delete[]resp;
}

string ejercicio4 (string pala){
	string resp4;
	vector<char> tin = ejercicio1(pala);
	int tama = tin.size();
	int*resp2 = new int[tama];
	resp2=ejercicio2(tin,pala,tama);
	int*resp3 = new int[tama];
	resp3 = ejercicio3(resp2,tama);
	for(int g = 0; g<tama; g++){
		char let = tin.at(g);
		int numero = resp2[g];
		for(int h = 0;h<numero;h++){
			resp4+=let;
		}
	}
	return resp4;
}

int main(int argc, char** argv) {
	int opcion = 0;
	while(opcion!=5){
		cout<<"+++++Menu+++++"<<endl;
		cout<<"1. Ejercicio 1"<<endl;
		cout<<"2. Ejercicio 2"<<endl;
		cout<<"3. Ejercicio 3"<<endl;
		cout<<"4. Ejercicio 4"<<endl;
		cout<<"5. Salir Corriendo"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				string palabra;
				cout<<"Ingrese la cadena deseada"<<endl;
				cin>>palabra;
			    for (char elemento : ejercicio1(palabra)) cout << elemento << " ";
			    cout<<endl;
				break;
			}
			case 2:{
				string pal,l;
				int num;
				vector<char> letras;
				cout<<"Ingrese la palabra"<<endl;
				cin>>pal;
				cout<<"Ingrese la cantidad de letras que ingresara en el vector: "<<endl;
				cin>>num;
				cout<<"Ingrese las letras para el vector una por una: "<<endl;
				for(int i = 0; i<num;i++){
					char entrada = 'a';
					cin>>entrada;
					letras.push_back(entrada);
				}
				int* ans = ejercicio2(letras,pal,num);
				for(int j = 0;j<num;j++){
					cout<<ans[j]<<", ";
				}
				cout<<endl;
				break;
			}
			case 3:{
				int num;
				cout<<"Ingrese la cantidad de numeros que va a ingresar: "<<endl;
				cin>>num;
				int* numeros = new int[num];
				cout<<"Ingrese los numeros uno por uno: "<<endl;
				for(int i = 0;i<num;i++){
					cin>>numeros[i];
				}
				int* numr = ejercicio3(numeros,num);
				for (int f = 0;f<num;f++){
					cout << *(numr+f) << " ";
				}	
			    cout<<endl;
				break;
			}
			case 4:{
				string palab;
				cout<<"Ingrese una palabra: "<<endl;
				cin>>palab;
				string resp4r = ejercicio4(palab);
				for(int y = 0;y<resp4r.length();y++){
					cout<<resp4r.at(y)<<", ";
				}
				cout<<endl;
				break;
			}
				
		}
	}
	return 0;
}
