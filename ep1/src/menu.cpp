#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include "menu.hpp"
#include "funcoes.hpp"

using namespace std;

Menu::Menu() {}  // Cosntrutor da Classe Menu.

Menu::~Menu() {} // Destrutor da classe Menu.

/*
    Método que imprime o menu principal na tela.
*/
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

/*
    Método que imprime o menu do Modo Venda.   
*/
void Menu::menu_modoVenda() {
    system("clear");
    int check;
    cout << "<-- Bem-vindo ao modo Venda! -->" << endl;
    cout << "--------------------------------" << endl;
    check = menu_cadastro();
    menu_compra(check);
}

/*
    Método que imprime o Menu e recebe o cpf para checar se o cliente já exite.
    Caso exista, o método cria o cliente para realizar a operação de compra e também
    imprime o Cliente na tela.  
*/
int Menu::menu_cadastro() {
    string arquivo, cpf;
    int check = 0;
    clientes.push_back(new Cliente());


    cout << "Digite o cpf do cliente: ";
    cpf = getString();
    cout << "--------------------------------" << endl;
    arquivo = clientes[clientes.size()-1]->check_cpf(cpf);
    if(cadastro_existe(arquivo, "./assets/Cadastro_clientes/"+cpf)) {
        clientes[clientes.size()-1] = clientes[clientes.size()-1]->leArquivo(arquivo);
        if(clientes[clientes.size()-1]->get_socio() or clientes[clientes.size()-1]->get_total_de_compras() >= 20) {
            clientes[clientes.size()-1] = new Socio(clientes[clientes.size()-1]->get_nome(), 
            clientes[clientes.size()-1]->get_idade(), clientes[clientes.size()-1]->get_cpf(), 
            clientes[clientes.size()-1]->get_email(), clientes[clientes.size()-1]->get_total_de_compras());
            clientes[clientes.size()-1]->imprime_dados();
        }
        else 
            clientes[clientes.size()-1]->imprime_dados();
        sleep(2);
        check = 1;
    }
    else {
        cadastra_cliente(cpf);
        check = 0;
    }
    return check;
}

/*
    Método que checa se o Cliente já é cadastrado. 
    E imprime na tela o resultado da checagem. 
*/
bool Menu::cadastro_existe(string arquivo, string test) {
    if(arquivo == test+".txt") {
        cout << "--> Cliente encontrado no sistema! <--" << endl;
        sleep(1);
        cout << "--------------------------------" << endl;
        return true;
    }
    cout << "###### Cadastro não encontrado ######" << endl;
    return false;
}

/*
    Método que imprime na tela o menu de cadastro do Cliente.
    E em seguida cria o Cliente.
*/
void Menu::cadastra_cliente(string cpf) {
    string nome, email;
    int idade;
    
    cout << ":: Por favor, Insira os dados do Cliente para Cadastro -->" << endl;
    cout << "----------------------------------" << endl;
    cout << "Nome: ";
    nome = getString();
    cout << "Idade: ";
    idade = getInt();
    cout << "Cpf: " << cpf << endl;
    cout << "Email: ";
    email = getString();
    set_cliente(nome, idade, cpf, email);
}

/*
    Método que coloca o cliente criado num vector de Clientes.  
*/
void Menu::set_cliente(string nome, int idade, string cpf, string email) {
    clientes.push_back(new Cliente(nome, idade, cpf, email));
    cout << "Cliente, " << nome << " cadastrado com sucesso!" << endl;
    sleep(1);
}

/*
    Método que imprime o menu de compra para inclusão de produtos no carrinho do cliente.
    E após o cliente terminar a compra checa se a compra foi concluída com sucesso.  
*/
void Menu::menu_compra(int check) {
    string codigo;
    string sair = "S";
    int quantidade;
    vector<Categoria *> cat;
    bool check2;

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
    check2 = clientes[clientes.size()-1]->nota_fiscal();

    if(clientes[clientes.size()-1]->finaliza_compra()) {
        cout << "************** COMPRA CONCLUÍDA COM SUCESSO **************" << endl;
        clientes[clientes.size()-1]->cadastra_cliente();
        cout << "Aperte ENTER para voltar ao menu incial...--> ";
        codigo = getString();
        if(check2) {
            vector<Produto *> produtos = clientes[clientes.size()-1]->atualiza_recomendacao();
            recomendacao = new Recomendacao(new Categoria(produtos));
            recomendacao->add_categoria_cliente(check, clientes[clientes.size()-1]->get_cpf());
            recomendacao->~Recomendacao();
        }
    }
    else {
        cout << "############## COMPRA CANCELADA POR FALTA DE PRODUTOS NO ESTOQUE OU POR FALTA DE PRODUTOS NO CARRINHO ##############" << endl;
        cout << "Aperte ENTER para voltar ao menu incial...--> " << endl;
        codigo = getString();
    }
    
    clientes[clientes.size()-1]->~Cliente();
}

/*
    Método que imprime o Menu do modo estoque e em seguida guia para 
    o Menu da opção desejada.
*/
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

/*
    Método que imprime a tela de cadastro do produto.
*/
void Menu::cadastra_produto() {
    string codigo, nome, preco, categoria;
    int quantidade, comando = -2;
    //cout << "\033[2J\033[1;1H";

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

    if (estoque->set_produto(codigo, nome, quantidade, price)) {
        while(comando != 0) {
            cout << "Digite a categoria ao qual o produto " << nome << " pertence [Caso ele ainda não pertença a nenhuma categoria pressione ENTER]: ";
            categoria = getString();
            
            if(estoque->acrescenta_categoria_ao_produto(codigo, categoria))
                cout << "***** Produto '" << nome << "' cadastrado na categoria '" << categoria << "' *****" << endl;
            else 
                cout << "###### Categoria inexistente ######" << endl;

            cout << "Deseja Acrescentar mais categorias ao produto ::::" << endl;
            cout << "(1) Sim" << endl;
            cout << "(0) Não" << endl;
            comando = getInt();
        }
    }

    estoque->~Estoque();
    cout << "Digite ENTER para volta ao Menu do Estoque -->";
    nome = getString();
}

/*
    Método que imprime a tela de atualização do Estoque.  
*/
void Menu::atualiza_estoque() {
    string codigo;
    int quantidade;
    //estoque = new Estoque();

    cout << "-------------------------------------------------------------" << endl;
    cout << "Insira o código produto que deseja atualizar a quantidade --> ";
    codigo = getString();
    cout << "Digite a nova quantidade do produto --> ";
    quantidade = getInt();

    estoque->atualiza_quantidade(codigo, quantidade); 
    estoque->~Estoque();
    cout << "Digite ENTER para volta ao Menu do Estoque -->";
    codigo = getString();
}

/*
    Método que imprime a tela de Cadastro de uma nova categoria.  
*/
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
            cout << "Digite o código dos produtos que fazem parte da categoria '" << categoria << "'[Caso nã possua produtos que pertencem a categoria digite ENTER]" << endl;
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

/*
    Método que imprime a tela do modo de Recomendação.
*/
void Menu::menu_modoRecomendacao() {
    string cpf, arquivo;
    clientes.push_back(new Cliente());

    system("clear");
    cout << "<-- Bem-vindo ao modo Recomendação! -->" << endl;
    cout << "---------------------------------------" << endl;

    cout << "Digite o cpf do cliente: ";
    cpf = getString();
    cout << "--------------------------------" << endl;
    ifstream entrada1;
    entrada1.open("./assets/Categorias/Recomendacao_Clientes/"+cpf+".txt", ios::in);
    arquivo = clientes[clientes.size()-1]->check_cpf(cpf);
    if(cadastro_existe(arquivo, "./assets/Cadastro_clientes/"+cpf)) {
        clientes[clientes.size()-1] = clientes[clientes.size()-1]->leArquivo(arquivo); 
        clientes[clientes.size()-1]->imprime_dados();
        sleep(2);
        if(entrada1.is_open()) {
            entrada1.close();
            recomendacao = new Recomendacao();
            recomendacao->leArquivo_recomendacao(clientes[clientes.size()-1]->get_cpf());
            recomendacao->sorted_recomendacao();
            recomendacao->~Recomendacao();
        }
        else
            cout << "***** Ainda não existe recomendações para este cliente, faça uma compra antes :) *****" << endl;
    }

    cout << "Digite ENTER para volta ao Menu Inicial --> ";
    cpf = getString();
}