#include "circulo.hpp"
#include <iostream>

using namespace std;

Circulo::Circulo() {}

Circulo::Circulo(float raio) {
    set_tipo("Círculo");
    set_base(raio);
}

Circulo::~Circulo() {}

float Circulo::calcula_area() {
    return 3.14 * get_base() * get_base();
}

float Circulo::calcula_perimetro() {
    return 2.0 * 3.14 * get_base();
}

void Circulo::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << calcula_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
}