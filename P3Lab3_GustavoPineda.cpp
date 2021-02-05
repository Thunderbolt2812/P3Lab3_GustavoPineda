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

int* ejercicio2 (vector<char> vl, string cad){
	int* resp = new int[vl.size()];
	for(int i = 0; i<vl.size();i++){
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

int* ejercicio3 (int*numeros){
	int mayor = 0,cont2 = 0;
	int*resp = new int[sizeof(numeros)];
	for(int i = 0; i<sizeof(numeros);i++){
		for(int j = 0;j<sizeof(numeros);j++){
			if(numeros[j]>=numeros[i]){
				mayor = numeros[j];
				cont2 = mayor;
			}
		}
	}
	for(int p = 0; p<sizeof(numeros);p++){
		for(int k = 0;k<sizeof(numeros);k++){
			if(numeros[k]==cont2){
				resp[p]=k;
				cout<<k<<endl;
				cont2--;
			}
		}
	}
	return resp;
	delete[]resp;
}

/*string ejercicio4 (string pala){
	string resp4;
	for(int i = 0;){
		
	}
	return resp4;
}*/

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
				int* ans = ejercicio2(letras,pal);
				for(int j = 0;j<sizeof(ans);j++){
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
				int* numr = ejercicio3(numeros);
				for (int f = 0;f<sizeof(numr);f++){
					cout << numr[f] << " ";
				}	
			    cout<<endl;
				break;
			}
			case 4:{
				
				break;
			}
				
		}
	}
	return 0;
}
