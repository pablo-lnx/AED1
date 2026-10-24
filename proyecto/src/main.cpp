#include <iostream>
#include <string>
#include "Interprete.h"

using namespace std;

int main(){
    Interprete interprete;
    string comando;

    while (cin >> comando) {
        interprete.ejecutar(comando);
    }
    return 0;
}