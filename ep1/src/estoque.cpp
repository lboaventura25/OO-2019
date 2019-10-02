#include <fstream>
#include "estoque.hpp"

using namespace std;

Estoque::Estoque() {} // Construtor da classe Estoque.

Estoque::~Estoque() {} // Destrutor da classe Estoque.

/*
    Método que recebe as características do produto e cria ele, 
    caso não exista.
*/
bool Estoque::set_produto(string codigo, string nome, int quantidade, float preco) {
    string arq;
    Produto *produtos = new Produto(codigo, nome, quantidade, preco);

    arq = produto_existe(codigo);

    if(arq == "./assets/Cadastro_produtos/"+codigo+".txt")
        cout << "###### Código do Produto já existe no Estoque ######" << endl;
    else {
        cadastra_produto(produtos);
        cout << "**** Produto " << nome << " cadastrado com sucesso! ****" << endl;
        return true;
    }
    return false;
}

/*
    Método que atualiza a quantidade do Produto no estoque caso ele exista.
*/
void Estoque::atualiza_quantidade(string codigo, int quantidade) {
    ofstream entrada;
    string arq;
    Produto *produto = new Produto();

    arq = produto_existe(codigo);

    if(arq == "./assets/Cadastro_produtos/"+codigo+".txt") {
        produto = produto->leArquivo(arq);
        produto->set_quantidade(quantidade);
        cadastra_produto(produto);
        cout << "**** Produto " << produto->get_nome() << " atualizado com sucesso! ****" << endl;
    }
    else
        cout << "###### Produto não existe ######" << endl;
}

/*
    Método que cadastra o produto no arquivo.
*/
void Estoque::cadastra_produto(Produto * produto) {
    produto->cadastro_produto();
}

/*
    Método que checa se o produto já existe.
    Caso exista, retorna o caminho do seu arquivo.
*/
string Estoque::produto_existe(string codigo) {
    Produto produto;
    string arq;

    arq = produto.check_produto(codigo);

    if(arq == "./assets/Cadastro_produtos/"+codigo+".txt") {
        return arq;
    }

    else {
        return "BLABLA";
    }
}

/*
    Método que acrescenta categoria ao produto e grava no arquivo.
*/
bool Estoque::acrescenta_categoria_ao_produto(string codigo_produto, string categoria) {
    ifstream entrada;
    ofstream saida;
    string texto;
    bool check = false;

    entrada.open("./assets/Categorias/Categoria.txt", ios::in);

    if(entrada.is_open()) {
        while(entrada.eof() != true) {
            getline(entrada, texto);
            if(texto == categoria) {
                check = true;
                break;
            }
        }
        entrada.close();
    }

    if(check) {
        saida.open("./assets/Categorias/Categorias/"+ categoria +".txt", ios::app);
        if(saida.is_open()) {
            saida << codigo_produto << endl;
        }
        saida.close();
        return true;
    }
    return false;
}