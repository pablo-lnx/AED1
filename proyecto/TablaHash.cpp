
#include <iostream>
#include "TablaHash.h"

using namespace std;

// CONSTRUCTOR
TablaHash::TablaHash(){}

// DESTRUCTOR
TablaHash::~TablaHash(){}

// FUNCION HASH
int TablaHash::funcionHash(string palabra) const
{
    int suma = 0;

    for (unsigned i = 0; i < palabra.length(); i++)
    {
        suma = suma + (unsigned char) palabra[i];
    }

    return suma % 100;
}

// INSERTAR
void TablaHash::insertar(string palabra, Producto* nuevo)
{
    int posicion = funcionHash(palabra);

    list<Entrada>::iterator it;
    it = tabla[posicion].begin();

    bool encontrado = false;

    // Buscamos si la palabra ya existe
    while (it != tabla[posicion].end() && !encontrado)
    {
        if (it->palabra == palabra)
        {
            encontrado = true;
        }
        else
        {
            it++;
        }
    }

    // Si la palabra no existe, creamos una nueva entrada
    if (!encontrado)
    {
        tabla[posicion].push_back(Entrada());

        it = tabla[posicion].end();
        it--;

        it->palabra = palabra;
    }

    // Buscamos la posicion del producto según su identificador
    list<Producto*>::iterator itProducto;
    itProducto = it->productos.begin();

    bool repetido = false;

    while (itProducto != it->productos.end() &&
           (*itProducto)->getIdentificador() < nuevo->getIdentificador())
    {
        itProducto++;
    }

    // Comprobamos si el producto ya existe
    if (itProducto != it->productos.end() &&
        (*itProducto)->getIdentificador() == nuevo->getIdentificador())
    {
        repetido = true;
    }

    // Si no está repetido, lo insertamos ordenadamente
    if (!repetido)
    {
        it->productos.insert(itProducto, nuevo);
    }
}

// PALABRAS
int TablaHash::palabras(string palabra) const
{
    int posicion = funcionHash(palabra);

    list<Entrada>::const_iterator it;
    it = tabla[posicion].begin();

    bool encontrado = false;

    // Buscamos la palabra
    while (it != tabla[posicion].end() && !encontrado)
    {
        if (it->palabra == palabra)
        {
            encontrado = true;
        }
        else
        {
            it++;
        }
    }

    int contador = 0;

    // Si la palabra existe, mostramos sus productos
    if (encontrado)
    {
        list<Producto*>::const_iterator itProducto;
        itProducto = it->productos.begin();

        while (itProducto != it->productos.end())
        {
            contador++;

            cout << contador << ". ";
            (*itProducto)->mostrar();

            itProducto++;
        }
    }

    cout << "Total: " << contador << " productos" << endl;

    return contador;
}
