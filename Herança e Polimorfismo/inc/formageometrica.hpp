#ifndef FORMAGEOMETRICA_HPP
#define FORMAGEOMETRICA_HPP

#include <string>

using namespace std;

class FormaGeometrica {
private:
    string tipo;
    float base;
    float altura;
public:
    FormaGeometrica();
    FormaGeometrica(float base, float altura);
    FormaGeometrica(string tipo, float base, float altura);
    ~FormaGeometrica();
    void set_tipo(string tipo);
    string get_tipo();
    void set_base(float base);
    float get_base();
    void set_altura(float altura);
    float get_altura();
    float calcula_area();
    float calcula_perimetro();

    virtual void imprime_forma();
};

#endif