#include <iostream>
#include <list>
#include <string>
#include "DiccionarioProductos.h"

using namespace std;

// CONSTRUCTOR
DiccionarioProductos::DiccionarioProductos(){
    contador = 0;
}

// METODOS

void DiccionarioProductos::insertar(Producto nuevo)
{
    // Comprueba si la lista no tiene algun producto aun
    if (!lista_productos.size()) {
        lista_productos.push_back(nuevo);
        contador++;
    }
    else {

        list<Producto>::iterator it = lista_productos.begin();  // Inicializo el objeto iterador
        
        // Busca en la lista el indice/puntero que mantiene la lista ordenada tras incluir el nuevo producto
        while (it!=lista_productos.end() && it->getIdentificador() < nuevo.getIdentificador()) 
            ++it;

        // Comprueba que el bucle ha terminado con un puntero valido o no, y que no se este intentando insertar un producto ya existente
        if (it==lista_productos.end() || it->getIdentificador() != nuevo.getIdentificador()) {
            // objlista.insert(itLista, valor);
            lista_productos.insert(it, nuevo);
            ++contador;
        }
    }
}

void DiccionarioProductos::eliminar(ull id)
{
    // POR HACER
}

int DiccionarioProductos::producto(ull id)
{
    list<Producto>::iterator it = lista_productos.begin();

    // Busca en la lista el indice/puntero que tiene el ID buscado
    while (it!=lista_productos.end() && it->getIdentificador() != id)
        ++it;

    if (it==lista_productos.end()) return 0;

    cout << "1. ";
    it->mostrar();
    return 1;
}

void DiccionarioProductos::precios(double min, double max)
{
    // POR HACER
}