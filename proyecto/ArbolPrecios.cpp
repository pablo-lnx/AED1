
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
    Nodo* aux = izq->derecho;       // Subarbol derecho del Hijo izquierdo

    izq->derecho = nodo;
    nodo->izquierdo = aux;

    nodo->altura = 1 + max(altura(nodo->izquierdo),
                           altura(nodo->derecho));

    izq->altura = 1 + max(altura(izq->izquierdo),
                          altura(izq->derecho));

    return izq;
}

ArbolPrecios::Nodo* ArbolPrecios::rotacionIzquierda(Nodo* nodo)
{
    Nodo* der = nodo->derecho;      // Hijo derecho
    Nodo* aux = der->izquierdo;     // Subarbol izquierdo del Hijo derecho

    der->izquierdo = nodo;
    nodo->derecho = aux;

    nodo->altura = 1 + max(altura(nodo->izquierdo),
                           altura(nodo->derecho));

    der->altura = 1 + max(altura(der->izquierdo),
                          altura(der->derecho));

    return der;
}

ArbolPrecios::Nodo* ArbolPrecios::equilibrar(Nodo* nodo)
{
    // TODO:
    // 1. Actualizar la altura del nodo.
    // 2. Calcular el factor de equilibrio.
    // 3. Detectar los casos LL, RR, LR y RL.
    // 4. Aplicar las rotaciones correspondientes.

    return nodo;
}


// ============================================================
// INSERCIÓN RECURSIVA
// ============================================================

ArbolPrecios::Nodo* ArbolPrecios::insertar(
    Nodo* nodo, int precio, Producto* producto)
{
    // TODO:
    // 1. Si el nodo es nullptr, crear un nodo nuevo.
    // 2. Si el precio es menor, insertar por la izquierda.
    // 3. Si el precio es mayor, insertar por la derecha.
    // 4. Si el precio coincide, añadir el producto a la lista.
    // 5. Equilibrar el nodo antes de devolverlo.

    return nodo;
}


// ============================================================
// INSERCIÓN PÚBLICA
// ============================================================

void ArbolPrecios::insertar(Producto* producto)
{
    // TODO:
    // 1. Obtener el precio mediante producto->getPrecio().
    // 2. Convertirlo a céntimos.
    // 3. Actualizar la raíz mediante la inserción recursiva.
}


// ============================================================
// CONSULTA RECURSIVA POR INTERVALO
// ============================================================

void ArbolPrecios::consultar(
    Nodo* nodo, int min, int max,
    vector<Producto*>& resultado) const
{
    // TODO:
    // 1. Si nodo es nullptr, terminar.
    // 2. Si el precio está dentro del intervalo,
    //    añadir sus productos al vector.
    // 3. Explorar únicamente los subárboles que puedan
    //    contener precios dentro del intervalo.
}


// ============================================================
// CONSULTA PÚBLICA
// ============================================================

void ArbolPrecios::precios(double min, double max)
{
    // TODO:
    // 1. Convertir los límites a céntimos.
    // 2. Recopilar los productos mediante consultar().
    // 3. Ordenar los productos por identificador ascendente,
    //    sin utilizar std::sort ni <algorithm>.
    // 4. Mostrar los productos con el formato del enunciado.
    // 5. Mostrar el total de productos.
}
