#include <iostream>
using namespace std;
#include <unistd.h>
#include "header.h"

void Problema10()
{
    string n;
    bool n_lvalido = true;
    int resultado = 0;
    int n_lsiguente;
    cout <<"En este problema se ingresa un numero romano y se convierte al sistema arabigo"<<endl;

    do {
    n_lvalido = true;
    resultado = 0;
    cout <<"ingrese el numero romano"<<endl;
    cin >>n;

    for (size_t i = 0; i < n.length() && n_lvalido == true; ++i) {
        int n_letra = valorRomano(n[i]);
        if(n_letra == -1){
            cout <<"El numero romano inglesado tiene un caracter invalido"<<endl;
            sleep(2);
            n_lvalido = false;
            break;
        }

        if(i + 1 < n.length()){
            n_lsiguente = valorRomano(n[i + 1]);
        } else{
            n_lsiguente = 0;
        }

        if(n_letra < n_lsiguente){
            resultado += -n_letra;
        } else{
            resultado += n_letra;
        }

    }
    } while (n_lvalido == false);

    cout <<"El numero en sistema arabigo es: "<<resultado<<endl;
    sleep(3);
}
