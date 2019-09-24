#include "hexagono.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Hexagono::Hexagono() {}

Hexagono::Hexagono(float lado) {
    set_tipo("Hexágono");
    set_lado(lado);
}

Hexagono::~Hexagono() {}

float Hexagono::get_area() {
    return 6 * calcula_area();
}

float Hexagono::calcula_perimetro() {
    return 6 * get_lado();
}

void Hexagono::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << get_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
}