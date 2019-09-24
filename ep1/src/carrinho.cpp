#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "carrinho.hpp"

using namespace std;

Carrinho::Carrinho() {}

Carrinho::~Carrinho() {}

void Carrinho::set_produto(Produto *produto) {
    this->produtos.push_back(produto);
}

Produto * Carrinho::get_produto(int posicao) {
    return this->produtos[posicao];
}

void Carrinho::set_quantidades(int quantidade) {
    this->quantidades.push_back(quantidade);
}

vector<int> Carrinho::get_quantidades() {
    return this->quantidades;
}

void Carrinho::acrescenta_carrinho(string codigo, int quantidade) {
    string arquivo;

    Produto produto;
    arquivo = produto.check_produto(codigo);
    if(arquivo != "./doc/Cadastro_produtos/"+codigo+".txt") {
        cout << "*** Produto não cadastrado! ***" << endl;
    }
    else {
        set_produto(produto.leArquivo(arquivo));
        cout << "*** Produto " << produtos[produtos.size()-1]->get_nome() << " incluído no carrinho ***" << endl;
        set_quantidades(quantidade);
    }
}

float Carrinho::nota_fiscal_do_carrinho(float porcentagem_desconto) {
    int i = 0;
    float valor = 0;

    system("clear");
    cout << "--------------------------------------------------------" << endl;
    cout << "********************** NOTA FISCAL *********************" << endl << endl;
    cout << "|      Nome       |  Quant.  |  Preço  |  Preço*Quant  |" << endl;
    cout << "--------------------------------------------------------" << endl;

    for(Produto *produto: produtos) {
        cout << produto->get_nome();
        if(produto->get_nome().length() < 19) {
            for(int j = produto->get_nome().length(); j <= 19; j++) {
                cout << " ";
            }
        }
        cout << "\t" << quantidades[i] << "\t ";
        cout << produto->get_preco() << "\t       " << produto->get_preco()*quantidades[i] << endl;
        valor += (produto->get_preco() * quantidades[i]);
        i++;
    }

    cout << "--------------------------------------------------------" << endl;
    cout << endl << "--> Valor total da compra: R$" << valor << endl;
    cout << "--> Valor do desconto oferecido: R$" << porcentagem_desconto * valor << endl; 
    cout << "--> Valor final ----> R$" << (1 - porcentagem_desconto) * valor << endl;
    cout << "--------------------------------------------------------" << endl;

    return (1 - porcentagem_desconto) * valor;
}

bool Carrinho::check_estoque() {
    int i = 0, j = 0;
    vector<bool> okay;

    for(Produto *produto: produtos) {
        if(produto->check_estoque(quantidades[i])) {
            okay.push_back(true);
        }
        else {
            produtos.erase(produtos.begin() + j);
            okay.push_back(false);
        }
        j++;
    }

    for(bool x: okay) {
        if(x == false)
            return false;
    }

    for(Produto *produto: produtos) {
        produto->cadastro_produto();
    }    

    return true;
}