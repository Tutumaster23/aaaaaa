#pragma once

void logo();

int menuJuego();

void interfaz(int ronda, string jugadorActual, int puntajes[2], int dadosStock[2], int turno);

void interfazFinal(int puntajes[2], string nombres[2], int& maximoPuntaje, string& maximoNombre);

void creditos();

void estadisticas(int& maximoPuntaje, string& maximoNombre);

int confirmar ();

