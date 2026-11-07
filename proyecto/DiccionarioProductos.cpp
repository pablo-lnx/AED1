
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

    lista_productos.insert(it, nuevo);
    Producto* producto = &(*it);

    // Indexamos las palabras del nombre
    stringstream flujoNombre(producto->getNombre());
    string palabra;

    while (flujoNombre >> palabra) tabla.insertar(palabra, producto);

    // Indexamos las palabras de la descripcion
    stringstream flujoDescripcion(producto->getDescripcion());

    while (flujoDescripcion >> palabra) tabla.insertar(palabra, producto);
    
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
