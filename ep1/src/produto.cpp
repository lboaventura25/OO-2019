#include <iostream>
#include <string>
#include <fstream>
#include "produto.hpp"

using namespace std;

/*
    Construtor da classe Produto.  
*/
Produto::Produto() {
    set_codigo("SemCodigo");
    set_nome("Sem");
    set_quantidade(0);
    set_preco(0.0);
}

/*
    Sobrecarga do construtor da classe Produto.  
*/
Produto::Produto(string codigo, string nome, int quantidade, float preco) {
    set_codigo(codigo);
    set_nome(nome);
    set_quantidade(quantidade);
    set_preco(preco);
}


Produto::~Produto() {} // Destrutor da classe Produto.

/*
    Métodos acessores da classe Produto.  
*/
void Produto::set_codigo(string codigo) {
    this->codigo = codigo;
}

string Produto::get_codigo() {
    return this->codigo;
}

void Produto::set_nome(string nome) {
    this->nome = nome;
}

string Produto::get_nome() {
    return this->nome;
}

void Produto::set_quantidade(int quantidade) {
    this->quantidade = quantidade;
}

int Produto::get_quantidade() {
    return this->quantidade;
}

void Produto::set_preco(float preco) {
    this->preco = preco;
}

float Produto::get_preco() {
    return this->preco;
}

/*
    Método para impressão dos atributos da classe Produto.  
*/
void Produto::imprime_dados() {
    cout << "----------------------------------" << endl;
    cout << "Código: " << get_codigo() << endl;
    cout << "Nome do Produto: " << get_nome() << endl;
    cout << "Quantidade: " << get_quantidade() << endl;
    cout << "Preço: " << get_preco() << endl;
    cout << "----------------------------------" << endl;
}

/*
    Método que escreve o Produto no seu arquivo.   
*/
void Produto::cadastro_produto() {
    ofstream saida;
    saida.open("./assets/Cadastro_produtos/"+get_codigo()+".txt", ios::trunc);

    if(saida.is_open()) {
        saida << get_codigo() << endl;
        saida << get_nome() << endl;
        saida << get_quantidade() << endl;
        saida << get_preco() << endl;
        saida.close();
    }
}

/*
    Método que checa se o Produto existe.
    E retorna o caminho do arquivo do Produto caso exista.   
*/
string Produto::check_produto(string codigo) {
    ifstream arquivo;
    string arq = "./assets/Cadastro_produtos/"+codigo+".txt";

    arquivo.open(arq, ios::in);

    if(arquivo.is_open()) {
        return arq;
    } 

    arquivo.close();
    return "Cadastro não encontrado";
}

/*
    Método que carrega um Produto de um arquivo para o programa e o retorna.
*/
Produto * Produto::leArquivo(string arquivo) {
    ifstream entrada;
    Produto * produtos = new Produto();
    string texto;
    int i = 0, quantidade;
    float preco;

    entrada.open(arquivo, ios::in);
    if(entrada.is_open()) {
        getline(entrada, texto);
        produtos->set_codigo(texto);
        i++;
        getline(entrada, texto);
        produtos->set_nome(texto);
        i++;
        getline(entrada, texto);
        quantidade = stoi(texto);
        produtos->set_quantidade(quantidade);
        i++;
        getline(entrada, texto);
        preco = stof(texto);
        produtos->set_preco(preco);
        
        entrada.close();
    }
    return produtos; 
}

/*
    Método que checa se existe uma quantidade x do produto no estoque da loja. 
*/
bool Produto::check_estoque(int quantidade) {
    if(get_quantidade() >= quantidade) {
        set_quantidade(get_quantidade() - quantidade);
        return true;
    }

    return false;
}