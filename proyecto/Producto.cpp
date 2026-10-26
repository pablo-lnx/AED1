#include <iostream>
#include <string>

#include "Producto.h"

using namespace std;

// CONSTRUCTOR
Producto::Producto(){
    identificador = 0;
    nombre = "";
    descripcion = "";
    precio = 0.0;
}

// METODOS
void Producto::leer()
{
    cin >> identificador;
    cin.ignore();
    getline(cin, nombre);
    getline(cin, descripcion);
    cin >> precio;
}

void Producto::mostrar()
{
    cout << nombre << " (" << identificador << ")" << endl
    << "  " << descripcion << endl
    << "  " << precio << " euros" << endl;
}