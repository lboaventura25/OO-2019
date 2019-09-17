#ifndef QUADRADO_HPP
#define QUADRADO_HPP

#include <iostream>
#include "formageometrica.hpp"

using namespace std;

class Quadrado : public FormaGeometrica {

    public:
        Quadrado();
        Quadrado(float lado);
        ~Quadrado();

        void imprime_forma();
};

#endif