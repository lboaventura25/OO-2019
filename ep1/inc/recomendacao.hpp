#ifndef RECOMENDACAO_HPP
#define RECOMENDACAO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "cliente.hpp"
#include "categoria.hpp"

using namespace std;

class Recomendacao : public Categoria {

private:
    //Atributos
    vector<Categoria *> categorias;
    Cliente * cliente;
    map<string, int> recomenda;

public:
    Recomendacao();// Construtor da classe
    Recomendacao(Categoria * categoria);
    ~Recomendacao();// Destrutor da classe

    // Métodos acessores
    void set_categoria(string nome);
    void set_categoria(string nome, vector<Produto *> produtos);
    vector<Categoria *> get_categoria();
    void set_cliente(Cliente * cliente);
    void set_map(map<string, int> recomenda);
    map<string, int> get_map();

    //Outros métodos
    void add_categoria_cliente(int check, string cpf);
    void set_recomendacao(string cpf);
};

#endif