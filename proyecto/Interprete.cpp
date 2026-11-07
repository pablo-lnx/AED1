#include <iostream>
#include <string>
#include "Interprete.h"

using namespace std;

// CONSTRUCTOR
Interprete::Interprete(){}

// METODOS
void Interprete::procesar_insertar()
{
    Producto nuevo;
    nuevo.leer();
    dic.insertar(nuevo);
    cout << dic.numElem() << " productos" << endl;
}

void Interprete::ejecutar(string comando)
{
    if (comando=="insertar") procesar_insertar();
    if (comando=="palabras") procesar_palabras();
}