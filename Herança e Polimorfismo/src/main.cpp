#include <iostream>
#include <vector>
#include "formageometrica.hpp"
#include "triangulo.hpp"
#include "quadrado.hpp"
#include "circulo.hpp"
#include "trianguloEquilatero.hpp"
#include "paralelogramo.hpp"
#include "trianguloIsosceles.hpp"
#include "pentagono.hpp"
#include "hexagono.hpp"

using namespace std;

int main(int argc, char **argv) {

    vector<FormaGeometrica *> formas;

    formas.push_back(new Triangulo(4, 2));
    formas.push_back(new Quadrado(5));
    formas.push_back(new Circulo(6));
    formas.push_back(new Paralelogramo(6, 8));
    formas.push_back(new TrianguloEquilatero(5));
    formas.push_back(new TrianguloIsosceles(5, 4));
    formas.push_back(new Pentagono(7));
    formas.push_back(new Hexagono(5));

    cout << "---------- Lista de formas -----------" << endl;

    for(FormaGeometrica *f: formas) {
        f->imprime_forma();
        cout << "--------------------------" << endl;
    }
    cout << "--------------------------------------" << endl;

    return 0;
}