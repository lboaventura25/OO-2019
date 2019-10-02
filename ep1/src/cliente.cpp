#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "cliente.hpp"

using namespace std;

Cliente::Cliente() {} // Construtor da classe Cliente.


/*
    Sobrecarga do construtor da classe Cliente.
*/
Cliente::Cliente(string nome, int idade, string cpf, string email) {
    set_nome(nome);
    set_idade(idade);
    set_cpf(cpf);
    set_email(email);
    set_socio(false);
    set_total_de_compras(0);
    cadastra_cliente();
}

Cliente::~Cliente() {} // Destrutor da classe Cliente.


/*
    Métodos acessores da classe Cliente.
*/
void Cliente::set_nome(string nome) {
    this->nome = nome;
}

string Cliente::get_nome() {
    return this->nome;
}

void Cliente::set_idade(int idade) {
    this->idade = idade;
}

int Cliente::get_idade() {
    return this->idade;
}

void Cliente::set_cpf(string cpf) {
    this->cpf = cpf;
}

string Cliente::get_cpf() {
    return this->cpf;
}

void Cliente::set_email(string email) {
    this->email = email;
}

string Cliente::get_email() {
    return this->email;
}

void Cliente::set_socio(bool is_socio) {
    this->is_socio = is_socio;
}
bool Cliente::get_socio() {
    return this->is_socio;
}

void Cliente::set_total_de_compras(float valor) {
    this->total_de_compras = valor;
}
    
float Cliente::get_total_de_compras() {
    return this->total_de_compras;
}

Carrinho Cliente::get_carrinho() {
    return this->carrinho;
}

/*
    Método que imprime os dados do cliente.
*/
void Cliente::imprime_dados() {
    cout << fixed << setprecision(2);
    cout << "Nome do Cliente: " << get_nome() << endl;
    cout << "Idade: " << get_idade() << endl;
    cout << "Cpf: " << get_cpf() << endl;
    cout << "E-mail: " << get_email() << endl;
    cout << "Sócio: ";
    if(get_socio() == 1)
        cout << "Sim" << endl;
    else
        cout << "Não" << endl;
    cout << "Total de compras: R$" << get_total_de_compras() << endl;
    cout << "----------------------------------" << endl;
}

/*
    Método que cadastra o cliente no arquivo.
*/
void Cliente::cadastra_cliente() {
    ofstream saida;
    saida.open("./assets/Cadastro_clientes/"+get_cpf()+".txt", ios::trunc);

    if(saida.is_open()) {
        saida << get_nome() << endl;
        saida << get_idade() << endl;
        saida << get_cpf() << endl;
        saida << get_email() << endl;
        saida << get_socio() << endl;
        saida << get_total_de_compras() << endl;
        saida.close();
    }
    // saida.open("./assets/Categorias/"+get_cpf()+".txt", ios::trunc);
    saida.close();
}

/*
    Método que lê as informações do cliente do arquivo.
    Cria o cliente e o retorna.
*/
Cliente * Cliente::leArquivo(string arquivo) {
    ifstream entrada;
    Cliente * clientes = new Cliente;
    string texto;
    int i = 0, idade;
    float total_de_compras;

    entrada.open(arquivo, ios::in);
    if(entrada.is_open()) {
        getline(entrada, texto);
        clientes->set_nome(texto);
        i++;
        getline(entrada, texto);
        idade = stoi(texto);
        clientes->set_idade(idade);
        i++;
        getline(entrada, texto);
        clientes->set_cpf(texto);
        i++;
        getline(entrada, texto);
        clientes->set_email(texto);
        i++;
        getline(entrada, texto);
        if(texto == "1") 
            clientes->set_socio(true);
        else
            clientes->set_socio(false);
        i++;
        getline(entrada, texto);
        total_de_compras = stof(texto);
        clientes->set_total_de_compras(total_de_compras);
        
        entrada.close();
    }
    return clientes; 
}

/*
    Método que checa se o cliente já foi cadastrado.
*/
string Cliente::check_cpf(string cpf) {
    ifstream arquivo;
    string arq = "./assets/Cadastro_clientes/"+cpf+".txt";

    arquivo.open(arq, ios::in);

    if(arquivo.is_open())
        return arq; 

    arquivo.close();
    return "Cadastro não encontrado";
}

/*
    Método que coloca no carrinho do cliente o produto e sua quantidade.
*/
void Cliente::compra_do_cliente(string codigo, int quantidade) {
    carrinho.acrescenta_carrinho(codigo, quantidade);
}

/*
    Método que gera a nota fiscal da compra, e que também
    checa se tem algum produto na compra.
*/
bool Cliente::nota_fiscal() {
    float total_da_compra = carrinho.nota_fiscal_do_carrinho(0.0);
    set_total_de_compras(get_total_de_compras() + total_da_compra);
    if(total_da_compra > 0) {
        return true;
    }
    return false;
}

/*
    Método que finaliza a compra e checa se tem os produtos no estoque.  
*/
bool Cliente::finaliza_compra() {
    return carrinho.check_estoque();
}

/*
    Método que retorna os prosutos comprados para atualização 
    da recomendação do cleinte.
*/
vector<Produto *> Cliente::atualiza_recomendacao() {
    vector<Produto *> produtos;
    produtos = carrinho.get_produto();
    carrinho.~Carrinho();

    return produtos; 
}