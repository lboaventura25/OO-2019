#include <fstream>
#include "recomendacao.hpp"

using namespace std;

Recomendacao::Recomendacao() {} // Construtor da classe Recomendaçao.

/*
    Sobrecarga do construtor da classe Recomendacao.  
*/
Recomendacao::Recomendacao(Categoria * categoria) {
    categorias.push_back(categoria);
}

/*
    Destrutor da classe Recomendacao.
*/
Recomendacao::~Recomendacao() {
    for(unsigned int i = 0; i < categorias.size()-1; i++) {
        categorias.erase(categorias.begin() + i);
    }
    get_map().clear();
}

/*
    Métodos Acessores da classe Recomendacao.  
*/
void Recomendacao::set_categoria() {
    categorias.push_back(new Categoria());
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

/*
    Método que acessa o arquivo de Recomendacao do cliente e carrega as informações dele,
    em seguida identifica as categorias dos produtos comprados pelo cliente. 
*/
void Recomendacao::add_categoria_cliente(int check, string cpf) {
    map<string, int> recomenda;
    ifstream entrada, entrada2, entrada3;
    string texto, codigo, texto2, texto3;

    entrada.open("./assets/Categorias/Categoria.txt", ios::in);

    if(entrada.is_open()) {
        while(entrada.eof() != true) {
            getline(entrada, texto);

            if(texto != "") {
                recomenda[texto] = 0;

                if(check) {
                    entrada3.open("./assets/Categorias/Recomendacao_Clientes/"+cpf+".txt", ios::in);

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
                entrada2.open("./assets/Categorias/Categorias/"+texto+".txt", ios::in);

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

/*
    Método que reescreve no arquivo de Recomendação do Cliente após a compra ser finalizada.  
*/
void Recomendacao::set_recomendacao(string cpf) {
    ofstream saida;

    saida.open("./assets/Categorias/Recomendacao_Clientes/"+cpf+".txt", ios::trunc);

    // for(auto x: get_map()) {
    //     cout << x.first << " -- " << x.second << endl;
    // }

    if(saida.is_open()) {
        for(auto recomenda2: get_map()) {
            saida << recomenda2.first << endl;
            saida << recomenda2.second << endl;
        }
    }
    saida.close();
}

/*
    Método que lê o arquivo de recomendação para recomendar produtos para o cliente.
*/
void Recomendacao::leArquivo_recomendacao(string cpf) {
    ifstream entrada;
    map<string, int> recomenda;
    string categoria, valor;

    entrada.open("./assets/Categorias/Recomendacao_Clientes/"+ cpf + ".txt", ios::in);

    if(entrada.is_open()) {
        while(entrada.eof() != true) {
            getline(entrada, categoria);
            if(categoria != "") {
                recomenda[categoria];
                getline(entrada, valor);
                recomenda[categoria] = stoi(valor);
            }
        }
        entrada.close();
    }

    set_map(recomenda);
}

/*
    Método que realiza a ordenção das categorias para uma recomendação mais eficaz.
    E imprime a ordem de recomendação das categorias.
*/
void Recomendacao::sorted_recomendacao() {
    vector<pair<int, string>> ordem_recomenda;
    vector<pair<int, string>>::iterator itpair;
    map<string, int>::iterator it;
    int limite = 0;
    unsigned int j = 0;

    for(it = get_map().begin(); j <= get_map().size()-1; it++, j++) {
        ordem_recomenda.push_back(make_pair(it->second, it->first));
    }
    j = 0;

    sort(ordem_recomenda.begin(), ordem_recomenda.end(), maior_menor_lexicografica);

    for(itpair = ordem_recomenda.begin(); j < ordem_recomenda.size(); itpair++, j++) {
        set_categoria();
        get_categoria()[get_categoria().size()-1]->set_categoria(itpair->second);
    }
    
    for(unsigned int i = 0; i <= categorias.size()-1; i++) {
        cout << endl << endl;
        if(limite < 10) {
            cout << i+1 <<"ª. Categoria mais recomendada: " << categorias[i]->get_categoria() << endl;
            cout << "------------------------------------" << endl;
        }
        limite = categorias[i]->leArquivo(categorias[i]->get_categoria(), limite);
    }
    for(unsigned int i = 0; i < ordem_recomenda.size()-1; i++) {
        ordem_recomenda.erase(ordem_recomenda.begin() + i);
    }
}