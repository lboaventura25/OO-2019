#ifndef SOCIO_HPP
#define SOCIO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "cliente.hpp"
#include "carrinho.hpp"

using namespace std;

/*
    Classe Sócio que é filha da classe Cliente.
*/

class Socio : public Cliente {

private:
    //Atributos
    float desconto;

public:
    Socio();//Contrutor
    Socio(string nome, int idade, string cpf, string email, float total_de_compras);//Sobrecarga do Construtor
    ~Socio();//Destrutor

    //Métodos Acessores
    void set_desconto(float desconto);
    float get_desconto();

    //Outros Métodos
    bool nota_fiscal();
    void imprime_dados();
};

#endif