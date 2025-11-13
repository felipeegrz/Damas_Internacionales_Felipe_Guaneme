#include "../Planteo/Pieza.h"

Pieza::Pieza(int jugador) {
    this->jugador = jugador;
    this->esDama = false;
    this->simbolo = (jugador == 1) ? "x" : "o";
}

bool Pieza::getEsDama() const {
    return esDama;
}

int Pieza::getJugador() const {
    return jugador;
}

string Pieza::getSimbolo() const {
    return simbolo;
}

void Pieza::coronar() {
    esDama = true;
    simbolo = (jugador == 1) ? "X" : "O";
}
