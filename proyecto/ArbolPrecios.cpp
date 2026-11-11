
#include "ArbolPrecios.h"
#include <iostream>

using namespace std;

// CONSTRUCTOR (NODO)
ArbolPrecios::Nodo::Nodo(int precio, Producto* producto)
{
    this->precio = precio;
    productos.push_back(producto);

    izquierdo = nullptr;
    derecho = nullptr;

    altura = 1;
}

// DESTRUCTOR (NODO)
ArbolPrecios::Nodo::~Nodo()
{
    delete izquierdo;
    delete derecho;
}

// CONSTRUCTOR (ARBOL)
ArbolPrecios::ArbolPrecios()
{
    raiz = nullptr;
}

// DESTRUCTOR (ARBOL)
ArbolPrecios::~ArbolPrecios()
{
    delete raiz;
}

// METODOS AUX (Arbol AVL)

int ArbolPrecios::altura(Nodo* nodo) const
{
    if (nodo == nullptr)
        return 0;

    return nodo->altura;
}

int ArbolPrecios::factorEquilibrio(Nodo* nodo) const
{
    if (nodo == nullptr)
        return 0;

    return altura(nodo->izquierdo) - altura(nodo->derecho);
}

// ROTACIONES

ArbolPrecios::Nodo* ArbolPrecios::rotacionDerecha(Nodo* nodo)
{
    Nodo* izq = nodo->izquierdo;    // Hijo izquierdo
    Nodo* aux = izq->derecho;       // Subárbol derecho del hijo izquierdo

    izq->derecho = nodo;
    nodo->izquierdo = aux;

    // Actualizar altura del nodo que ha descendido
    int altura_izq = altura(nodo->izquierdo);
    int altura_der = altura(nodo->derecho);

    if (altura_izq > altura_der)
        nodo->altura = 1 + altura_izq;
    else
        nodo->altura = 1 + altura_der;

    // Actualizar altura del nodo que ha ascendido
    altura_izq = altura(izq->izquierdo);
    altura_der = altura(izq->derecho);

    if (altura_izq > altura_der)
        izq->altura = 1 + altura_izq;
    else
        izq->altura = 1 + altura_der;

    return izq;
}

ArbolPrecios::Nodo* ArbolPrecios::rotacionIzquierda(Nodo* nodo)
{
    Nodo* der = nodo->derecho;     // Hijo derecho
    Nodo* aux = der->izquierdo;    // Subárbol izquierdo del hijo derecho

    der->izquierdo = nodo;
    nodo->derecho = aux;

    // Actualizar altura del nodo que ha descendido
    int altura_izq = altura(nodo->izquierdo);
    int altura_der = altura(nodo->derecho);

    if (altura_izq > altura_der)
        nodo->altura = 1 + altura_izq;
    else
        nodo->altura = 1 + altura_der;

    // Actualizar altura del nodo que ha ascendido
    altura_izq = altura(der->izquierdo);
    altura_der = altura(der->derecho);

    if (altura_izq > altura_der)
        der->altura = 1 + altura_izq;
    else
        der->altura = 1 + altura_der;

    return der;
}

// EQUILIBRAR
ArbolPrecios::Nodo* ArbolPrecios::equilibrar(Nodo* nodo)
{
    int altura_izq = altura(nodo->izquierdo);
    int altura_der = altura(nodo->derecho);

    if (altura_izq > altura_der)
        nodo->altura = 1 + altura_izq;
    else
        nodo->altura = 1 + altura_der;

    int fe_nodo = factorEquilibrio(nodo);

    if (fe_nodo > 1)         // CASOS LL Y LR
    {
        int fe_hijo = factorEquilibrio(nodo->izquierdo);

        if (fe_hijo < 0)     // LR
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);

        nodo = rotacionDerecha(nodo);
    }
    else if (fe_nodo < -1)   // CASOS RR Y RL
    {
        int fe_hijo = factorEquilibrio(nodo->derecho);

        if (fe_hijo > 0)     // RL
            nodo->derecho = rotacionDerecha(nodo->derecho);

        nodo = rotacionIzquierda(nodo);
    }

    return nodo;
}

// INSERCIÓN RECURSIVA
ArbolPrecios::Nodo* ArbolPrecios::insertar(Nodo* nodo, int precio, Producto* producto)
{
    // Si el nodo es nullptr, crear un nodo nuevo.
    if (nodo == nullptr) return new Nodo(precio, producto);

    // Si el precio es menor, insertar por la izquierda.
    if (precio < nodo->precio) nodo->izquierdo = insertar(nodo->izquierdo, precio, producto);
    
    // Si el precio es mayor, insertar por la derecha.
    else if (precio > nodo->precio) nodo->derecho = insertar(nodo->derecho, precio, producto);

    // Si el precio coincide, añadir el producto a la lista.
    else {
        nodo->productos.push_back(producto);
        return nodo;
    }

    return equilibrar(nodo);
}


// INSERCIÓN PUBLICA
void ArbolPrecios::insertar(Producto* producto)
{ 
    // Convertirlo a céntimos.
    int precio = producto->getPrecio() * 100 + 0.5;
    raiz = insertar(raiz, precio, producto);
}

// CONSULTAR
void ArbolPrecios::consultar(Nodo* nodo, int min, int max, vector<Producto*>& resultado) const
{
    if (nodo != nullptr)
    {
        // Si el precio está dentro del intervalo, añadir sus productos.
        if (nodo->precio >= min && nodo->precio <= max)
        {
            for (Producto* producto : nodo->productos)
                resultado.push_back(producto);
        }

        // Explorar únicamente los subárboles que puedan contener precios dentro del intervalo.
        if (nodo->precio < min)
            consultar(nodo->derecho, min, max, resultado);

        else if (nodo->precio > max)
            consultar(nodo->izquierdo, min, max, resultado);

        else
        {
            consultar(nodo->izquierdo, min, max, resultado);
            consultar(nodo->derecho, min, max, resultado);
        }
    }
}

// PRECIOS
void ArbolPrecios::precios(double min, double max)
{
    // TODO:
    // 1. Convertir los límites a céntimos.
    // 2. Recopilar los productos mediante consultar().
    // 3. Ordenar los productos por identificador ascendente
    // 4. Mostrar los productos con el formato del enunciado.
    // 5. Mostrar el total de productos.
}
