
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include "DiccionarioProductos.h"

using namespace std;

// CONSTRUCTOR
DiccionarioProductos::DiccionarioProductos() {}

// INSERTAR
void DiccionarioProductos::insertar(Producto nuevo)
{
    // Insertamos el producto al principio de la lista en O(1)
    lista_productos.push_front(nuevo);

    // Obtenemos un puntero al producto insertado
    Producto* producto = &lista_productos.front();
    arbol.insertar(producto);

    // Indexamos las palabras del nombre
    stringstream flujoNombre(producto->getNombre());
    string palabra;

    while (flujoNombre >> palabra)
        tabla.insertar(palabra, producto);

    // Indexamos las palabras de la descripcion
    stringstream flujoDescripcion(producto->getDescripcion());

    while (flujoDescripcion >> palabra)
        tabla.insertar(palabra, producto);
}

// PALABRAS
void DiccionarioProductos::palabras(string palabra)
{
    tabla.palabras(palabra);
}

// PRECIOS
void DiccionarioProductos::precios(double min, double max)
{
    arbol.precios(min, max);
}

// NUMERO DE PRODUCTOS
int DiccionarioProductos::numElem()
{
    return lista_productos.size();
}
