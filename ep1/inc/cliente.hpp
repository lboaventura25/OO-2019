#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "produto.hpp"
#include "carrinho.hpp"

using namespace std;

class Cliente {

private:
    // Atributos
    string nome;
    int idade;
    string cpf;
    string email;
    bool is_socio;
    float total_de_compras;
    Carrinho carrinho;

public:
    //Métodos
    Cliente(); // Construtor da classe Cliente
    Cliente(string nome, int idade, string cpf, string email);
    ~Cliente(); // Destrutor da classe Cliente

    // Métodos Acessores
    void set_nome(string nome);
    string get_nome();
    void set_idade(int idade);
    int get_idade();
    void set_cpf(string cpf);
    string get_cpf();
    void set_email(string email);
    string get_email();
    void set_socio(bool is_socio);
    bool get_socio();
    void set_total_de_compras(float valor);
    float get_total_de_compras();
    Carrinho get_carrinho();

    // Outros métodos
    virtual void imprime_dados();
    void imprime_clientes(vector<Cliente *> cliente);
    void cadastra_cliente();
    Cliente * leArquivo(string arquivo);
    string check_cpf(string cpf);
    string check_socio();
    void compra_do_cliente(string codigo, int quantidade);
    bool finaliza_compra();
    virtual void nota_fiscal();
    void kill_carrinho();
};

#endif