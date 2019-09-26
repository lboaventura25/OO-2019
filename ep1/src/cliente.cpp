#include <iostream>
#include <string>
#include <fstream>
#include "cliente.hpp"

using namespace std;

// Implementação
Cliente::Cliente() {}

Cliente::Cliente(string nome, int idade, string cpf, string email) {
    set_nome(nome);
    set_idade(idade);
    set_cpf(cpf);
    set_email(email);
    set_socio(false);
    set_total_de_compras(0);
    cadastra_cliente();
}

Cliente::~Cliente() {}

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

void Cliente::imprime_dados() {
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

void Cliente::imprime_clientes(vector<Cliente *> cliente) {
    cout << "--------Lista de CLientes---------" << endl;
    cout << "==================================" << endl;

    for(Cliente *cliente: cliente) {
        cliente->imprime_dados();
    }
}

void Cliente::cadastra_cliente() {
    ofstream saida;
    saida.open("./doc/Cadastro_clientes/"+get_cpf()+".txt", ios::trunc);

    if(saida.is_open()) {
        saida << get_nome() << endl;
        saida << get_idade() << endl;
        saida << get_cpf() << endl;
        saida << get_email() << endl;
        saida << get_socio() << endl;
        saida << get_total_de_compras() << endl;
        saida.close();
    }
    // saida.open("./doc/Categorias/"+get_cpf()+".txt", ios::trunc);
    saida.close();
}

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

string Cliente::check_cpf(string cpf) {
    ifstream arquivo;
    string arq = "./doc/Cadastro_clientes/"+cpf+".txt";

    arquivo.open(arq, ios::in);

    if(arquivo.is_open())
        return arq; 

    arquivo.close();
    return "Cadastro não encontrado";
}

void Cliente::compra_do_cliente(string codigo, int quantidade) {
    carrinho.acrescenta_carrinho(codigo, quantidade);
}

void  Cliente::nota_fiscal() {
    set_total_de_compras(get_total_de_compras() + carrinho.nota_fiscal_do_carrinho(0.0));
}

bool Cliente::finaliza_compra() {
    return carrinho.check_estoque();
}

vector<Produto *> Cliente::atualiza_recomendacao() {
    vector<Produto *> produtos;
    produtos = carrinho.get_produto();
    carrinho.~Carrinho();

    return produtos; 
}