#include <iostream>
#include <fstream>
#include "socio.hpp"
#include <string>

using namespace std;

Socio::Socio() {}

Socio::Socio(Cliente * cliente){
    set_nome(cliente->get_nome());
    set_idade(cliente->get_idade());
    set_cpf(cliente->get_cpf());
    set_email(cliente->get_email());
    set_socio(true);
    set_total_de_compras(cliente->get_total_de_compras());

    if(get_total_de_compras() >= 20)
        set_desconto(0.15);
}

Socio::~Socio() {}

void Socio::set_desconto(float desconto) {
    this->desconto = desconto;
}

float Socio::get_desconto() {
    return this->desconto;
}

void Socio::nota_fiscal() {
    set_total_de_compras(get_total_de_compras() + (get_carrinho().nota_fiscal_do_carrinho(get_desconto())));
}

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