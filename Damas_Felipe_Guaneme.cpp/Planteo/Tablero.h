#ifndef TABLERO_H
#define TABLERO_H

#include "Pieza.h"
#include <iostream>
#include <string>
using namespace std;

class Tablero {
private:
    Pieza* casillas[10][10];

public:
    Tablero();
    ~Tablero();
    void inicializar();
    void mostrar();
    bool moverPieza(int filaOrigen, int colOrigen, int filaDestino, int colDestino, int turno);
    bool hayMovimientos(int jugador);
    int contarPiezas(int jugador);
};

#endif
