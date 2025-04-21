#include <iostream>
using namespace std;
#include <unistd.h>
#include "header.h"

void Problema18()
{
    unsigned long long int n;
    const int tamaño = 10;
    unsigned long long int total_permutaciones = factorial(tamaño);
    cout <<"En este problema se ingresa un numero y te devuelve la enesima permutacion lexicografica"<<endl;

    do {
    cout << "Ingrese el numero"<<endl;
    cin >> n;
    if (n < 1 || n > total_permutaciones) {
        cout << "Numero fuera de rango (debe estar entre 1 y " << total_permutaciones << ")." << endl;
    }
    } while(n < 1 || n > total_permutaciones);

    int digitos[tamaño] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool usados[tamaño] = {false};
    string resultado = "";
    n--;

    for (int i = tamaño - 1; i >= 0; --i) {
        unsigned long long int f = factorial(i);
        int posicion = n / f;
        n %= f;

        int contador = -1;
        for (int j = 0; j < tamaño; ++j) {
            if (!usados[j]) {
                contador++;
                if (contador == posicion) {
                    resultado += to_string(digitos[j]);
                    usados[j] = true;
                    break;
                }
            }
        }
    }

    cout << "Permutacion lexicografica: " << resultado << endl;
}
