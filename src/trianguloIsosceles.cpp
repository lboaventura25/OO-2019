#include "trianguloIsosceles.hpp"
#include <iostream>
#include <math.h>

using namespace std;

TrianguloIsosceles::TrianguloIsosceles() {}

TrianguloIsosceles::TrianguloIsosceles(float base, float altura){
    set_tipo("Triângulo Isósceles");
    set_base(base);
    set_altura(altura);
}

TrianguloIsosceles::~TrianguloIsosceles() {}

float TrianguloIsosceles::calcula_perimetro() {
    float lado;
    lado = sqrt(pow(get_altura(), 2) + pow(get_base() / 2, 2));
    return lado + lado + get_base();
}
void TrianguloIsosceles::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << calcula_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
}
