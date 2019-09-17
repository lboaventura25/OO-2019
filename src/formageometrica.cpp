#include "formageometrica.hpp"
#include <iostream>

FormaGeometrica::FormaGeometrica(){
    tipo = "Genérico";
    base = 10.0f;
    altura = 5.0;
}
FormaGeometrica::FormaGeometrica(float base, float altura){
    tipo = "Genérico";
    this->base = base;
    this->altura = altura;
}
FormaGeometrica::FormaGeometrica(string tipo, float base, float altura){
    set_tipo(tipo);
    set_base(base);
    set_altura(altura);
}
FormaGeometrica::~FormaGeometrica(){
    cout << "Destruindo o objeto: " << tipo << endl;
}
void FormaGeometrica::set_tipo(string tipo){
    this->tipo = tipo;
}
string FormaGeometrica::get_tipo(){
    return tipo;
}
void FormaGeometrica::set_base(float base){
    if(base < 0)
        throw(1);
    else
        this->base = base;
}
float FormaGeometrica::get_base(){
    return base;
}
void FormaGeometrica::set_altura(float altura){
    if(altura < 0)
        throw(1);
    else
        this->altura = altura;
}
float FormaGeometrica::get_altura(){
    return altura;
}
float FormaGeometrica::calcula_area(){
    return base * altura;
}
float FormaGeometrica::calcula_perimetro(){
    return 2*base + 2*altura;
}
void FormaGeometrica::imprime_forma() {
    cout << "Tipo: " << get_tipo() << endl;
    cout << "Base: " << get_base() << endl;
    cout << "Altura: " << get_altura() << endl;
}