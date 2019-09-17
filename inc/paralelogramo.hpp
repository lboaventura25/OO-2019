#ifndef PARALELOGRAMO_HPP
#define PARALELOGRAMO_HPP

#include <iostream>
#include "formageometrica.hpp"

using namespace std;

class Paralelogramo : public FormaGeometrica {

    public:
        Paralelogramo();
        Paralelogramo(float base, float altura);
        ~Paralelogramo();

        void imprime_forma();
};

#endif