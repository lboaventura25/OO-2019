#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <unistd.h>
#include "cliente.hpp"
#include "produto.hpp"
#include "funcoes.hpp"
#include "menu.hpp"

using namespace std;

int main() {

    int resp = -1;
    Menu menu;

    while(resp != 0) {
        menu.menu_inicio();
        resp = getInt();

        switch(resp) {
            case 1:
                menu.menu_modoVenda();
                break;

            case 2:
                menu.menu_modoEstoque();
                break;

            case 3:
                menu.menu_modoRecomendacao();
                break;

            case 0:
                break;

            default:
                cout << "Opção Inválida!" << endl;
                sleep(1);
                break;
        }
    }
    return 0;
}