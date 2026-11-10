
#include <iostream>
#include <string>
#include "Interprete.h"

using namespace std;

// CONSTRUCTOR
Interprete::Interprete(){}

// PROCESAR INSERTAR
void Interprete::procesar_insertar()
{
    Producto nuevo;
    nuevo.leer();

    dic.insertar(nuevo);

    cout << dic.numElem() << " productos" << endl;
}

// PROCESAR PALABRAS
void Interprete::procesar_palabras()
{
    string palabra;
    cin >> palabra;
    cout << "palabras " << palabra << endl;
    dic.palabras(palabra);
}

// PRECIOS
void Interprete::procesar_precios()
{
    double min, max;
    cin >> min >> max;

    cout << "precios " << min << " " << max << endl;

    dic.precios(min, max);
}

// EJECUTAR COMANDO
void Interprete::ejecutar(string comando)
{
    if (comando == "insertar") procesar_insertar();
    if (comando == "palabras") procesar_palabras();
    if (comando == "precios") procesar_precios();
}
