#ifndef TRIANGULOISOSCELES_HPP
#define TRIANGULOISOSCELES_HPP

#include <iostream>
#include "triangulo.hpp"

using namespace std;

class TrianguloIsosceles : public Triangulo {
    
    public:
        TrianguloIsosceles();
        TrianguloIsosceles(float base, float altura);
        ~TrianguloIsosceles();

        float calcula_perimetro();
        void imprime_forma();
};

#endif