#ifndef PIEZA_H
#define PIEZA_H

#include <string>
using namespace std;

class Pieza {
private:
    bool esDama;
    int jugador;
    string simbolo;

public:
    Pieza(int jugador);
    bool getEsDama() const;
    int getJugador() const;
    string getSimbolo() const;
    void coronar();
};

#endif
