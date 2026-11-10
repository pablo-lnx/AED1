#ifndef _DICCIONARIO_PRODUCTOS
#define _DICCIONARIO_PRODUCTOS

// Arreglar importaciones
#include "Producto.h"
#include "TablaHash.h"
#include "ArbolPrecios.h"
#include <list>

class DiccionarioProductos {
    private:
        // ATRIBUTOS
        std::list<Producto> lista_productos;
        TablaHash tabla;
        ArbolPrecios arbol;
    
    public:
        // CONSTRUCTOR
        DiccionarioProductos();

        // METODOS
        void insertar(Producto nuevo);
        void palabras(std::string palabra);
        void precios(double min, double max);
        int numElem();
};

#endif