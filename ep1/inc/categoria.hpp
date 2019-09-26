#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <map>
#include "produto.hpp"

using namespace std;

class Categoria {

private:
    string nome;
    vector<Produto *> produtos;

public:
    Categoria();//Construtor
    Categoria(string nome);
    Categoria(string nome, vector<Produto *> produtos);
    Categoria(vector<Produto *> produtos);
    ~Categoria();//Destrutor

    //Métodos Acessores
    void set_categoria(string nome);
    string get_categoria();
    void set_produto(string codigo);
    void set_produtos(vector<Produto *> produtos);
    void set_produto(Produto * produto);
    vector<Produto *> get_produto();

    //Outros Métodos
    bool cadastra_categoria(string categoria);
    void cadastra_codigos();
    bool leArquivo(string categoria);
};

#endif