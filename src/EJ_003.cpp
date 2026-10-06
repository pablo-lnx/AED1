// EJERCICIO INCOMPLETO

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string minusculas(string entrada){
    string salida = entrada;
    for (unsigned i=0; i<entrada.length(); i++) {
        if (entrada[i] == 'A' && entrada[i] =='Z')  salida[i] = (char)tolower(entrada[i]);
        else if (entrada[i] == (char) 0xC3) {
            salida[i] = (char) 0xC3;
            switch (entrada[i+1])
            {
            case (char) 0x81:
                salida[i+1] = (char) 0xA1;
                break;
            
            case (char) 0x89:
                salida[i+1] = (char) 0xA9;
                break;

            case (char) 0x8D:
                salida[i+1] = (char) 0xAD;
                break;

            case (char) 0x93:
                salida[i+1] = (char) 0xB3;
                break;

            case (char) 0x9A:
                salida[i+1] = (char) 0xBA;
                break;

            case (char) 0x9C:
                salida[i+1] = (char) 0xBC;
                break;

            case (char) 0x91:
                salida[i+1] = (char) 0xB1;
                break;

            default:
                break;
            }
        }
        else salida[i] = entrada[i];
    }

    return salida;
}

int main(){
    string cadena;
    int cont = 1;

    while (getline(cin, cadena)) {
        cout << cont << ". " << cadena << endl;
        istringstream iss(cadena);
        string palabra;
        
        while (iss >> palabra) {
            cout << minusculas(palabra) << "\n";
        }
        cont++;
    }

    return 0;
}
