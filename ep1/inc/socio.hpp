#ifndef SOCIO_HPP
#define SOCIO_HPP

#include <iostream>
#include <string>
#include <vector>
#include "cliente.hpp"
#include "carrinho.hpp"

using namespace std;

class Socio : public Cliente {

private:
    //Atributos
    float desconto;

public:
    Socio();//Contrutor
    Socio(Cliente *cliente);//Sobrecarga do Construtor
    ~Socio();//Destrutor

    //Métodos Acessores
    void set_desconto(float desconto);
    float get_desconto();

    //Outros Métodos
    void nota_fiscal();
    void imprime_dados();
};

#endif