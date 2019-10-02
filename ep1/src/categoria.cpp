#include <fstream>
#include "categoria.hpp"

using namespace std;

Categoria::Categoria() {} // Construtor da classe Categoria.

/*
    Sobrecargas do construtor da classe Categoria.  
*/
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

Categoria::~Categoria() {} // Destrutor da classe Categoria.

/*
    Métodos acessores da classe Categoria.  
*/
void Categoria::set_categoria(string nome) {
    this->nome = nome;
}

string Categoria::get_categoria() {
    return this->nome;
}

/*
    Método que acrescenta um produto pelo código.  
*/
void Categoria::set_produto(string codigo) {
    Produto produto;
    string arq;

    arq = produto.check_produto(codigo);

    if(arq == "./assets/Cadastro_produtos/"+codigo+".txt") {
        set_produto(produto.leArquivo(arq));
        cout << "***** Produto " << produtos[produtos.size()-1]->get_nome() << " encontrado! *****" << endl;
    }
    else
        cout << "###### Produto não existe #####" << endl;
}

/*
    Sobrecarga que acrescenta o Produto já criado.  
*/
void Categoria::set_produto(Produto * produto) {
    produtos.push_back(produto);
}

/*
    Sobrecarga que acrescenta vários peodutos de uma vez.  
*/
void Categoria::set_produtos(vector<Produto *> produtos) {
    this->produtos = produtos;
}

vector<Produto *> Categoria::get_produto() {
    return produtos;
}

/*
    Método que caso a categoria não exista, cadastra ela no arquivo de Categorias.
    
*/
bool Categoria::cadastra_categoria(string categoria) {
    ofstream saida;

    if(check_categoria(categoria)) {
        saida.open("./assets/Categorias/Categoria.txt", ios::app);

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

/*
    Método que cadastra novos códigos de produtos no arquivo da categoria específica.  
*/
void Categoria::cadastra_codigos() {
    ofstream saida;
    saida.open("./assets/Categorias/Categorias/"+get_categoria()+".txt", ios::trunc);

    if(saida.is_open()) {
        for(Produto * produto: produtos) {
            saida << produto->get_codigo() << endl;
        }
        saida.close();
    }
}

/*
    Método que checa se o nome da categoria já está cadastrada.  
*/
bool Categoria::check_categoria(string categoria) {
    ifstream entrada;
    string texto;

    entrada.open("./assets/Categorias/Categoria.txt", ios::in);

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

/*
    Método que lê do arquivo da categoria os produtos que fazem parte dela, 
    e em seguida imprime uma lista de 10 produtos.
*/
int Categoria::leArquivo(string categoria, int limite) {
    ifstream entrada;
    Produto * prod;
    string texto;

    if(!check_categoria(categoria)) {
        entrada.open("./assets/Categorias/Categorias/"+categoria+".txt", ios::in);

        if(entrada.is_open()) {
            while(entrada.eof() != true) {
                prod = new Produto();
                getline(entrada, texto);
                if(texto != "") {
                    prod->set_codigo(texto);
                    prod = prod->leArquivo(prod->check_produto(prod->get_codigo()));
                    set_produto(prod);
                }
            }
            for(Produto *prod: produtos) {
                if(limite < 10) {
                    cout << "\t     ";
                    cout << limite + 1 << "º Produto" << endl;
                    prod->imprime_dados();
                    limite++;
                }
                else
                    break;
            }
        }
        entrada.close();
    }
    return limite;
}