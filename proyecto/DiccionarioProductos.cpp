
#include <iostream>
#include <list>
#include <string>
#include "DiccionarioProductos.h"

using namespace std;

// CONSTRUCTOR
DiccionarioProductos::DiccionarioProductos() {}

// INSERTAR
void DiccionarioProductos::insertar(Producto nuevo)
{
    list<Producto>::iterator it = lista_productos.begin();

    // Buscamos la posicion correcta
    while (it != lista_productos.end() &&
           it->getIdentificador() < nuevo.getIdentificador())
    {
        it++;
    }

    // Si ya existe, no lo insertamos
    if (it != lista_productos.end() &&
        it->getIdentificador() == nuevo.getIdentificador())
    {
        return;
    }

    // Insertamos el producto ordenadamente
    lista_productos.insert(it, nuevo);
}

// PALABRAS
void DiccionarioProductos::palabras(string palabra)
{
    tabla.palabras(palabra);
}

// NUMERO DE PRODUCTOS
int DiccionarioProductos::numElem()
{
    return lista_productos.size();
}
