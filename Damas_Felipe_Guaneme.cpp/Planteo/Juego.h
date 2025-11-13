#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include <string>
using namespace std;

class Juego {
private:
    Tablero tablero;
    string jugador1;
    string jugador2;
    int turnoActual;
    bool juegoActivo;

public:
    Juego();
    void mostrarMenu();
    void iniciar();
    void mostrarReglas();
    void jugar();
};

#endif
