#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using ull = unsigned long long;

class Producto {
    private:
        // Atributos
        ull identificador;	// Necesito un TD con al menos 13D
                            // int = long (Tamaño)
                            // (10D) long:                (-2,147,483,648 - 2,147,483,647)
                            // (10D) unsigned long:       (0 - 4,294,967,295)
                            // (19D) long long:           (-9,223,372,036,854,775,808 - 9,223,372,036,854,775,807)
                            // (20D) unsigned long long:  (0 - 18,446,744,073,709,551,615)
                            // int < uint < ll < ull
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


int main(){
    Producto producto;
    string comando;
    int contador = 0;
    
    while (cin >> comando) {
        if (comando=="insertar") {
            producto.leer ();
            cout << ++contador << ". ";
            producto.mostrar();
        }
    }

    return 0;
}