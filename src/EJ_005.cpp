#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using ull = unsigned long long;

int contador = 0;   // Variable global => Contador numero de productos

class Producto {
    private:
        // Atributos
        ull identificador;
        string nombre;
        string descripcion;
        double precio;

    public:
        // Constructor
        Producto()
        {
            identificador = 0;
            nombre = "";
            descripcion = "";
            precio = 0.0;
        };

        // Metodos
        void leer()
        {
            cin >> identificador;
            cin.ignore();
            getline(cin, nombre);
            getline(cin, descripcion);
            cin >> precio;
        };

        void mostrar()
        {
            cout << ::contador << ".  " << nombre << " (" << identificador << ")" << endl
            << "  " << descripcion << endl
            << "  " << precio << " euros" << endl;
        };
};

Producto producto;  // Objeto global

// Prototipos
void procesar_insertar();
void procesar_palabras();
void procesar_precios();            // Resolver       
void procesar_eliminar();           // Resolver
void procesar_producto();           // Resolver
void interprete(string comando);

int main(){
    string comando;

    while (cin >> comando) {
        interprete(comando);
    }
    return 0;
}

// Metodos
void interprete (string comando)
{
    if (comando=="insertar")  procesar_insertar();
    else if (comando=="palabras")  procesar_palabras();
    else if (comando=="precios")  procesar_precios();
    else if (comando=="eliminar")  procesar_eliminar();
    else  procesar_producto();
};

void procesar_insertar()
{
    ::producto.leer();
    cout << ++::contador << " productos" << endl;
};

void procesar_palabras()
{
    string nombre_p;

    cin.ignore();
    getline(cin, nombre_p);
    
    cout << "palabras " << nombre_p << endl;
    ::producto.mostrar();
    cout << "Total: " << ::contador << " producto" << endl;
};

void procesar_precios()
{

};

void procesar_eliminar()
{

};

void procesar_producto()
{

};