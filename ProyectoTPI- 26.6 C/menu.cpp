#include <iostream>
#include <cstdlib>
#include "rlutil.h"
#include "juego.h"

using namespace std;

void logo(){
 rlutil::locate(10,2);cout <<" _______  __    _  _______  ______    _______  __    _  ______   _______  ______   _______  _______ "<<endl;
 rlutil::locate(10,3);cout <<"|       ||  |  | ||       ||    _ |  |       ||  |  | ||      | |   _   ||      | |       ||       |"<<endl;
 rlutil::locate(10,4);cout <<"|    ___||   |_| ||    ___||   | ||  |    ___||   |_| ||  _    ||  |_|  ||  _    ||   _   ||  _____|"<<endl;
 rlutil::locate(10,5);cout <<"|   |___ |       ||   |___ |   |_||_ |   |___ |       || | |   ||       || | |   ||  | |  || |_____ "<<endl;
 rlutil::locate(10,6);cout <<"|    ___||  _    ||    ___||    __  ||    ___||  _    || |_|   ||       || |_|   ||  |_|  ||_____  |"<<endl;
 rlutil::locate(10,7);cout <<"|   |___ | | |   ||   |    |   |  | ||   |___ | | |   ||       ||   _   ||       ||       | _____| |"<<endl;
 rlutil::locate(10,8);cout <<"|_______||_|  |__||___|    |___|  |_||_______||_|  |__||______| |__| |__||______| |_______||_______|"<<endl;
}

int menuJuego(){
    int menu;
    system("cls");
    logo();
    rlutil::locate(40,12);cout << "-------| MENU PRINCIPAL |-------" <<endl;
    rlutil::locate(40,13);cout << "==     1. JUGAR               ==" <<endl;
    rlutil::locate(40,14);cout << "==     2. ESTADISTICAS        ==" <<endl;
    rlutil::locate(40,15);cout << "==     3. CREDITOS            ==" <<endl;
    rlutil::locate(40,16);cout << "==     0. SALIR DEL PROGRAMA  ==" <<endl;
    rlutil::locate(40,17);cout << "-------| ------------- |--------" <<endl;
    rlutil::locate(55,20);cin >> menu;
    system("cls");

    return menu;
}

void interfaz(int ronda, string jugadorActual, int puntajes[2], int dadosStock[2], int turno){
    cout << "==========================" << endl;
    cout << "RONDA #" << ronda << " - TURNO DE: " << jugadorActual << endl;
    cout << "--------------------------" << endl;
    cout << "Puntaje actual: " << puntajes[turno] << " puntos" << endl;
    cout << "Dados stock disponibles: " << dadosStock[turno] << endl;
    cout << "==========================" << endl;
    cout << endl;
}

void interfazFinal(int puntajes[2], string nombres[2], int& maximoPuntaje, string& maximoNombre) {
    system("cls");
    cout << "==========================" << endl;
    cout << "       FIN DEL JUEGO      " << endl;
    cout << "==========================" << endl;
    cout << " Puntajes finales:        " << endl;
    cout << "--------------------------" << endl;
    cout << " " << nombres[0] << ": " << puntajes[0] << " puntos" << endl;
    cout << " " << nombres[1] << ": " << puntajes[1] << " puntos" << endl;
    cout << "--------------------------" << endl;

    if (puntajes[0] > puntajes[1]) {
        cout << " GANADOR: " << nombres[0] << endl;
        if (puntajes[0] > maximoPuntaje) {
            maximoPuntaje = puntajes[0];
            maximoNombre = nombres[0];
        }
    } else if (puntajes[1] > puntajes[0]) {
        cout << " GANADOR: " << nombres[1] << endl;
        if (puntajes[1] > maximoPuntaje) {
            maximoPuntaje = puntajes[1];
            maximoNombre = nombres[1];
        }
    } else {
        cout << " EMPATE ENTRE AMBOS JUGADORES!" << endl;
        if (puntajes[0] > maximoPuntaje) {
            maximoPuntaje = puntajes[0];
            maximoNombre = "Empate entre " + nombres[0] + " y " + nombres[1];
        }
    }

    cout << "==========================" << endl;
    cout << endl;
}

void creditos(){
    rlutil::locate(40,2); cout << "----------| CREDITOS |-----------" << endl;
    rlutil::locate(40,4); cout << "============EQUIPO 21============" << endl;
    rlutil::locate(40,5); cout << "==                             ==" <<endl;
    rlutil::locate(40,6); cout << "==  Renato Canavesi, 28592     ==" <<endl;
    rlutil::locate(40,7); cout << "==  Francisco Cristiani, 32383 ==" << endl;
    rlutil::locate(40,8); cout << "==                             ==" <<endl;
    rlutil::locate(40,9); cout << "=================================" << endl;
    rlutil::locate(40,11);cout << "----------| -------- |----------" << endl;

    rlutil::locate(40,25);
    system ("pause");
    system ("cls");
}

void estadisticas(int& maximoPuntaje, string& maximoNombre){
    rlutil::locate(40,6);
    if (maximoNombre == "") {
        cout << "No hay estadisticas actualmente..." << endl;
    } else {
        cout << "Maximo puntaje: " << maximoNombre << " con " << maximoPuntaje << " puntos" << endl;
    }
    rlutil::locate(40,25);
    system("pause");
}

int confirmar (){
    string confirmacion;
    rlutil::locate(50,6); cout << "Desea Salir?"<< endl;
    rlutil::locate(50,8); cout << "   (Y/N)    " << endl;
    while (true){
        rlutil::locate(55,9);
        cin >> confirmacion;
        if (confirmacion == "Y" || confirmacion == "y"){
        exit (0);
            } else if (confirmacion == "N" || confirmacion == "n"){
                return 0;
                } else {
                    rlutil::locate(40,10); cout << "Caracter Invalido. Ingrese 'Y' o 'N' " << endl;
                    }
    }
}
