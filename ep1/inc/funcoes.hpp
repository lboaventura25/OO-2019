#ifndef FUNCOES_CPP
#define FUNCOES_CPP

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

/*
    Assinatura de funções extras para leitura mais segura do teclado. 
*/
string getString();
int getInt();
float getFloat();
bool maior_menor_lexicografica(pair<int, string> &A, pair<int, string> &B);

#endif