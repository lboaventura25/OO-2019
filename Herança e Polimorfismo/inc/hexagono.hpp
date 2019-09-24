#ifndef HEXAGONO_HPP
#define HEXAGONO_HPP

#include <iostream>
#include "trianguloEquilatero.hpp"

using namespace std;

class Hexagono : public TrianguloEquilatero {
    public:
        Hexagono();
        Hexagono(float lado);
        ~Hexagono();

        float get_area();
        float calcula_perimetro();
        void imprime_forma();
};

#endif