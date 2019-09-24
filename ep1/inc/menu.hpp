#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include "cliente.hpp"
#include "produto.hpp"
#include "socio.hpp"
#include "estoque.hpp"
#include "categoria.hpp"

using namespace std;

class Menu {

    private:
        vector<Cliente *> clientes;
        Estoque *estoque;
        Categoria *categorias;

    public:
        // Métodos
        Menu(); // Construtor da Classe
        ~Menu(); // Destrutor da Classe
        
        // Outros Métodos
        void menu_inicio();

        void menu_modoVenda();
        void menu_cadastro();
        void menu_cadastro_produtos();
        void menu_compra();
        void menu_modoEstoque();
        void set_cliente(string nome, int idade, string cpf, string email);
        bool cadastro_existe(string arquivo, string test);
        void cadastra_cliente();
        void cadastra_produto();
        void atualiza_estoque();
        void cadastra_categoria();
};

#endif