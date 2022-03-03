#ifndef GATO_HEADER
#define GATO_HEADER

#define TRUE 1
#define FALSE 0

typedef struct jugador
{
    char nombre[21];
    char simbolo;
    char tiros[6];
    int n_victorias;
    int n_derrotas;
    int n_empates;
}jugador;

void inicializar_jugadores(jugador* j1, jugador* j2);
void comenzar_partida(char* tabla, jugador* j1, jugador* j2, int* casillas, const int _size);
void print_tabla(char* tabla);
void limpiar_buffer(void);
int validar_tiro(int pos, int* casillas, const int _size);
int validar_ganador(char* casillas_J);
void show_menu(jugador j1, jugador j2, char* tabla, int* casillas, const int size);

#endif //GATO_HEADER
