#ifndef TRIANGULOEQUILATERO_HPP
#define TRIANGULOEQUILATERO_HPP

#include <iostream>
#include "triangulo.hpp"

using namespace std;

class TrianguloEquilatero : public Triangulo {
    private:
        float lado;

    public:
        TrianguloEquilatero();
        TrianguloEquilatero(float lado);
        ~TrianguloEquilatero();
        void set_lado(float lado);
        float get_lado();

        float calcula_area();
        float calcula_perimetro();
        void imprime_forma();
};

#endif