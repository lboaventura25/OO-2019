#include "trianguloEquilatero.hpp"
#include <iostream>
#include <math.h>

using namespace std;

TrianguloEquilatero::TrianguloEquilatero() {}

TrianguloEquilatero::TrianguloEquilatero(float lado) {
    set_tipo("Triângulo Equilátero");
    set_lado(lado);
}
TrianguloEquilatero::~TrianguloEquilatero() {}

void TrianguloEquilatero::set_lado(float lado) {
    this->lado = lado;
}

float TrianguloEquilatero::get_lado() {
    return this->lado;
}

float TrianguloEquilatero::calcula_area() {
    return (sqrt(3)/4) * get_lado() * get_lado();
}

float TrianguloEquilatero::calcula_perimetro() {
    return 3 * get_lado();
}

void TrianguloEquilatero::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << calcula_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
}