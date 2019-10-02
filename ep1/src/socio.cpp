#include <iostream>
#include <fstream>
#include "socio.hpp"
#include <string>

using namespace std;

Socio::Socio() {} // Construtor da classe Socio.

/*
    Sobrecarga do construtor da classe Socio.
*/
Socio::Socio(string nome, int idade, string cpf, string email, float total_de_compras){
    set_nome(nome);
    set_idade(idade);
    set_cpf(cpf);
    set_email(email);
    set_socio(true);
    set_total_de_compras(total_de_compras);

    if(get_total_de_compras() >= 20)
        set_desconto(0.15);
}

Socio::~Socio() {} // Destrutor da classe Socio.

/*
    Métodos acessores da classe Socio.
*/
void Socio::set_desconto(float desconto) {
    this->desconto = desconto;
}

float Socio::get_desconto() {
    return this->desconto;
}

/*
    Método Sobrescrito da classe Cliente que gera a nota fiscal da compra com o desconto do Socio, 
    e que também checa se tem algum produto na compra.
*/
bool Socio::nota_fiscal() {
    float total_da_compra = get_carrinho().nota_fiscal_do_carrinho(get_desconto());
    set_total_de_compras(get_total_de_compras() + total_da_compra);
    if(total_da_compra > 0) {
        return true;
    }
    return false;
}

/*
    Método responsável por imprimir o Cliente que é Sócio 
    com o respectivo desconto no Perfil.  
*/
void Socio::imprime_dados() {
        cout << "Nome do Cliente: " << get_nome() << endl;
        cout << "Idade: " << get_idade() << endl;
        cout << "Cpf: " << get_cpf() << endl;
        cout << "E-mail: " << get_email() << endl;
        cout << "Sócio: " << "Sim" << endl;;
        cout << "Porcentagem de desconto: " << get_desconto()*100 << "%" << endl;
        cout << "Total de compras: R$" << get_total_de_compras() << endl;
        cout << "----------------------------------" << endl;
}