#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto {

    private:
        // Atributos
        string codigo;
        string nome;
        int quantidade;
        float preco;

    public:
        // Métodos
        Produto(); // Construtor da classe Produto
        Produto(string codigo, string nome, int quantidade, float preco);
        ~Produto(); // Destrutor da classe Produto

        // Métodos Acessores
        void set_codigo(string codigo);
        string get_codigo();
        void set_nome(string nome);
        string get_nome();
        void set_quantidade(int quantidade);
        int get_quantidade();
        void set_preco(float preco);
        float get_preco();

        // Outros Métodos
        void imprime_dados();
        void cadastro_produto();
        string check_produto(string codigo);
        Produto * leArquivo(string arquivo);
        bool check_estoque(int quantidade);
};

#endif