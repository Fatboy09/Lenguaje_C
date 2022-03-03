#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gato.h"

int main() {

    jugador j1,j2;
    char tabla[9];
    int casillas[9];
    size_t size = sizeof(casillas)/sizeof(casillas[0]);

    memset(tabla,' ',sizeof(tabla));
    memset(casillas,0,sizeof(casillas));
    printf("\t-- TIC TAC TOE --\n\n");
    printf("Nombre del jugador 1: ");
    fgets(j1.nombre,sizeof(j1.nombre),stdin);
    j1.nombre[strcspn((j1.nombre),"\n")] = '\0';
    printf("Nombre del jugador 2: ");
    fgets(j2.nombre,sizeof(j2.nombre),stdin);
    j2.nombre[strcspn((j2.nombre),"\n")] = '\0';
    inicializar_jugadores(&j1,&j2);
    show_menu(j1,j2,tabla,casillas,size);

    return 0;
}