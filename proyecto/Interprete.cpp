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

void Interprete::procesar_eliminar ()
{
    ull id;
    cin >> id;
    dic.eliminar(id);
    cout << dic.numElem() << " productos" << endl;
}

void Interprete::procesar_producto()
{
    ull id;
    cin >> id;
    cout << "producto " << id << endl;
    int encontrados = dic.producto(id);
    cout << "Total: " << encontrados << " productos" << endl;
}

void Interprete::procesar_precios()
{
    // POR HACER
}

void Interprete::ejecutar(string comando)
{
    if (comando=="insertar") procesar_insertar();
    else if (comando=="eliminar") procesar_eliminar();
    else if (comando=="producto") procesar_producto();
    else if (comando=="precios") procesar_precios();
}