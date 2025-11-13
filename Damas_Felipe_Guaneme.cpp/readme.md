Innovaciones o Cosas a Destacar del Proyecto:
*POO: 
¿Para que se implementó?
Para lograr organizar el codigo en modulos independientes como lo pedia el docente y adicional a ello, el poder facilitar la comprension del programa.
¿Por qué se consideró necesario? 
Esto ya que el docente pidio todo separado y organizado mediante modulos, siendo asi mas facil programar todo mediante los dichos modulos
¿Cómo se llevó a cabo?
Pieza: define el color y tipo de cada ficha.
Tablero: administra las posiciones de las piezas, el estado del juego y las validaciones.
Juego: controla los turnos, el menú y la interacción con los jugadores.
Y cada modulo esta concatenado entre si.

Validaciones y manejo de errores
¿Para qué se implementó?
Para garantizar que las reglas del juego se cumplan y evitar movimientos inválidos.
¿Por qué se consideró necesario?
Las damas tienen reglas específicas que deben respetarse para mantener la coherencia del juego.
¿Cómo se llevó a cabo su implementación?
Se incluyeron comprobaciones para:
Evitar movimientos fuera del tablero.
Impedir mover piezas del oponente.
Validar que las casillas destino estén vacías.
Controlar las capturas y movimientos diagonales.
Si se detecta un movimiento inválido, se muestra un mensaje claro al jugador.

validarMovimiento() y detección automática de capturas
¿Para qué se implementó?

Para que el sistema pueda verificar, antes de mover una pieza, si el movimiento cumple con las reglas del juego.
¿Por qué se consideró necesario?
En la mayoría de proyectos estudiantiles de damas, los movimientos se controlan de forma manual (solo verifican si la casilla destino está vacía).
¿Cómo se llevó a cabo su implementación?
Se implementó dentro de la clase Tablero
Esto es para verificar si la jugada es legal o que detecte, cuando un movimiento no es valido dentro de las reglas que se establecio en el juego.

Sistema de Turnos automaticos 
¿Para qué se implementó?
Para automatizar el cambio de jugador después de cada movimiento válido, haciendo el juego más fluido y evitando confusiones o errores manuales.
¿Por qué se consideró necesario?
Porque en versiones básicas los turnos se cambian manualmente, lo que puede romper la secuencia del juego. Este sistema garantiza orden, coherencia y mejor experiencia.
¿Cómo se llevó a cabo su implementación?
Se creó una variable turnoActual dentro de la clase Juego, que alterna entre 'B' y 'N'