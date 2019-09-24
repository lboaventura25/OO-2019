#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "produto.hpp"

using namespace std;

class Categoria {

private:
    string nome;
    vector<Produto *> produtos;

public:
    Categoria();//Construtor
    Categoria(string nome);
    ~Categoria();//Destrutor

    //Métodos Acessores
    void set_categoria(string get_nome);
    string get_categoria();
    void set_produto(string codigo);
    void set_produto(Produto *produto);

    //Outros Métodos
    bool cadastra_categoria(string categoria);
    void cadastra_codigos();
    bool leArquivo(string categoria);
};

#endif