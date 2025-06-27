#include <iostream>

using namespace std;

int generarDado6() {
    return rand() % 6 + 1;
}

int generarDado12() {
    return rand() % 12 + 1;
}

void cargarDados6(int dados[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        dados[i] = generarDado6();
    }
}

void cargarDados12(int dados[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        dados[i] = generarDado12();
    }
}

void mostrarDados(int dados[], int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "[" << dados[i] << "] ";
    }
    cout << endl;

}

