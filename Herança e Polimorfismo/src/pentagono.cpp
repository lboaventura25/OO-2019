#include "pentagono.hpp"
#include <iostream>
#include <math.h>

using namespace std;

Pentagono::Pentagono() {}

Pentagono::Pentagono(float lado) {
    set_tipo("Pentágono");
    set_lado(lado);
}

Pentagono::~Pentagono() {}

float Pentagono::calcula_area() {
    float h;
    h = (get_lado() / 2) / tan(0.628319);
    return ((h * get_lado()) / 2) * 5;
}

float Pentagono::calcula_perimetro() {
    return 5 * get_lado();
}

void Pentagono::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << calcula_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
}