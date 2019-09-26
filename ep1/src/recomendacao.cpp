#include <fstream>
#include "recomendacao.hpp"

using namespace std;

Recomendacao::Recomendacao() {}

Recomendacao::Recomendacao(Categoria * categoria) {
    categorias.push_back(categoria);
}

Recomendacao::~Recomendacao() {}

void Recomendacao::set_categoria(string nome) {
    categorias.push_back(new Categoria(nome));
}

void Recomendacao::set_categoria(string nome, vector<Produto *> produtos) {
    categorias.push_back(new Categoria(nome, produtos));
}

vector<Categoria *> Recomendacao::get_categoria() {
    return categorias;
}

void Recomendacao::set_cliente(Cliente * cliente) {
    this->cliente = cliente;
}

void Recomendacao::set_map(map<string, int> recomenda) {
    this->recomenda = recomenda;
}

map<string, int> Recomendacao::get_map() {
    return this->recomenda;
}


void Recomendacao::add_categoria_cliente(int check, string cpf) {
    map<string, int> recomenda;
    ifstream entrada, entrada2, entrada3;
    string texto, codigo, texto2, texto3;

    entrada.open("./doc/Categorias/Categoria.txt", ios::in);

    if(entrada.is_open()) {
        while(entrada.eof() != true) {
            getline(entrada, texto);

            if(texto != "") {
                recomenda[texto] = 0;

                if(check) {
                    entrada3.open("./doc/Categorias/Recomendacao_Clientes/"+cpf+".txt", ios::in);

                    if(entrada3.is_open()) {
                        while(entrada3.eof() != true) {
                            getline(entrada3, texto3);
                            if(texto3 == texto) {
                                getline(entrada3, texto3);
                                recomenda[texto] = stoi(texto3);
                            }
                        }
                    }
                    entrada3.close();
                }
            }

            for(Produto *produto: categorias[categorias.size()-1]->get_produto()) {
                codigo = produto->get_codigo();
                entrada2.open("./doc/Categorias/Categorias/"+texto+".txt", ios::in);

                if(entrada2.is_open()) {
                    while(entrada2.eof() != true) {
                        getline(entrada2, texto2);
                        if(texto2 == codigo) {
                            recomenda[texto] += 1;
                        }
                    }
                    entrada2.close();
                }
            }
        }
        entrada.close();
    }

    set_map(recomenda);
    set_recomendacao(cpf);
}

void Recomendacao::set_recomendacao(string cpf) {
    ofstream saida;

    saida.open("./doc/Categorias/Recomendacao_Clientes/"+cpf+".txt", ios::out);

    // for(auto x: get_map()) {
    //     cout << x.first << " -- " << x.second << endl;
    // }

    if(saida.is_open()) {
        for(auto recomenda2 = get_map().begin(); recomenda2 != get_map().end(); recomenda2++) {
            saida << recomenda2->first << endl;
            saida << recomenda2->second << endl;
        }
    }
    saida.close();
}