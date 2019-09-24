#include <fstream>
#include "estoque.hpp"

using namespace std;

Estoque::Estoque() {}

Estoque::~Estoque() {}

void Estoque::set_produto(string codigo, string nome, int quantidade, float preco) {
    string arq;
    Produto *produtos = new Produto(codigo, nome, quantidade, preco);

    arq = produto_existe(codigo);

    if(arq == "./doc/Cadastro_produtos/"+codigo+".txt")
        cout << "###### Código do Produto já existe no Estoque ######" << endl;
    else {
        cadastra_produto(produtos);
        cout << "**** Produto " << nome << " cadastrado com sucesso! ****" << endl;
    }
}

void Estoque::atualiza_quantidade(string codigo, int quantidade) {
    ofstream entrada;
    string arq;
    Produto *produto = new Produto();

    arq = produto_existe(codigo);

    if(arq == "./doc/Cadastro_produtos/"+codigo+".txt") {
        produto = produto->leArquivo(arq);
        produto->set_quantidade(quantidade);
        cadastra_produto(produto);
        cout << "**** Produto " << produto->get_nome() << " atualizado com sucesso! ****" << endl;
    }
    else
        cout << "###### Produto não existe ######" << endl;
}

void Estoque::cadastra_produto(Produto * produto) {
    produto->cadastro_produto();
}

string Estoque::produto_existe(string codigo) {
    Produto produto;
    string arq;

    arq = produto.check_produto(codigo);

    if(arq == "./doc/Cadastro_produtos/"+codigo+".txt") {
        return arq;
    }

    else {
        return "BLABLA";
    }
}