#include <iostream>
using namespace std;
#include <unistd.h>

void Problema12()
{
    int matriz[3][3];
    cout <<"En este problema se ingresa una matriz 3x3 y dice si la matriz es una matriz magica o no"<<endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout <<"Ingrese el "<<j+1<<" numero de la "<<i+1<<" fila"<<endl;
            cin >>matriz[i][j];
        }
    }
    cout <<"La matriz: "<<endl;
    int sumaMagica = matriz[0][0] + matriz[0][1] + matriz[0][2];
    bool esMagica = true;

    for (int i = 0; i < 3; i++) {
        int sumaFila = 0;
        int sumaCol = 0;
        for (int j = 0; j < 3; j++) {
            sumaFila += matriz[i][j];
            sumaCol += matriz[j][i];

            cout <<matriz[i][j]<<" ";
        }
        if (sumaFila != sumaMagica) {
            esMagica = false;
        if (sumaCol != sumaMagica) {
            esMagica = false;
        }
        }
        cout <<endl;
    }

    if (esMagica == true) {
        int diag1 = matriz[0][0] + matriz[1][1] + matriz[2][2];
        int diag2 = matriz[0][2] + matriz[1][1] + matriz[2][0];
        if (diag1 != sumaMagica || diag2 != sumaMagica) {
            esMagica = false;
        }
    }

    if (esMagica == true) {
        cout <<"\nEs magica."<<endl;
    } else {
        cout <<"\nNo es magica."<<endl;
    }
    sleep(3);
}
