
#include <iostream>
#include <string>
#include <sstream>
#include "TablaHash.h"

using namespace std;

static string minusculas(string entrada)
{
    string salida = entrada;
    for (unsigned i=0; i<entrada.length(); i++) {
        
        if (entrada[i] >= 'A' && entrada[i] <= 'Z')  salida[i] = (char)tolower(entrada[i]);
        
        else if (entrada[i] == (char) 0xC3) {
            salida[i] = (char) 0xC3;
            switch (entrada[i+1])
            {
            case (char) 0x81:
                salida[i+1] = (char) 0xA1;
                ++i;
                break;
            
            case (char) 0x89:
                salida[i+1] = (char) 0xA9;
                ++i;
                break;

            case (char) 0x8D:
                salida[i+1] = (char) 0xAD;
                ++i;
                break;

            case (char) 0x93:
                salida[i+1] = (char) 0xB3;
                ++i;
                break;

            case (char) 0x9A:
                salida[i+1] = (char) 0xBA;
                ++i;
                break;

            case (char) 0x9C:
                salida[i+1] = (char) 0xBC;
                ++i;
                break;

            case (char) 0x91:
                salida[i+1] = (char) 0xB1;
                ++i;
                break;

            default:
                break;
            }
        }
        
        else salida[i] = entrada[i];
    }

    return salida;
}

// CONSTRUCTOR
TablaHash::TablaHash(){}

// DESTRUCTOR
TablaHash::~TablaHash(){}

// FUNCION HASH
int TablaHash::funcionHash(string palabra) const
{
    int suma = 0;

    for (unsigned i = 0; i < palabra.length(); i++){
        suma = suma + (unsigned char) palabra[i];
    }

    return suma % 100;
}

// INSERTAR
void TablaHash::insertar(string palabra, Producto* nuevo)
{
    palabra = minusculas(palabra);
    int posicion = funcionHash(palabra);

    list<Entrada>::iterator it = tabla[posicion].begin();

    bool encontrado = false;

    // Buscamos si la palabra ya existe
    while (it != tabla[posicion].end() && !encontrado){
        
        if (it->palabra == palabra) encontrado = true;
        
        else it++;
    }

    // Si la palabra no existe, creamos una nueva entrada
    if (!encontrado)
    {
        tabla[posicion].push_back(Entrada());

        it = tabla[posicion].end();
        it--;

        it->palabra = palabra;
    }

    // Buscamos la posicion del producto según su identificador
    list<Producto*>::iterator itProducto;
    itProducto = it->productos.begin();

    bool repetido = false;

    while (itProducto != it->productos.end() &&
           (*itProducto)->getIdentificador() < nuevo->getIdentificador())
    {
        itProducto++;
    }

    // Comprobamos si el producto ya existe
    if (itProducto != it->productos.end() &&
        (*itProducto)->getIdentificador() == nuevo->getIdentificador())
    {
        repetido = true;
    }

    // Si no está repetido, lo insertamos ordenadamente
    if (!repetido)
    {
        it->productos.insert(itProducto, nuevo);
    }
}

// PALABRAS
int TablaHash::palabras(string palabra) const
{
    palabra = minusculas(palabra);
    int posicion = funcionHash(palabra);

    list<Entrada>::const_iterator it;
    it = tabla[posicion].begin();

    bool encontrado = false;

    // Buscamos la palabra
    while (it != tabla[posicion].end() && !encontrado)
    {
        if (it->palabra == palabra) encontrado = true;

        else it++;
    }

    int contador = 0;

    // Si la palabra existe, mostramos sus productos
    if (encontrado)
    {
        list<Producto*>::const_iterator itProducto;
        itProducto = it->productos.begin();

        while (itProducto != it->productos.end())
        {
            contador++;

            cout << contador << ". ";
            (*itProducto)->mostrar();

            itProducto++;
        }
    }

    cout << "Total: " << contador << " productos" << endl;

    return contador;
}
