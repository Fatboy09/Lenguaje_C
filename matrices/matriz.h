#ifndef MATRIZ_H
#define MATRIZ_H

typedef int typedata;

typedef struct MATRIX {
    int rows;
    int columns;
    typedata* m;
} MATRIX;

typedef struct MATRIX_F {
    int rows;
    int columns;
    double* m;
} MATRIX_F;

typedef MATRIX* matrix;
typedef MATRIX_F* matrix_f;

typedata* reservar_memoria(const int rows, const int columns);
void crear_matriz(matrix* m,const int rows, const int columns);
void crear_matrizFloat(matrix_f* m, const int rows, const int columns);
matrix_f matrizInt_to_matrizFloat(matrix m);
matrix sumar_matrices(matrix m1, matrix m2);
matrix_f sumar_matricesFloat(matrix_f m1, matrix_f m2);
matrix restar_matrices(matrix m1, matrix m2);
matrix_f restar_matricesFloat(matrix_f m1, matrix_f m2);
matrix producto_escalar(matrix m, const int k);
matrix_f producto_escalarFloat(matrix m, const double k);
matrix producto_matrices(matrix m1, matrix m2);
matrix_f producto_matricesFloat(matrix_f m1, matrix_f m2);
matrix transpuesta(matrix m);
matrix matriz_identidad(const int orden);
matrix matriz_adjunta(matrix m);
matrix_f matriz_inversa(matrix m);
typedata determinante(matrix m);
int rango(matrix m);
void print_matriz(matrix m);
void print_matrizFloat(matrix_f m);
void inicializar_matriz(matrix* m);
void fill_matriz(matrix* m,const int lo, const int hi);
void fill_matriz_input(matrix* m);
void mostrar_resultado(matrix* m, const char* str);
void mostrar_resultadoFloat(matrix_f* m, const char* str);
int is_squareMatrix(matrix m);
void remove_matrix(matrix* m);
void remove_matrixFloat(matrix_f* m);
#endif //MATRIZ H
