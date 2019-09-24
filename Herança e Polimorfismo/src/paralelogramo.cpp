#include "paralelogramo.hpp"
#include <iostream>

using namespace std;

Paralelogramo::Paralelogramo() {}

Paralelogramo::Paralelogramo(float base, float altura) {
    set_tipo("Paralelogramo");
    set_base(base);
    set_altura(altura);
}

Paralelogramo::~Paralelogramo() {}

void Paralelogramo::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Area: " << calcula_area() << endl;
    cout << "Perimetro: " << calcula_perimetro() << endl;
} 