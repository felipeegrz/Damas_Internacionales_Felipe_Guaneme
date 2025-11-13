#include "../Planteo/Tablero.h"
#include <iomanip>

Tablero::Tablero() {
    inicializar();
}

Tablero::~Tablero() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            delete casillas[i][j];
}

void Tablero::inicializar() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            casillas[i][j] = nullptr;
        }
    }

    // Jugador numero 1 (x)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 2 != 0)
                casillas[i][j] = new Pieza(1);
        }
    }

    // Jugador  numero 2 (o)
    for (int i = 6; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if ((i + j) % 2 != 0)
                casillas[i][j] = new Pieza(2);
        }
    }
}

void Tablero::mostrar() {
    cout << "\n     A  B  C  D  E  F  G  H  I  J\n";
    cout << "   ----------------------------------\n";
    for (int i = 0; i < 10; i++) {
        cout << " " << (10 - i) << " | ";
        for (int j = 0; j < 10; j++) {
            if (casillas[i][j] == nullptr)
                cout << ((i + j) % 2 == 0 ? "." : "_") << "  ";
            else {
                if (casillas[i][j]->getJugador() == 1)
                    cout << "\033[31m" << casillas[i][j]->getSimbolo() << "\033[0m  "; // rojo
                else
                    cout << "\033[34m" << casillas[i][j]->getSimbolo() << "\033[0m  "; // azul
            }
        }
        cout << "| " << (10 - i) << "\n";
    }
    cout << "   ----------------------------------\n";
    cout << "     A  B  C  D  E  F  G  H  I  J\n";
}

bool Tablero::moverPieza(int filaOrigen, int colOrigen, int filaDestino, int colDestino, int turno) {
    if (filaOrigen < 0 || filaOrigen >= 10 || colOrigen < 0 || colOrigen >= 10 ||
        filaDestino < 0 || filaDestino >= 10 || colDestino < 0 || colDestino >= 10)
        return false;

    Pieza* pieza = casillas[filaOrigen][colOrigen];
    if (pieza == nullptr || pieza->getJugador() != turno)
        return false;

    if (casillas[filaDestino][colDestino] != nullptr)
        return false;

    int diffFila = filaDestino - filaOrigen;
    int diffCol = colDestino - colOrigen;

    // Movimiento simple
    if (abs(diffFila) == 1 && abs(diffCol) == 1)
        casillas[filaDestino][colDestino] = pieza, casillas[filaOrigen][colOrigen] = nullptr;

    // Para capturar la pieza
    else if (abs(diffFila) == 2 && abs(diffCol) == 2) {
        int midFila = (filaOrigen + filaDestino) / 2;
        int midCol = (colOrigen + colDestino) / 2;
        Pieza* inter = casillas[midFila][midCol];

        if (inter && inter->getJugador() != turno) {
            delete inter;
            casillas[midFila][midCol] = nullptr;
            casillas[filaDestino][colDestino] = pieza;
            casillas[filaOrigen][colOrigen] = nullptr;
        } else return false;
    } else return false;

    if (turno == 1 && filaDestino == 9)
        pieza->coronar();
    if (turno == 2 && filaDestino == 0)
        pieza->coronar();

    return true;
}

int Tablero::contarPiezas(int jugador) {
    int c = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (casillas[i][j] && casillas[i][j]->getJugador() == jugador)
                c++;
    return c;
}

bool Tablero::hayMovimientos(int jugador) {
    return contarPiezas(jugador) > 0;
}
