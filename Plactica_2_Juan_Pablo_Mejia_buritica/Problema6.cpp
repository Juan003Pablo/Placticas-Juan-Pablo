#include <iostream>
using namespace std;
#include <unistd.h>

void Problema6()
{
    string cadena;
    string resultado = "";
    cout <<"En este problema se ingresa una cadena y luego lo devuelve en mayusculas"<<endl;
    cout <<"escriba el texto"<<endl;
    cin >>cadena;

    for (size_t i = 0; i < cadena.length(); ++i) {
        if(cadena[i] >= 97 && cadena[i] <= 122){
            resultado += cadena[i]-32;
        }
        else if(cadena[i] == -92){
            resultado += cadena[i]+1;
        }
        else{
            resultado += cadena[i];
        }
    }

    cout <<"Original: "<<cadena<<". En mayusculas: "<<resultado<<"."<<endl;
    sleep(3);
}
