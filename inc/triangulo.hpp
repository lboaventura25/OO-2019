#ifndef TRIANGULO_HPP
#define TRIANGULO_HPP

#include <iostream>
#include "formageometrica.hpp"

using namespace std;

class Triangulo : public FormaGeometrica{
    
    public:
        Triangulo();
        Triangulo(float base, float altura);
        ~Triangulo();

        float calcula_area();
        float calcula_perimetro();
        void imprime_forma();
};

#endif