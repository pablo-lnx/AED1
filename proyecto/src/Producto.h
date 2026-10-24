#ifndef _PRODUCTO
#define _PRODUCTO

#include <string>

using ull = unsigned long long;

class Producto {
    private:
        // Atributos
        ull identificador;
        std::string nombre;
        std::string descripcion;
        double precio;

    public:
        // CONSTRUCTOR
        Producto();

        // GETTERS
        ull getIdentificador() { return identificador; }

        // METODOS
        void leer();
        void mostrar();
};

#endif