#include <iostream>
using namespace std;
#include "header.h"


int main()
{
    int p;

    while (true) {
        cout<<"\nEliga un problema par (2-18)"<<"\n0 para salir"<<endl;
        cin>>p;
        switch (p){
        case 0:
            return 0;
        case 2:
            cout<<'\n';
            Problema2();
            break;
        case 4:
            cout<<'\n';
            Problema4();
            break;
        case 6:
            cout<<'\n';
            Problema6();
            break;
        case 8:
            cout<<'\n';
            Problema8();
            break;
        case 10:
            cout<<'\n';
            Problema10();
            break;
        case 12:
            cout<<'\n';
            Problema12();
            break;
        case 14:
            cout<<'\n';
            Problema14();
            break;
        case 16:
            cout<<'\n';
            Problema16();
            break;
        case 18:
            cout<<'\n';
            Problema18();
            break;
        default:
            break;
        }
    }
}
