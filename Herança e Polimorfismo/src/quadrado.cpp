#include "quadrado.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Quadrado::Quadrado() {}

Quadrado::Quadrado(float lado) {
    set_tipo("Quadrado");
    set_base(lado);
    set_altura(lado);
}

Quadrado::~Quadrado() {}

void Quadrado::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << calcula_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
} 