#include <iostream>
using namespace std;
#include <unistd.h>

void Problema16()
{
    int n;
    cout <<"En este problema se ingresa un numero n y en una malla nxn solo pudiendo moverte hacia la derecha o hacia abajo, se imprime cuantos posibles caminos hay"<<endl;
    cout <<"Ingrese un numero"<<endl;
    cin >>n;

    int resultado = 1;
    for (int i = 1; i <= n; ++i) {
        resultado = resultado * (n + i) / i;
    }

    cout <<"Para una malla de "<<n<<'x'<<n<<" hay "<<resultado<<" caminos."<<endl;
    sleep(3);
}
