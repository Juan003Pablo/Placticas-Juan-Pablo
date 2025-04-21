#include <iostream>
using namespace std;
#include <unistd.h>

void Problema4()
{
    string cadena;
    cout <<"En este problema se ingresa un string de numeros y se transforma en un int"<<endl;
    cout<<"Escribe una cadena de numeros"<<endl;
    cin>>cadena;
    int longitud = cadena.length();

    // falta validacion
    int resultado = cadena[0]-48;
    for (int i = 1; i < longitud; ++i) {
        int numero = cadena[i]-48;
        resultado = resultado * 10 + numero;
    }

    cout<<"El resultado convertido en int: "<<resultado<<endl;
    sleep(3);
}
