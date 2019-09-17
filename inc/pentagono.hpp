#ifndef PENTAGONO_HPP
#define PENTAGONO_HPP

#include <iostream>
#include "trianguloEquilatero.hpp"

using namespace std;

class Pentagono : public TrianguloEquilatero {
    public:
        Pentagono();
        Pentagono(float lado);
        ~Pentagono();

        float calcula_area();
        float calcula_perimetro();
        void imprime_forma();
};

#endif