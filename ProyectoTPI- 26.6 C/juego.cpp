#include <iostream>
#include <cstdlib>

#include "dados.h"
#include "juego.h"
#include "menu.h"

using namespace std;

void limpiarPantalla(){
    system("pause");
    system("cls");
}

void comenzarJuego(int& maximoPuntaje, string& maximoNombre) {
    string nombres[2];
    int puntajes[2];
    puntajes[0] = 0;
    puntajes[1] = 0;
    int dadosStock[2] = {6, 6};
    int puntosObtenidos = 0;
    int victoriaAutomatica = 0;

    quienComienza(nombres);

    for (int ronda = 1; ronda <= 3; ronda++) {
        for (int turno = 0; turno < 2; turno++) {
            puntosObtenidos = 0;
            string jugadorActual = nombres[turno];

            interfaz(ronda, jugadorActual, puntajes, dadosStock, turno);
            victoriaAutomatica =  tirar(jugadorActual, puntosObtenidos, dadosStock, turno);

            puntajes[turno] += puntosObtenidos;

            if (victoriaAutomatica == 1) {
                interfazFinal(puntajes ,nombres, maximoPuntaje, maximoNombre);
                system("pause");
                return;
            }
        }
    }

    interfazFinal(puntajes ,nombres, maximoPuntaje, maximoNombre);
    system("pause");
}

int tiradaInicial(string nombreJugador1,string nombreJugador2) {
        int Jugador1 = 0, Jugador2 = 0, JugadorP = 0;
        while(Jugador1 == Jugador2){
            int dados6[1];

            cout << "Dado de: "<< nombreJugador1 << endl;
            cargarDados6(dados6, 1);
            mostrarDados(dados6, 1);

            Jugador1 = dados6[0];

            system("pause");
            cout << endl;

            cout << "Dado de: "<< nombreJugador2 << endl;
            cargarDados6(dados6, 1);
            mostrarDados(dados6, 1);

            Jugador2 = dados6[0];

            limpiarPantalla();

            if (Jugador1 == Jugador2){
                cout << "Empate! Tirar de vuelta..." << endl;
                limpiarPantalla();
            }

        }

        if (Jugador1 > Jugador2){
            JugadorP = 1;
            cout << "Empieza " << nombreJugador1 << ": [" << Jugador1 << "]" << endl;
            cout << "Sigue " << nombreJugador2 << ": [" << Jugador2 << "]" << endl;
        } else {
            JugadorP = 2;
            cout << "Empieza " << nombreJugador2 << ": [" << Jugador2 << "]" << endl;
            cout << "Sigue " << nombreJugador1 << ": [" << Jugador1 << "]" << endl;
        }

        limpiarPantalla();
        return JugadorP;
}

void quienComienza(string nombres[2]) {
    string nombreJugador1, nombreJugador2;

    cout << "Nombre del Jugador 1: ";
    cin >> nombreJugador1;
    cout << "Nombre del Jugador 2: ";
    cin >> nombreJugador2;

    system("cls");

    int resultado = tiradaInicial(nombreJugador1, nombreJugador2);

    if (resultado == 1) {
        nombres[0] = nombreJugador1;
        nombres[1] = nombreJugador2;
    } else {
        nombres[0] = nombreJugador2;
        nombres[1] = nombreJugador1;
    }
}

int tirar(string jugadorActual, int& puntosObtenidos, int dadosStock[2], int turno) {
    cout << "Lanzamiento dados objetivo:" << endl;
    int dados12[2],suma12 = 0;
    cargarDados12(dados12, 2);
    mostrarDados(dados12, 2);
    for (int i = 0; i <= 1; i++){
        suma12 += dados12[i];
    }

    cout << endl;
    cout << "Numero objetivo: " << suma12 << endl;
    cout << endl;

    cout << "Lanzamiento dados stock:" << endl;
    int dados6[11];
    cargarDados6(dados6, dadosStock[turno]);
    mostrarDados(dados6, dadosStock[turno]);

    cout << endl << "Selecciona los dados stock por su posicion (1 a " << dadosStock[turno] << "), 0 para cerrar la suma:" << endl;

    int dados6suma = 0;
    bool dados6usados[11] = {false};
    int seleccion;
    int cont = 0;

    while (dados6suma != suma12) {
        cin >> seleccion;

        if (seleccion == 0) break;

        if (seleccion >= 1 && seleccion <= dadosStock[turno]) {
            int indice = seleccion - 1;

            if (!dados6usados[indice]) {
                dados6usados[indice] = true;
                dados6suma += dados6[indice];
                cont++;

                cout << "Dado usado: " << dados6[indice] << " | Suma actual: " << dados6suma << endl;

                if (cont == dadosStock[turno] && dados6suma == suma12) {
                    cout << "Usaste todos los dados!! " << jugadorActual << " Gano!!" << endl;
                    puntosObtenidos += 10000;
                    limpiarPantalla();
                    return 1;
                }

            } else {
                cout << "Ese dado ya fue usado." << endl;
            }

        } else {
            cout << "Posicion invalida. Ingrese un numero entre 1 y " << dadosStock[turno] << "." << endl;
        }
    }

    cout << endl;
    cout << "=========================="<<endl;

    int oponente;
    if (turno == 0) {
        oponente = 1;
    } else {
        oponente = 0;
    }

    if (dados6suma == suma12) {
        cout << "Tirada exitosa!" << endl;
        int puntaje = cont*suma12;
        puntosObtenidos += puntaje;

        dadosStock[turno] -= cont;
        dadosStock[oponente] += cont;

        cout << "Puntaje obtenido esta ronda: " << puntaje << endl;
        cout << "Dados stock enviados al oponente: "<< cont << endl;

    } else {
        cout << "No igualaste el numero objetivo!" << endl;
        if (dadosStock[oponente] > 1) {
        dadosStock[turno] += 1;
        dadosStock[oponente] -= 1;
        cout << jugadorActual << " recibe 1 dado del oponente." << endl;
        } else {
        cout << "El oponente solo tiene 1 dado, por ende no se transfiere dado." << endl;
        }
    }
    cout << "==========================" << endl;


    limpiarPantalla();
    return 0;
}
