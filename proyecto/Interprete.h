#ifndef _INTERPRETE
#define _INTERPRETE

#include <string>
#include "DiccionarioProductos.h"

class Interprete {
    private:
        // ATRIBUTOS
        DiccionarioProductos dic;

        // METODOS PRIVADOS
        void procesar_insertar ();
        void procesar_eliminar();
        void procesar_producto();
        void procesar_precios();

    public:
        // CONSTRUCTOR
        Interprete();

        // METODOS
        void ejecutar(std::string comando);
};

#endif