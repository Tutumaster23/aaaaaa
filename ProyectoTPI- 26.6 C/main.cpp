#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

#include "menu.h"
#include "juego.h"
#include "dados.h"
#include "rlutil.h"

int main() {
    srand(time(0));
    int menu;
    int maximoPuntaje = 0;
    string maximoNombre = "";

    while (true) {
        menu = menuJuego();
        switch(menu) {
            case 1:
                comenzarJuego(maximoPuntaje, maximoNombre);
                break;
            case 2:
                estadisticas(maximoPuntaje, maximoNombre);
                break;
            case 3:
                creditos();
                break;
            case 0:
                confirmar();
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                system("pause");
        }
    }
    rlutil::hidecursor();
    return 0;
}
