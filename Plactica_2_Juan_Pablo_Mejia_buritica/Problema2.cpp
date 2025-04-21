#include <iostream>
using namespace std;
#include <unistd.h>
#include <cstdlib>
#include <ctime>

void Problema2()
{
    char arreglo[200];
    int contador[26] = {0};
    string letrasArreglo;
    srand(time(0));
    cout <<"En este problema se genera un arreglo de 200 letras aleatorias y luego se imprime junto a una cuantas veces hay cada letra"<<endl;

    for (int i = 0; i < 200; ++i) {
        char letra = 'A' + (rand() % 26);
        letrasArreglo += letra;
        arreglo[i] = letra;
        contador[arreglo[i] - 'A']++;
    }
    cout<<letrasArreglo<<endl;
    for (int i = 0; i < 26; ++i) {
        if (contador[i] > 0) {
            cout <<char('A'+ i)<<": "<<contador[i]<<endl;
        }
    }
    sleep(3);
}
