#include "../Planteo/Juego.h"
#include <iostream>
#include <limits>
using namespace std;

Juego::Juego() {
    turnoActual = 1;
    juegoActivo = true;
}

void Juego::mostrarMenu() {
    int opcion;
    do {
        cout << "\n==============================\n";
        cout << "   Damas Juego Por Felipe Guaneme\n";
        cout << "==============================\n";
        cout << "1. Iniciar partida\n";
        cout << "2. Ver reglas\n";
        cout << "3. Salir\n";
        cout << "==============================\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            iniciar();
            break;
        case 2:
            mostrarReglas();
            break;
        case 3:
            cout << "Gracias Por Jugar, Juego Hecho Por Felipe Guaneme💡\n";
            juegoActivo = false;
            break;
        default:
            cout << "Opcion no valida.\n";
        }
    } while (juegoActivo);
}

void Juego::mostrarReglas() {
    cout << "\n=== REGLAS BASICAS ===\n";
    cout << "- Movimiento diagonal hacia adelante.\n";
    cout << "- Captura obligatoria cuando sea posible.\n";
    cout << "- Una pieza que llega al extremo contrario se convierte en Dama.\n";
    cout << "- Gana quien capture todas las piezas del rival o deje sin movimientos al oponente.\n";
}

void Juego::iniciar() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpia el bufer

    cout << "\nIngrese el nombre del Jugador 1 (x): ";
    getline(cin, jugador1);
    cout << "Ingrese el nombre del Jugador 2 (o): ";
    getline(cin, jugador2);

    cout << "\n¡Bienvenidos " << jugador1 << " y " << jugador2 << "!\n";
    jugar();
}

void Juego::jugar() {
    while (true) {
        tablero.mostrar();
        cout << "\nTurno de ";
        if (turnoActual == 1)
            cout << "\033[31m" << jugador1 << "\033[0m (x)\n";
        else
            cout << "\033[34m" << jugador2 << "\033[0m (o)\n";

        cout << "Ingrese movimiento (ejemplo: B6 C5): ";

        string origen, destino;
        cin >> origen >> destino;

        if (origen.size() != 2 || destino.size() != 2) {
            cout << "Formato inválido.\n";
            continue;
        }

        int colO = toupper(origen[0]) - 'A';
        int filaO = 10 - (origen[1] - '0');
        int colD = toupper(destino[0]) - 'A';
        int filaD = 10 - (destino[1] - '0');

        if (!tablero.moverPieza(filaO, colO, filaD, colD, turnoActual)) {
            cout << "Movimiento inválido. Intente de nuevo.\n";
            continue;
        }

        if (tablero.contarPiezas(1) == 0) {
            cout << "\n¡\033[34m" << jugador2 << "\033[0m ha ganado!\n";
            break;
        } else if (tablero.contarPiezas(2) == 0) {
            cout << "\n¡\033[31m" << jugador1 << "\033[0m ha ganado!\n";
            break;
        }

        turnoActual = (turnoActual == 1) ? 2 : 1;
    }
}
