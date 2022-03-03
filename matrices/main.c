#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "matriz.h"
#include "stermp.h"

void print_title() {
    printf("\n\t---------------------------------------");
    printf("\n\t|\tCalculadora de Matrices\t      |");
    printf("\n\t---------------------------------------\n\n");
}

void user_input(int *rows, int *columns, const int i) {
    
    int n_inputs;
    
    while(1) {
        system("clear");
        printf("\nIngresa el numero de filas y columnas de la matriz %d. (Ej. 2 2): ", i + 1);
        n_inputs = scanf("%d %d", &(*rows), &(*columns));
        if(n_inputs == 2) {
            if(*rows > 0 && *columns > 0)
                break;
            printf("Error. Datos de entrada invalidos. Deben ser enteros positivos. Intentelo denuevo. Presione ENTER para continuar...");
        } else 
            printf("Error. Sus datos de entrada son invalidos. Deben ser de tipo numerico entero. Intentalo denuevo. Presione ENTER para continuar...");
        clear_buffer();
        getchar();
    }
}

void menu(matrix* arr) {
    
    int opc;
    int rows, columns, det;
    int k, n_inputs;
    matrix res = NULL;
    matrix_f res_f = NULL;
    
    rows = columns = 0;
    
    do {
        system("clear");
        print_title();
        printf("\t    1. Suma y Resta de Matrices\n");
        printf("\t    2. Producto entre matrices (A * B)\n");
        printf("\t    3. Producto por un escalar (k * A)\n");
        printf("\t    4. Transpuesta\n");
        printf("\t    5. Determinante de una Matriz\n");
        printf("\t    6. Matriz Adjunta\n");
        printf("\t    7. Matriz Inversa\n");
        printf("\t    8. Matriz Identidad\n");
        printf("\t    9. Rango de una Matriz\n");
        printf("\t   10. Salir\n");
        
        printf("\nIngrese una opcion del menu: ");
        //opc = getc(stdin);
        n_inputs = scanf("%d",&opc);
        if(n_inputs != 1)
            opc = -1;
        
        switch(opc) {
            case 1:
                for(int i = 0; i < 2; ++i) {
                    user_input(&rows,&columns,i);
                    crear_matriz(&arr[i],rows,columns);
                    printf("Matriz %d:\n\n",i + 1);
                    fill_matriz_input(&arr[i]);
                }
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                printf("Matriz B:\n");
                print_matriz(arr[1]);
                res = sumar_matrices(arr[0],arr[1]);
                mostrar_resultado(&res,"A + B");
                res = restar_matrices(arr[0],arr[1]);
                mostrar_resultado(&res,"A - B");
                
                for(int i = 0; i < 2; ++i)
                    remove_matrix(&arr[i]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 2:
                for(int i = 0; i < 2; ++i) {
                    user_input(&rows,&columns,i);
                    crear_matriz(&arr[i],rows,columns);
                    printf("Matriz %d:\n\n",i + 1);
                    fill_matriz_input(&arr[i]);
                }
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                printf("Matriz B:\n");
                print_matriz(arr[1]);
                res = producto_matrices(arr[0],arr[1]);
                mostrar_resultado(&res,"A * B");
                
                for(int i = 0; i < 2; ++i)
                    remove_matrix(&arr[i]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 3:
                while(1) {
                    printf("\nIngrese un valor para k: ");
                    n_inputs = scanf("%d",&k);
                    if(n_inputs == 1)
                        break;
                    else 
                        printf("Error. Sus datos de entrada son invalidos. Deben ser de tipo numerico entero. Intentalo denuevo. Presione ENTER para continuar...");
                    clear_buffer();
                    getchar();
                }
                user_input(&rows,&columns,0);
                crear_matriz(&arr[0],rows,columns);
                printf("Matriz A:\n\n");
                fill_matriz_input(&arr[0]);
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                res = producto_escalar(arr[0],k);
                printf("%d ", k);
                mostrar_resultado(&res,"* A");
                
                remove_matrix(&arr[0]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 4:
                user_input(&rows,&columns,0);
                crear_matriz(&arr[0],rows,columns);
                printf("Matriz A:\n\n");
                fill_matriz_input(&arr[0]);
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                res = transpuesta(arr[0]);
                mostrar_resultado(&res,"Matriz transpuesta de A");
                
                remove_matrix(&arr[0]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 5:
                user_input(&rows,&columns,0);
                crear_matriz(&arr[0],rows,columns);
                printf("Matriz A:\n\n");
                fill_matriz_input(&arr[0]);
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                det = determinante(arr[0]);
                if(det != INT_MIN)
                    printf("Det(A): %d\n",det);
                
                remove_matrix(&arr[0]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 6:
                user_input(&rows,&columns,0);
                crear_matriz(&arr[0],rows,columns);
                printf("Matriz A:\n\n");
                fill_matriz_input(&arr[0]);
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                res = matriz_adjunta(arr[0]);
                mostrar_resultado(&res,"Adj(A)");
                
                remove_matrix(&arr[0]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 7:
                user_input(&rows,&columns,0);
                crear_matriz(&arr[0],rows,columns);
                printf("Matriz A:\n\n");
                fill_matriz_input(&arr[0]);
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                res_f = matriz_inversa(arr[0]);
                mostrar_resultadoFloat(&res_f,"Inv(A)");
                
                remove_matrix(&arr[0]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 8:
                while(1) {
                    printf("\nIngrese el orden de la matriz cuadrada: ");
                    n_inputs = scanf("%d",&k);
                    if(n_inputs == 1) {
                        if(k > 0)
                            break;
                        printf("Error. Dato de entrada invalido. Deben ser un entero positivo. Intentelo denuevo. Presione ENTER para continuar...");
                    }
                    else 
                        printf("Error. Sus datos de entrada son invalidos. Deben ser de tipo numerico entero. Intentalo denuevo. Presione ENTER para continuar...");
                    clear_buffer();
                    getchar();
                }
                printf("\nMatriz identidad de orden %d",k);
                res = matriz_identidad(k);
                mostrar_resultado(&res,"");
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 9:
                user_input(&rows,&columns,0);
                crear_matriz(&arr[0],rows,columns);
                printf("Matriz A:\n\n");
                fill_matriz_input(&arr[0]);
                system("clear");
                printf("\nMatriz A:\n");
                print_matriz(arr[0]);
                printf("Rango(A): %d\n",rango(arr[0]));

                remove_matrix(&arr[0]);
                
                printf("\nPresione ENTER para continuar...");
                clear_buffer();
                getchar();
                break;
            case 10:
                break;
            default:
                clear_buffer();
                printf("\nError. Opcion no valida, intenta denuevo. Presione ENTER para continuar...");
                getchar();
                break;
        }
        
        clear_buffer();
            
    } while(opc != 10);
}

int main() {
    matrix arr[2];
    
    for(int i = 0; i < (int)(sizeof(arr)/sizeof(arr[0])); ++i)
        arr[i] = NULL;
        
    menu(arr);
        
    return 0;
}

