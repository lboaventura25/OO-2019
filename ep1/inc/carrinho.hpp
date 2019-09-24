#ifndef CARRINHO_HPP
#define CARRINHO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "produto.hpp"

using namespace std;

class Carrinho {

private:
    // Atributos
    vector<Produto *> produtos;
    vector<int> quantidades; 

public:
    // Métodos
    Carrinho();// Construtor da classe Produto
    ~Carrinho();// Destrutor da classe Produto

    // Métodos Acessores
    void set_produto(Produto * produto);
    Produto * get_produto(int posicao);
    void set_quantidades(int quantidade);
    vector<int> get_quantidades();

    // Outros Métodos
    void acrescenta_carrinho(string codigo, int quantidade);
    float nota_fiscal_do_carrinho(float porcentagem_desconto);
    bool check_estoque();
};

#endif