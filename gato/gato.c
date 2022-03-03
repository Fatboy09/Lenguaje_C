#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "gato.h"

char lines[8][4] = {
    {'0','1','2','\0'},
    {'0','3','6','\0'},
    {'0','4','8','\0'},
    {'1','4','7','\0'},
    {'2','5','8','\0'},
    {'3','4','5','\0'},
    {'6','7','8','\0'},
    {'2','4','6','\0'}
};

void limpiar_buffer() {
    int fdflags;
    fdflags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, fdflags | O_NONBLOCK);
    while (getchar()!=EOF);
    fcntl(STDIN_FILENO, F_SETFL, fdflags);
}

void inicializar_jugadores(jugador* j1, jugador* j2) {
    /*printf("Nombre del jugador 1: ");
    fgets(j1->nombre,sizeof(j1->nombre),stdin);
    printf("Nombre del jugador 2: ");
    fgets(j2->nombre,sizeof(j2->nombre),stdin);*/
    j1->n_derrotas = j1->n_empates = j1->n_victorias = 0;
    j2->n_derrotas = j2->n_empates = j2->n_victorias = 0;
    j1->simbolo = 'X';
    j2->simbolo = 'O';
    memset(j1->tiros,'\0',sizeof(j1->tiros));
    memset(j2->tiros,'\0',sizeof(j2->tiros));
    //printf("inicializando\n");
}

void print_tabla(char* tabla) {
    /*printf("\n\t 0 | 1 | 2\tInstrucciones:");
    printf("\n\t---+---+---");
    printf("\n\t 3 | 4 | 5\t 1. Para escribir su simbolo en el recuadro debera ingresar");
    printf("\n\t---+---+---\t    la posicion correspondiente a dicha casilla");
    printf("\n\t 6 | 7 | 8");
    printf("\n===================================================================================");*/
    printf("\n\t %1c | %1c | %1c",tabla[0],tabla[1],tabla[2]);
    printf("\n\t---+---+---");
    printf("\n\t %1c | %1c | %1c",tabla[3],tabla[4],tabla[5]);
    printf("\n\t---+---+---");
    printf("\n\t %1c | %1c | %1c\n",tabla[6],tabla[7],tabla[8]);
}

int validar_tiro(int pos, int* casillas,const int _size) {
    int flag = FALSE;
    
    if(!(pos < 0 || pos > (_size - 1))) {
        if(casillas[pos] == 0) {
            casillas[pos] = 1;
            flag = TRUE;
        }
    }
    
    return flag;
}

int buscar_linea_ganadora(char* lines, char* casillas_J) {
    int cont = 0;
    int flag = FALSE;
    char* aux = lines;
    while (*aux != '\0') {
        if(strchr(casillas_J,*aux) != NULL) {
            cont++;
        }
        aux++;
    }
    if(cont == 3)
        flag = TRUE;
    return flag;
}

int validar_ganador(char* casillas_J) {
    int flag = FALSE;
    if(strlen(casillas_J) >= 3) {
        for(int i = 0; i < 8; ++i) {
            if(buscar_linea_ganadora(lines[i],casillas_J)) {
                flag = TRUE;
                break;
            }
        }
    }
    return flag;
}

void agregar_tiro(char* tiro, int pos) {
    for(int i = 0; i < 5; ++i) {
        if(tiro[i] == '\0') {
            tiro[i] = pos + 48;
            break;
        }
    }
}

void sumar_victoria(jugador* player) {
    player->n_victorias += 1;
}

void sumar_derrota(jugador* player) {
    player->n_derrotas += 1;
}

void sumar_empate(jugador* player) {
    player->n_empates += 1;
}

void clear_casillas(int* casillas,const int size) {
    for(int i = 0; i < size; ++i)
        casillas[i] = 0;
}

void clear_tabla(char* tabla) {
    for(int i = 0; i < 9; ++i)
        tabla[i] = ' ';
}

void clear_tiros(char* tiros) {
    for(int i = 0; i < 5; ++i)
        tiros[i] = '\0';
}

void comenzar_partida(char* tabla, jugador* j1, jugador* j2, int* casillas, const int _size) {
    int winner_flag = FALSE;
    const int mov_max = 9;
    int contador = 0;
    int idx;
    int winner[2] = {0,0};

    while(!winner_flag && contador != mov_max) {
        system("clear");
        ++contador;
        printf("\t-- TIC TAC TOE --\n");
        print_tabla(tabla);
        if(contador % 2 == 0) {
            while(TRUE) {
                printf("\n\tTurno del jugador(a) %s\n\n",j2->nombre);
                printf("Ingrese una posicion [0-8]: ");
                scanf("%d",&idx);
                limpiar_buffer();
                if(!validar_tiro(idx,casillas,_size)) {
                    if(idx < 0 || idx > 8)
                        fprintf(stderr,"Error. Esta posicion es invalida, intentalo de nuevo.\n");
                    else
                        fprintf(stderr,"Error. Esta casilla ya esta ocupada, intentalo de nuevo.\n");
                    printf("Presione ENTER para continuar...");
                    getchar();
                    system("clear");
                    printf("\t-- TIC TAC TOE --\n");
                    print_tabla(tabla);
                } else {
                    tabla[idx] = j2->simbolo;
                    agregar_tiro(j2->tiros,idx);
                    if(validar_ganador(j2->tiros)) {
                        winner_flag = TRUE;
                        winner[1] = 1;
                    }
                    break;
                }
            }
        } else {
            while(TRUE) {
                printf("\n\tTurno del jugador(a) %s\n\n",j1->nombre);
                printf("Ingrese una posicion [0-8]: ");
                scanf("%d",&idx);
                limpiar_buffer();
                if(!validar_tiro(idx,casillas,_size)) {
                    if(idx < 0 || idx > 8)
                        fprintf(stderr,"Error. Esta posicion es invalida, intentalo de nuevo.\n");
                    else
                        fprintf(stderr,"Error. Esta casilla ya esta ocupada, intentalo de nuevo.\n");
                    printf("Presione ENTER para continuar...");
                    getchar();
                    system("clear");
                    printf("\t-- TIC TAC TOE --\n");
                    print_tabla(tabla);
                } else {
                    tabla[idx] = j1->simbolo;
                    agregar_tiro(j1->tiros,idx);
                    if(validar_ganador(j1->tiros)) {
                        winner_flag = TRUE;
                        winner[0] = 1;
                    }
                    break;
                }
            }
        }
    }
    system("clear");
    printf("\t-- TIC TAC TOE --\n");
    print_tabla(tabla);
    if(contador == 9) {
        if(validar_ganador(j1->tiros)) {
            sumar_victoria(j1);
            sumar_derrota(j2);
            printf("\nEl ganador(a) de la partida es: %s\n",j1->nombre);
        } else {
            printf("\n\t    [GATO]\n");
            sumar_empate(j1);
            sumar_empate(j2);
        }
    } else {
        if(winner[0]) {
            sumar_victoria(j1);
            sumar_derrota(j2);
            printf("\nEl ganador(a) de la partida es: %s\n",j1->nombre);
        }
        else {
            sumar_victoria(j2);
            sumar_derrota(j1);
            printf("\nEl ganador(a) de la partida es: %s\n",j2->nombre);
        }
    }
}

void print_name_wth_spaces(char* name, int n_spc) {
    printf(" %s",name);
    for(int i = 0; i < n_spc; ++i)
        printf(" ");
}

void show_menu(jugador j1, jugador j2, char* tabla, int* casillas, const int size) {
    char opc;
    do {
        system("clear");
        printf("\t-- TIC TAC TOE --\n\n");
        printf("\t-- M e n u --\n\n");
        printf("1. Instrucciones del juego\n");
        printf("2. Comenzar nueva partida\n");
        printf("3. Ver tabla de puntuacion\n");
        printf("4. Salir del juego\n");
        printf("\nIngrese una opcion del menu: ");
        limpiar_buffer();
        opc = getc(stdin);
        switch (opc) {
        case '1':
            printf("\n\t 0 | 1 | 2\tInstrucciones:");
            printf("\n\t---+---+---");
            printf("\n\t 3 | 4 | 5\t 1. Para escribir su simbolo en el recuadro debera ingresar");
            printf("\n\t---+---+---\t    la posicion correspondiente a dicha casilla");
            printf("\n\t 6 | 7 | 8");
            printf("\n\nPresione ENTER para continuar...");
            limpiar_buffer();
            getchar();
            break;
        case '2':
            inicializar_jugadores(&j1,&j2);
            do {
                comenzar_partida(tabla,&j1,&j2,casillas,size);
                clear_casillas(casillas,size);
                clear_tabla(tabla);
                clear_tiros(j1.tiros);
                clear_tiros(j2.tiros);
                printf("\nQuiere comenzar otra partida [Y/n]: ");
                limpiar_buffer();
                opc = getchar();
            } while((opc == 'Y') || (opc == 'y'));
            break;
        case '3':
            printf("\n\t -- Tabla de Puntuacion --\n\n");
            printf("  Player\t      JG\t JP\t JE\n");
            if(strlen(j1.nombre) > strlen(j2.nombre)) {
                print_name_wth_spaces(j1.nombre,20 - strlen(j1.nombre));
                printf("%3d\t%3d\t%3d\n",j1.n_victorias,j1.n_derrotas,j1.n_empates);
                print_name_wth_spaces(j2.nombre,20 - strlen(j2.nombre));
                printf("%3d\t%3d\t%3d\n",j2.n_victorias,j2.n_derrotas,j2.n_empates);
            } else if(strlen(j1.nombre) < strlen(j2.nombre)) {
                print_name_wth_spaces(j1.nombre,20 - strlen(j1.nombre));
                printf("%3d\t%3d\t%3d\n",j1.n_victorias,j1.n_derrotas,j1.n_empates);
                print_name_wth_spaces(j2.nombre, 20 - strlen(j2.nombre));
                printf("%3d\t%3d\t%3d\n",j2.n_victorias,j2.n_derrotas,j2.n_empates);
            } else {
                print_name_wth_spaces(j1.nombre,20 - strlen(j1.nombre));
                printf("%3d\t%3d\t%3d\n",j1.n_victorias,j1.n_derrotas,j1.n_empates);
                print_name_wth_spaces(j2.nombre,20 - strlen(j2.nombre));
                printf("%3d\t%3d\t%3d\n",j2.n_victorias,j2.n_derrotas,j2.n_empates);
            }
            printf("\n\nPresione ENTER para continuar...");
            limpiar_buffer();
            getchar();
            break;
        case '4':
            printf("Adios!!!\n");
            break;
        default:
            fprintf(stderr,"Error. Opcion no valida, intentalo de nuevo\n");
            printf("Presione ENTER para continuar...");
            limpiar_buffer();
            getchar();
            break;
        }
    } while(opc != '4');
}