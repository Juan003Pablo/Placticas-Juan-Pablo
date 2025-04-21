#include <iostream>
using namespace std;
#include <unistd.h>

void Problema14()
{
    int matriz[5][5];
    int conta = 1;

    cout <<"En este problema se imprime una matriz de 5x5 con los numeros de 1 al 25, y luego la rota 90, 180 y 270 grados\n"<<endl;

    cout <<"\nEsta es la matriz original"<<endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matriz[i][j] = conta;
            conta++;
            if(matriz[i][j] < 10){
                cout <<matriz[i][j]<<"  ";
            } else{
                cout <<matriz[i][j]<<" ";
            }
        }
        cout <<endl;
    }
    sleep(3);
    cout <<"\nEsta es la matriz rotada 90 grados"<<endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(matriz[4-j][i] < 10){
                cout <<matriz[4-j][i]<<"  ";
            } else{
                cout <<matriz[4-j][i]<<" ";
            }
        }
        cout <<endl;
    }
    sleep(3);
    cout <<"\nEsta es la matriz rotada 180 grados"<<endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(matriz[4-i][4-j] < 10){
                cout <<matriz[4-i][4-j]<<"  ";
            } else{
                cout <<matriz[4-i][4-j]<<" ";
            }
        }
        cout <<endl;
    }
    sleep(3);
    cout <<"\nEsta es la matriz rotada 270 grados"<<endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(matriz[j][4-i] < 10){
                cout <<matriz[j][4-i]<<"  ";
            } else{
                cout <<matriz[j][4-i]<<" ";
            }
        }
        cout <<endl;
    }
    sleep(3);
}
