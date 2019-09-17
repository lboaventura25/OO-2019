#ifndef CIRCULO_HPP
#define CIRCULO_HPP

#include <iostream>
#include "formageometrica.hpp"

using namespace std;

class Circulo : public FormaGeometrica {

    public:
        Circulo();
        Circulo(float raio);
        ~Circulo();

        float calcula_area();
        float calcula_perimetro();
        void imprime_forma();
};

#endif