#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string cadena;
    int cont = 1;

    while (getline(cin, cadena)) {
        cout << cont << ". " << cadena << endl;
        istringstream iss(cadena);
        string palabra;
        
        while (iss >> palabra) {
            cout << palabra << "\n";
        }
        cont++;
    }

    return 0;
}