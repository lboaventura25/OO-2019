#include "funcoes.hpp"
#include <map>

/*
    Função que recebe tipo 'string' do teclado de forma mais eficiente. 
*/
string getString(){
    string valor;
    getline(cin, valor);
    return valor;
}

/*
    Função que recebe tipo 'int' do teclado de forma mais eficiente. 
*/
int getInt(){
    while(true){
        int valor;
        cin >> valor;
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Entrada inválida! Insira novamente: ";
        }
        else{
            cin.ignore(32767,'\n');
            return valor;
        }
    }
}

/*
    Função que recebe tipo 'float' do teclado de forma mais eficiente. 
*/
int geFloat(){
    while(true){
        float valor;
        cin >> valor;
        if(cin.fail()){
            cin.clear();
            cin.ignore(32767,'\n');
            cout << "Entrada inválida! Insira novamente: ";
        }
        else{
            cin.ignore(32767,'\n');
            return valor;
        }
    }
}

/*
    Função para ordenação do maior pro menor, e em caso de igualdade 
    prevalece a ordem lexicográfica.
*/
bool maior_menor_lexicografica(pair<int, string> &A, pair<int, string> &B) { 
    if(A.first == B.first) 
    	return (A.second < B.second);
    else
    	return (A.first > B.first); 
}