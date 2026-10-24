#ifndef _DICCIONARIO_PRODUCTOS
#define _DICCIONARIO_PRODUCTOS

#include "Producto.h"
#include <list>

class DiccionarioProductos {
    private:
        // ATRIBUTOS
        std::list<Producto> lista_productos;
        int contador;
    
    public:
        // CONSTRUCTOR
        DiccionarioProductos();

        // METODOS
        void insertar(Producto nuevo);          // Insertar de forma ordenada (ID del producto)
        void eliminar(ull id);                  // Elimina el objeto de la lista asociado con el ID pasado como parametro
        void producto(ull id);                  // Consulta un producto dado su ID
        void precios(double min, double max);   // Dados un precio minimo y maximo, busca los productos en dicho rango y muestralos por orden de ID
        int numElem() { return contador; }      // Devuelve el numero de productos
};

#endif