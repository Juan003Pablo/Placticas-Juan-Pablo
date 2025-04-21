#include <iostream>
using namespace std;
#include <unistd.h>

void Problema8()
{
    string cadena;
    string resultado_n = "";
    string resultado_c = "";
    cout <<"En este problema se ingresa una cadena de caracteres y luego se sepera los caracteres y los numeros"<<endl;
    cout <<"Ingrese una cadena de caracteres y numero"<<endl;
    cin >>cadena;

    for (size_t i = 0; i < cadena.length(); ++i) {
        if(cadena[i] >= 48 && cadena[i] <= 57){
            resultado_n += cadena[i];
        }
        else{
            resultado_c += cadena[i];
        }
    }
    cout <<"Original: "<<cadena<<'.'<<endl;
    cout <<"Texto: "<<resultado_c<<". Numeros: "<<resultado_n<<'.'<<endl;
    sleep(3);
}
