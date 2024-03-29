#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "produto.hpp"

using namespace std;

class Estoque {

    public:
        Estoque();//Construtor
        ~Estoque();//Destrutor

        //Métodos Acessores
        bool set_produto(string codigo, string nome, int quantidade, float preco);

        //Métodos 
        void atualiza_quantidade(string codigo, int quantidade);
        void cadastra_produto(Produto * produto);
        string produto_existe(string codigo);
        bool acrescenta_categoria_ao_produto(string codigo_produto, string categoria);
};

#endif