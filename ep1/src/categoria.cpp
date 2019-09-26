#include <fstream>
#include "categoria.hpp"

using namespace std;

Categoria::Categoria() {}

Categoria::Categoria(string nome) {
    set_categoria(nome);
}

Categoria::Categoria(string nome, vector<Produto *> produtos) {
    set_categoria(nome);
    set_produtos(produtos);
}

Categoria::Categoria(vector<Produto *> produtos) {
    set_categoria("Genérico");
    set_produtos(produtos);
}

Categoria::~Categoria() {}

void Categoria::set_categoria(string nome) {
    this->nome = nome;
}

string Categoria::get_categoria() {
    return this->nome;
}

void Categoria::set_produto(string codigo) {
    Produto produto;
    string arq;

    arq = produto.check_produto(codigo);

    if(arq == "./doc/Cadastro_produtos/"+codigo+".txt") {
        set_produto(produto.leArquivo(arq));
        cout << "***** Produto " << produtos[produtos.size()-1]->get_nome() << " encontrado! *****" << endl;
    }
    else
        cout << "###### Produto não existe #####" << endl;
}

void Categoria::set_produto(Produto * produto) {
    produtos.push_back(produto);
}

void Categoria::set_produtos(vector<Produto *> produtos) {
    this->produtos = produtos;
}

vector<Produto *> Categoria::get_produto() {
    return produtos;
}

bool Categoria::cadastra_categoria(string categoria) {
    ofstream saida;

    if(leArquivo(categoria)) {
        saida.open("./doc/Categorias/Categoria.txt", ios::app);

        if(saida.is_open()) {
            saida << get_categoria() << endl;
            saida.close();
            cout << "***** Categoria " << categoria << " cadastrada com sucesso! *****" << endl;
        }
        return true;
    }
    else 
        cout << "###### Categoria já existente ######" << endl;

    return false;
}

void Categoria::cadastra_codigos() {
    ofstream saida;
    saida.open("./doc/Categorias/Categorias/"+get_categoria()+".txt", ios::trunc);

    if(saida.is_open()) {
        for(Produto * produto: produtos) {
            saida << produto->get_codigo() << endl;
        }
        saida.close();
    }
}

bool Categoria::leArquivo(string categoria) {
    ifstream entrada;
    string texto;

    entrada.open("./doc/Categorias/Categoria.txt", ios::in);

    if(entrada.is_open()) {
        while(entrada.eof() != true) {
            getline(entrada, texto);
            if(texto == categoria) {
                return false;
            }
        }
        entrada.close();
    }
    return true;
}