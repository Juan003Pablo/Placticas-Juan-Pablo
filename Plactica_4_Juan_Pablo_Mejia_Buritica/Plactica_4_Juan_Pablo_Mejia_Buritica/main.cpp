#include <iostream>
#include "red.h"
#include "enrutador.h"
#include <unistd.h>

using namespace std;

red r;

using namespace std;

bool pedirEnrutadores(char * e)
{
    // pedimos al usuario que ingrese los dos enrutadores.
    bool k = true;

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
        cout << "Ingrese el nombre del enrutador: " << endl;
        cin >> e[i];

        if (!r.existElement(e[i]))
        {
            cout << endl;
            cout << "INFORMACION: " << endl;
            cout << "******* Usuario, el enrutador " << e[i] << " no existe. *******" << endl;
            k = false;
            break;
        }
    }

    return k;
}

int main()
{
    char opcion;

    while(true)
    {
        cout << endl;
        cout << "MENU PRINCIPAL" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        cout << "A- AGREGAR ENRUTADOR" << endl;
        cout << "B- ELIMINAR ENRUTADOR" << endl;
        cout << "C- VER ENRUTADOR" << endl;
        cout << "D- VER TABLA" << endl;
        cout << "E- AGREGAR RELACION" << endl;
        cout << "F- VER COSTO" << endl;
        cout << "G- VER RUTA" << endl;
        cout << "H- GUARDAR ENRUTADORES" << endl;
        cout << "I- CARGAR ARCHIVO" << endl;
        cout << "J- CAMBIAR COSTO" << endl;
        cout << "K- GENERAR RED" << endl;

        cin >> opcion;

        switch (opcion) {
        case 'a':
        case 'A':
        {
            cout << endl;
            cout << "INFORMACION: " << endl;
            cout << "******* Usuario, ingrese 0 para terminar el proceso." << endl;
            sleep(2);

            bool exist = false;
            char c;

            vector<enrutador>::iterator it;
            while (true)
            {
                exist = false;

                cout << endl;
                cout << "Ingrese el nombre del enrutador: " << endl;
                cin >> c;

                // terminamos el ciclo.
                if (c == '0') {
                    break;
                }

                it = r.getElement().begin();
                for (; it != r.getElement().end(); it++)
                {
                    if (c == it->getName())
                    {
                        exist = true;
                        cout << endl;
                        cout << "INFORMACION: " << endl;
                        cout << "******* Usuario, el nombre '" << c << "' ya esta siendo utilizado." << endl;
                        sleep(2);
                        break;
                    }
                }

                if (!exist) {
                    r.newElement(c); // creamos el elemento.
                }
            }
        }
            break;
        case 'b':
        case 'B':
        {
            char name;

            cout << endl;
            cout << "Ingrese el nombre del enrutador: " << endl;
            cin >> name;

            if (r.existElement(name))
            {
                r.deleteElement(r.getElement(name));
            }
            else
            {
                cout << endl;
                cout << "INFORMACION: " << endl;
                cout << "******* Usuario, el enrutador " << name << " no existe. *******" << endl;
                sleep(2);
            }
        }
            break;
        case 'c':
        case 'C':
            r.viewElements();
            sleep(2);
            break;
        case 'd':
        case 'D':
            r.viewPath();
            sleep(2);
            break;
        case 'e':
        case 'E':
        {
            char e[2] = {};
            int c = 0;

            if (!pedirEnrutadores(e))
            {
                continue;
            }

            cout << endl;
            cout << "Ingrese el costo de la relacion: " << endl;
            cin >> c;

            // validamos que el costo no sea menor que cero.
            if (c > 0)
            {
                enrutador a = r.getElement(e[0]);
                enrutador b = r.getElement(e[1]);

                a.setElement(e[1], c);
                b.setElement(e[0], c);

                // actualizamos los elementos en la red.
                r.updateElement(a);
                r.updateElement(b);

                // creamos la tabla de enretamiento.
                r.createTable();
            }
            else
            {
                cout << endl;
                cout << "INFORMACION: " << endl;
                cout << "******* Usuario, el costo no puede ser menor o igual a cero. *******" << endl;
                sleep(2);
            }
        }
            break;
        case 'f':
        case 'F':
        {
            char e[2] = {};
            if (!pedirEnrutadores(e))
            {
                continue; // Uno de los enrutadores ingresados no existe.
            }

            int resp = r.getCost(e[0], e[1]); // obtenemos el costo.

            if (resp == -1)
            {
                cout << endl;
                cout << "Usuario, los elementos " <<  e[0] << " y " << e[1] << " no estan relacionados." << endl;
                sleep(2);
            }
            else
            {
                cout << endl;
                cout << "El costo de enviar de " << e[0] << " a " << e[1] << " es: " << resp << endl;
                sleep(2);
            }
        }
            break;
        case 'g':
        case 'G':
        {

            char e[2] = {};

            if (!pedirEnrutadores(e))
            {
                continue;
            }

            string str = "";
            r.getBestPath(e[0], e[1], str); // obtenemos la mejor ruta.

            cout << endl;
            cout << "La mejor ruta para enviar un paquete de " << e[0] << " a " << e[1] << " es: " << str << endl;
            sleep(2);
        }
            break;
        case 'h':
        case 'H':
        {
            string f = "";
            cout << endl;
            cout << "Ingrese el nombre del archivo de guardado: " << endl;
            cin >> f;

            r.saveToFile(f);
            sleep(2);
        }
            break;
        case 'i':
        case 'I':
        {
            string f = "";
            cout << endl;
            cout << "Ingrese el nombre del archivo: " << endl;
            cin >> f;

            int re = r.loadFile(f);

            if (re == -1)
            {
                cout << endl;
                cout << "INFORMACION: " << endl;
                cout << "******* Usuario, ha ocurrido un error leyendo el archivo. *******" << endl;
                sleep(2);
            }
            else if (re == -2)
            {
                cout << endl;
                cout << "INFORMACION: " << endl;
                cout << "******* Usuario, no se ha podido abrir el archivo. *******" << endl;
                sleep(2);
            }
        }
            break;
        case 'j':
        case 'J':
        {
            char e[2] = {};

            if (!pedirEnrutadores(e))
            {
                continue;
            }

            enrutador a = r.getElement(e[0]);
            enrutador b = r.getElement(e[1]);

            if (!a.existRelation(e[1]))
            {
                cout << endl;
                cout << "INFORMACION: " << endl;
                cout << "******* Usuario, los enrutadores no estan relacionados. *******" << endl;
                sleep(2);
            }
            else
            {
                int c = 0;
                cout << endl;
                cout << "Ingrese el costo: " << endl;
                cin >> c;

                if (c <= 0)
                {
                    cout << endl;
                    cout << "INFORMACION: " << endl;
                    cout << "******* Usuario, el costo no puede ser menor o igual a cero. *******" << endl;
                    sleep(2);
                }
                else
                {
                    a.updateCost(c, e[1]);
                    b.updateCost(c, e[0]);

                    // actualizamos los elementos en la red.
                    r.updateElement(a);
                    r.updateElement(b);

                    r.createTable();
                }
            }
        }
            break;
        case 'k':
        case 'K':
            r.random();
            break;
        default:
            return 0;
        }
    }
    return 0;
}
