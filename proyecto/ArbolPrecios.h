#ifndef _ARBOL_PRECIOS
#define _ARBOL_PRECIOS

#include "Producto.h"
#include <list>
#include <vector>

class ArbolPrecios {
private:

    struct Nodo {
        int precio;
        std::list<Producto*> productos;

        Nodo* izquierdo;
        Nodo* derecho;

        int altura;

        Nodo(int precio, Producto* producto);
        ~Nodo();
    };

    Nodo* raiz;

    // Operaciones auxiliares del AVL
    int altura(Nodo* nodo) const;
    int factorEquilibrio(Nodo* nodo) const;

    Nodo* rotacionDerecha(Nodo* nodo);
    Nodo* rotacionIzquierda(Nodo* nodo);

    Nodo* equilibrar(Nodo* nodo);

    Nodo* insertar(Nodo* nodo, int precio, Producto* producto);

    void consultar(Nodo* nodo, int min, int max,
                   std::vector<Producto*>& resultado) const;

public:

    ArbolPrecios();
    ~ArbolPrecios();

    void insertar(Producto* producto);
    void precios(double min, double max);
};

#endif