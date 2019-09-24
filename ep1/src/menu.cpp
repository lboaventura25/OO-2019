#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "menu.hpp"
#include "funcoes.hpp"

using namespace std;

Menu::Menu() {}

Menu::~Menu() {}

void Menu::menu_inicio() {
    system("clear");
    cout << "----------- Menu Principal ------------" << endl;
    cout << "*          (1) Modo Venda             *" << endl;
    cout << "*          (2) Modo Estoque           *" << endl;
    cout << "*          (3) Modo Recomendação      *" << endl;
    cout << "*          (0) Fechar o Programa      *" << endl;
    cout << "---------------------------------------" << endl;
    cout << ":: Digite o modo desejado --> ";
}

void Menu::menu_modoVenda() {
    system("clear");
    cout << "<-- Bem-vindo ao modo Venda! -->" << endl;
    cout << "--------------------------------" << endl;
    menu_cadastro();
    menu_compra();
}

void Menu::menu_cadastro() {
    string arquivo, cpf;
    clientes.push_back(new Cliente());


    cout << "Digite o cpf do cliente: ";
    cpf = getString();
    cout << "--------------------------------" << endl;
    arquivo = clientes[clientes.size()-1]->check_cpf(cpf);
    if(cadastro_existe(arquivo, "./doc/Cadastro_clientes/"+cpf)) {
        clientes[clientes.size()-1] = clientes[clientes.size()-1]->leArquivo(arquivo);
        if(clientes[clientes.size()-1]->get_socio() || clientes[clientes.size()-1]->get_total_de_compras() >= 20) {
            clientes.push_back(new Socio(clientes[clientes.size()-1]));
            clientes[clientes.size()-1]->imprime_dados();
        }
        else 
            clientes[clientes.size()-1]->imprime_dados();
        sleep(2);
    }
    else {
        cadastra_cliente();
    }

}

bool Menu::cadastro_existe(string arquivo, string test) {
    if(arquivo == test+".txt") {
        cout << "--> Cliente encontrado no sistema! <--" << endl;
        sleep(1);
        cout << "--------------------------------" << endl;
        return true;
    }
    cout << "Cadastro não encontrado" << endl;
    return false;
}

void Menu::cadastra_cliente() {
    string nome, cpf, email;
    int idade;
    
    cout << ":: Por favor, Insira os dados do Cliente para Cadastro -->" << endl;
    cout << "----------------------------------" << endl;
    cout << "Nome: ";
    nome = getString();
    cout << "Idade: ";
    idade = getInt();
    cout << "Cpf: ";
    cpf = getString();
    cout << "Email: ";
    email = getString();
    set_cliente(nome, idade, cpf, email);
}

void Menu::set_cliente(string nome, int idade, string cpf, string email) {
    clientes.push_back(new Cliente(nome, idade, cpf, email));
    cout << "Cliente, " << nome << " cadastrado com sucesso!" << endl;
    sleep(1);
}

void Menu::menu_compra() {
    string codigo;
    string sair = "S";
    int quantidade;

    cout << " <------------ Modo Compra ------------>" << endl;
    while(sair == "S") {
        cout << "Digite o codigo do produto do cliente: " << endl;
        codigo = getString();
        cout << "Digite a quantidade do produto " << codigo << " : ";
        quantidade = getInt();
        clientes[clientes.size()-1]->compra_do_cliente(codigo, quantidade);

        cout << "Acrescentar mais produtos ao carrinho do cliente: [S/n]" << endl;
        cout << "--> ";
        sair = getString();
        cout << "---------------------------------------" << endl << endl;
    }
    clientes[clientes.size()-1]->nota_fiscal();

    if(clientes[clientes.size()-1]->finaliza_compra()) {
        cout << "************** COMPRA CONCLUÍDA COM SUCESSO **************" << endl;
        clientes[clientes.size()-1]->cadastra_cliente();
        cout << "Aperte ENTER para voltar ao menu incial...--> " << endl;
        codigo = getString();
    }
    else {
        cout << "############## COMPRA CANCELADA POR FALTA DE PRODUTOS NO ESTOQUE ##############" << endl;
        cout << "Aperte ENTER para voltar ao menu incial...--> " << endl;
        codigo = getString();
    }
    clientes[clientes.size()-1]->kill_carrinho();
}

void Menu::menu_modoEstoque() {
    int opcao;

    while(opcao != 0) {
        system("clear");
        cout << "<-- Bem-vindo ao modo Estoque! -->" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Cadastrar um novo produto   " << endl;
        cout << "(2) Atualizar Estoque           " << endl;
        cout << "(3) Cadastrar uma nova categoria" << endl;  
        cout << "(0) Voltar para Menu inicial    " << endl;  
        cout << "--------------------------------" << endl << endl;
        cout << "--> Digite a opção desejada: ";
        opcao = getInt();

        switch(opcao) {
            case 1:
                cadastra_produto();
                break;
            
            case 2:
                atualiza_estoque();
                break;

            case 3:
                cadastra_categoria();
                break;
            
            case 0:
                break;

            default:
                cout << "Opção inválida!" << endl;
                sleep(1);
                break;
        }
    }
}

void Menu::cadastra_produto() {
    string codigo, nome, preco;
    int quantidade;

    cout << "-------------------------------------" << endl;
    cout << "Insira os dados do novo produto -->" << endl;
    cout << "Código: ";
    codigo = getString();
    cout << "Nome: ";
    nome = getString();
    cout << "Quantidade: ";
    quantidade = getInt();
    cout << "Preço: ";
    preco = getString();
    float price = stof(preco);

    estoque->set_produto(codigo, nome, quantidade, price);
    cout << "Digite ENTER para volta ao Menu do Estoque -->";
    nome = getString();
}

void Menu::atualiza_estoque() {
    string codigo;
    int quantidade;
    //estoque = new Estoque();

    cout << "-------------------------------------------------------------" << endl;
    cout << "Insira o código produto que deseja atualizar a quantidade -->";
    codigo = getString();
    cout << "Digite a nova quantidade do produto --> ";
    quantidade = getInt();

    estoque->atualiza_quantidade(codigo, quantidade); 
    cout << "Digite ENTER para volta ao Menu do Estoque -->";
    codigo = getString();
}

void Menu::cadastra_categoria() {
    string categoria;
    string codigo;
    categorias = new Categoria();
    int opcao = -1;

    cout << "-------------------------------------" << endl;
    cout << "Insira a nova categoria --> ";
    categoria = getString();
    categorias = new Categoria(categoria);
    if(categorias->cadastra_categoria(categoria)) {

        while(opcao != 0) {
            cout << "Digite o código dos produtos que fazem parte da categoria '" << categoria << "'" << endl;
            cout << "--> ";
            codigo = getString();
            categorias->set_produto(codigo);

            cout << "Deseja Acrescentar mais codigos de produtos ::::" << endl;
            cout << "(1) Sim" << endl;
            cout << "(0) Não" << endl;
            opcao = getInt();
        }

        categorias->cadastra_codigos();
        categorias->~Categoria();
    }
    cout << "Digite ENTER para continuar --> ";
    categoria = getString();
}