#include "triangulo.hpp"
#include <iostream>
#include <math.h>

Triangulo::Triangulo() {}

Triangulo::~Triangulo() {}

Triangulo::Triangulo(float base, float altura) {
    set_tipo("Triângulo Retângulo");
    set_base(base);
    set_altura(altura);
}

float Triangulo::calcula_area() {
    return (get_base() * get_altura()) / 2.0; 
}

float Triangulo::calcula_perimetro() {
    float hipot;
	hipot = sqrt(pow(get_base(), 2) + pow(get_altura(), 2));
	return hipot + get_base() + get_altura();
}

void Triangulo::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << calcula_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
} 