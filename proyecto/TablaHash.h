#ifndef _TABLA_HASH
#define _TABLA_HASH

#include "Producto.h"
#include <list>
#include <string>
#include <vector>

using ull = unsigned long long;

class TablaHash
{
    private:
        // ATRIBUTOS
        struct Entrada
        {
            std::string palabra;
            std::list<Producto*> productos;
        };

        std::vector<std::list<Entrada>> tabla;
        int numPalabras;

        // METODOS PRIVADOS
        int funcionHash(std::string palabra) const;
        void reestructurar();

    public:
        // CONSTRUCTOR Y DESTRUCTOR
        TablaHash();
        ~TablaHash();

        // METODOS
        void insertar(std::string palabra, Producto* nuevo);
        int palabras(std::string palabra) const;
};

#endif