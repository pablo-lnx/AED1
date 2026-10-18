#include <iostream>
#include <string>

using namespace std;
using ull = unsigned long long;

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
            cout << nombre << " (" << identificador << ")" << endl
            << "  " << descripcion << endl
            << "  " << precio << " euros" << endl;
        };
};

// Variables globales
int contador = 0;       // Contador numero de productos
Producto producto;

// Prototipos
void procesar_insertar();
void procesar_palabras();
void procesar_precios();    
void procesar_eliminar();
void procesar_producto();
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
    if (comando=="insertar") procesar_insertar();
    else if (comando=="palabras") procesar_palabras();
    else if (comando=="precios") procesar_precios();
    else if (comando=="eliminar") procesar_eliminar();
    else if (comando=="producto") procesar_producto();
};

void procesar_insertar()
{
    ::producto.leer();
    cout << ++::contador << " productos" << endl;
};

void procesar_palabras()
{
    string comando;

    cin.ignore();
    // Es necesario usar getline ya que el numero de palabras es indefinido
    getline(cin, comando);
    
    cout << "palabras " << comando << endl;
    // cout << ::contador << ". ";
    cout << "1. ";
    ::producto.mostrar();
    // cout << "Total: " << ::contador << " producto" << endl;
    cout << "Total: 1 producto" << endl;
};

void procesar_precios()
{
    double min, max;
    cin >> min >> max;

    cout << "precios " << min << " "<< max << endl;
    // cout << ::contador << ". ";
    cout << "1. ";
    ::producto.mostrar();
    // cout << "Total: " << ::contador << " producto" << endl;
    cout << "Total: 1 producto" << endl;
};

void procesar_eliminar()
{
    cout << --::contador << " productos" << endl;
};

void procesar_producto()
{
    // Arreglar logica con el contador
    ull id;
    cin >> id;

    cout << "producto " << id << endl;
    cout << "1. ";
    //cout << ::contador << ". ";
    ::producto.mostrar();
    // cout << "Total: " << ::contador << " producto" << endl;
    cout << "Total: " << 1 << " producto" << endl;
};
