#ifndef _DICCIONARIO_PRODUCTOS
#define _DICCIONARIO_PRODUCTOS

// Arreglar importaciones
#include "Producto.h"
#include <list>

class DiccionarioProductos {
    private:
        // ATRIBUTOS
        std::list<Producto> lista_productos;
        TablaHash tabla;
    
    public:
        // CONSTRUCTOR
        DiccionarioProductos();

        // METODOS
        void insertar(Producto nuevo);      // Insertar de forma ordenada (ID del producto)
        void palabras(std::string palabra);
        int numElem()   // Devuelve el numero de productos
};

#endif