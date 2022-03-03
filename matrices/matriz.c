#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "matriz.h"
#include "stermp.h"

int between(const int lo, const int hi) {
    return lo + (rand() % (hi - lo));
}

typedata* reservar_memoria(const int rows, const int columns) {
    typedata* m = (typedata*) malloc(sizeof(typedata) * (size_t)(rows * columns));
    return m;
}

void crear_matriz(matrix* m, const int rows, const int columns) {

    matrix new_m = (matrix) malloc(sizeof(MATRIX));

    if(!new_m) {
        fprintf(stderr,"Error. No se reservo espacio en memoria\n");
        exit(EXIT_FAILURE);
    }
    new_m->m = reservar_memoria(rows,columns);
    new_m->rows = rows;
    new_m->columns = columns;
    
    *m = new_m;
}

void crear_matrizFloat(matrix_f* m, const int rows, const int columns) {
    
    matrix_f new_m = (matrix_f) malloc(sizeof(MATRIX_F));
    
    if(!new_m) {
        fprintf(stderr,"Error. No se reservo espacio en memoria\n");
        exit(EXIT_FAILURE);
    }
    
    new_m->m = (double*) malloc(sizeof(double) * (size_t) (rows * columns));
    new_m->rows = rows;
    new_m->columns = columns;
    
    *m = new_m;
}

matrix_f matrizInt_to_matrizFloat(matrix m) {
    matrix_f new_m = NULL;
    crear_matrizFloat(&new_m,m->rows,m->columns);
    
    for(int x = 0; x < (m->rows * m->columns); ++x)
        new_m->m[x] = (double) m->m[x];
    
    return new_m;
}

void inicializar_matriz(matrix* m) {
    for(int i = 0; i < ((*m)->rows * (*m)->columns); ++i)
        (*m)->m[i] = 0;
}

void inicializar_matrizFloat(matrix_f* m) {
    for(int i = 0; i < ((*m)->rows * (*m)->columns); ++i)
        (*m)->m[i] = 0.0;
}

void copy_matriz(matrix* m, matrix m2) {
    for(int i = 0; i < (m2->rows * m2->columns); ++i)
        (*m)->m[i] = m2->m[i];
}

void fill_matriz(matrix* m, const int lo, const int hi) {
    
    for(int x = 0; x < (*m)->rows; ++x) {
        for(int y = 0; y < (*m)->columns; ++y)
            (*m)->m[x * (*m)->columns + y] = between(lo,hi);
    }
    
}

void fill_matriz_input(matrix* m) {
    int data;
    int n;
    
    for(int x = 0; x < (*m)->rows; ++x) {
        for(int y = 0; y < (*m)->columns; ++y) {
            while(1) {
                //printf("Ingrese un dato para M[%d][%d]: ", x, y);
                gotoxy(y*5,x+5);
                n = scanf("%d",&data);
                if(n != 1) {
                    fprintf(stderr,"Error. Ingreso una dato no valido. Debe ser un valor numerico entero, intentelo de nuevo. Presione ENTER para continuar...");
                    clear_buffer();
                    getchar();
                } else 
                    break;
            }
            (*m)->m[x * (*m)->columns + y] = data;
        }
    }
}

int is_squareMatrix(matrix m) {
    return m->rows == m->columns;
}

matrix sumar_matrices(matrix m1, matrix m2) {
    
    if((m1->rows != m2->rows) || (m1->columns != m2->columns)) {
        fprintf(stderr,"ERROR. No se puede realizar la suma de matrices porque las matrices no son de la misma dimension\n\n");
        return NULL;
    }
    
    matrix m3 = NULL;
    crear_matriz(&m3,m1->rows,m1->columns);
    
    if(m3) {
        int idx;
        
        for(int x = 0; x < m3->rows; ++x) {
            for(int y = 0; y < m3->columns; ++y) {
                idx = x * m3->columns + y;
                m3->m[idx] = m1->m[idx] + m2->m[idx];
            }
        }
    }
    return m3;
}

matrix_f sumar_matricesFloat(matrix_f m1, matrix_f m2) {
    
    if((m1->rows != m2->rows) || (m1->columns != m2->columns)) {
        fprintf(stderr,"ERROR. No se puede realizar la suma de matrices porque las matrices no son de la misma dimension\n\n");
        return NULL;
    }
    
    matrix_f m3 = NULL;
    crear_matrizFloat(&m3,m1->rows,m1->columns);
    
    if(m3) {
        int idx;
        
        for(int x = 0; x < m3->rows; ++x) {
            for(int y = 0; y < m3->columns; ++y) {
                idx = x * m3->columns + y;
                m3->m[idx] = m1->m[idx] + m2->m[idx];
            }
        }
    }
    return m3;
}

matrix restar_matrices(matrix m1, matrix m2) {
    
    if((m1->rows != m2->rows) || (m1->columns != m2->columns)) {
        fprintf(stderr,"ERROR. No se puede realizar la resta de matrices porque las matrices no son de la misma dimension\n\n");
        return NULL;
    }
    
    matrix m3 = NULL;
    crear_matriz(&m3,m1->rows,m1->columns);
    
    if(m3) {
        int idx;
        
        for(int x = 0; x < m3->rows; ++x) {
            for(int y = 0; y < m3->columns; ++y) {
                idx = x * m3->columns + y;
                m3->m[idx] = m1->m[idx] - m2->m[idx];
            }
        }
    }
    return m3;
}

matrix_f restar_matricesFloat(matrix_f m1, matrix_f m2) {
    
    if((m1->rows != m2->rows) || (m1->columns != m2->columns)) {
        fprintf(stderr,"ERROR. No se puede realizar la resta de matrices porque las matrices no son de la misma dimension\n\n");
        return NULL;
    }
    
    matrix_f m3 = NULL;
    crear_matrizFloat(&m3,m1->rows,m1->columns);
    
    if(m3) {
        int idx;
        
        for(int x = 0; x < m3->rows; ++x) {
            for(int y = 0; y < m3->columns; ++y) {
                idx = x * m3->columns + y;
                m3->m[idx] = m1->m[idx] - m2->m[idx];
            }
        }
    }
    return m3;
}

matrix producto_escalar(matrix m, const int k) {
    matrix m2 = NULL;
    crear_matriz(&m2,m->rows,m->columns);
    
    if(m2) {
        int idx;
        
        for(int x = 0; x < m->rows; ++x) {
            for(int y = 0; y < m->columns; ++y) {
                idx = x * m->columns + y;
                m2->m[idx] = m->m[idx] * k; 
            }
        }
    }
    
    return m2;
}

matrix_f producto_escalarFloat(matrix m, const double k) {
    matrix_f m2 = NULL;
    crear_matrizFloat(&m2,m->rows,m->columns);
    
    if(m2) {
        int idx;
        
        for(int x = 0; x < m->rows; ++x) {
            for(int y = 0; y < m->columns; ++y) {
                idx = x * m->columns + y;
                m2->m[idx] = (double)m->m[idx] * k; 
            }
        }
    }
    
    return m2;
}

matrix producto_matrices(matrix m1, matrix m2) {
    
    matrix m3 = NULL;
    
    if(m1->columns != m2->rows) {
        fprintf(stderr, "Error. No se puede realizar la multiplicacion, no cumple con la condicion para realizar esta operacion.\n");
    } else {
        crear_matriz(&m3,m1->rows,m2->columns);
        int rows = m1->rows;
        int columns = m2->columns;
        
        if(m3) {
            inicializar_matriz(&m3);
            //print_matriz(m3);
            int idx;
            int iM1,iM2;
            for(int x = 0; x < rows; ++x) {
                for(int y = 0; y < columns; ++y) {
                    for(int z = 0; z < m2->rows; ++z) {
                        idx = x * columns + y;
                        iM1 = x * m2->rows + z;
                        iM2 = z * columns + y;
                        m3->m[idx] += (m1->m[iM1] * m2->m[iM2]);
                    }
                }
            }
        }
    }
    
    return m3;
}

matrix_f producto_matricesFloat(matrix_f m1, matrix_f m2) {
    matrix_f m3 = NULL;
    
    if(m1->columns != m2->rows) {
        fprintf(stderr, "Error. No se puede realizar la multiplicacion, no cumple con la condicion para realizar esta operacion.\n");
    } else {
        crear_matrizFloat(&m3,m1->rows,m2->columns);
        int rows = m1->rows;
        int columns = m2->columns;
        
        if(m3) {
            inicializar_matrizFloat(&m3);
            //print_matriz(m3);
            int idx;
            int iM1,iM2;
            for(int x = 0; x < rows; ++x) {
                for(int y = 0; y < columns; ++y) {
                    for(int z = 0; z < m2->rows; ++z) {
                        idx = x * columns + y;
                        iM1 = x * m2->rows + z;
                        iM2 = z * columns + y;
                        m3->m[idx] += (m1->m[iM1] * m2->m[iM2]);
                    }
                }
            }
        }
    }
    
    return m3;
}

matrix transpuesta(matrix m) {
    matrix t = NULL;
    
    crear_matriz(&t,m->columns,m->rows);
    
    if(t) {
        for(int x = 0; x < t->rows; ++x) {
            for(int y = 0; y < t->columns; ++y)
                t->m[x * t->columns + y] = m->m[y * t->rows + x];
        }    
    }
    
    return t;
}

void cofactores(typedata* m, typedata* subM, const int row, const int column, const int orden) {
    
    int i,j;
    i = j = 0;
    
    for(int x = 0; x < orden; ++x) {
        if(x == row)
            continue;
        for(int y = 0; y < orden; ++y) {
            if(y == column)
                continue;
            subM[i * (orden - 1) + j] = m[x * orden + y];
            j++;
            if(j >= (orden -1)) {
                i++;
                j = 0;
            }
        }
    }
}

int column_maxZeros(typedata* m, const int orden) {
    
    int column = 0;
    int n_Zeros = 0;
    
    for(int x = 0; x < orden; ++x) {
        for(int y = 0; y < orden; ++y) {
            if(m[y * orden + x] == 0)
                ++n_Zeros;
        }
        if(n_Zeros > 0)
            column = x;
        n_Zeros = 0;
    }
    return column;
}

typedata determinante_Laplace(typedata* m, const int orden) {
    
    typedata det = 0.0;
    int column;
    
    if(orden == 1)
        det = m[0];
    
    else if(orden == 2)
        det = (m[0] * m[3]) - (m[1] * m[2]);
    
    else {
        column = column_maxZeros(m,orden);
        typedata m_cofactores[(orden - 1) * (orden - 1)];
        for(int x = 0; x < orden; ++x) {
            cofactores(m,m_cofactores,x,column,orden);
            if(m[x * orden + column] == 0)
                continue;
            det += ((pow(-1.0,x + column)*m[x * orden + column]) * determinante_Laplace(m_cofactores,orden - 1));
        }
    }
    
    return det;
}

typedata determinante(matrix m) {

    if(is_squareMatrix(m))
        return determinante_Laplace(m->m, m->rows);
    
    printf("Error. No se puede calcular el determinante porque la matriz no es cuadrada.\n");
    return INT_MIN;
}

matrix matriz_identidad(const int orden) {
    matrix m = NULL;
    crear_matriz(&m,orden,orden);
    
    if(m) {
        inicializar_matriz(&m);
        for(int i = 0; i < m->rows; ++i)
            m->m[(orden+1)*i] = 1;
    }
    
    return m;
}

matrix matriz_adjunta(matrix m) {
    matrix m_adj = NULL;
    
    if(is_squareMatrix(m)) {
        crear_matriz(&m_adj,m->rows,m->columns);
        
        if(m_adj) {
            int orden;
            orden = m->rows;
            typedata subMatrix[(orden - 1) * (orden - 1)];
            
            for(int x = 0; x < orden; ++x) {
                for(int y = 0; y < orden; ++y) {
                    cofactores(m->m,subMatrix,x,y,orden);
                    m_adj->m[x * orden + y] = pow(-1.0,x + y) * determinante_Laplace(subMatrix,orden - 1);
                }
            }
        }
    } else {
        printf("Error. No se puede calcular la matriz adjunta porque la matriz no es cuadrada.\n");  
    }
    return m_adj;
}

matrix_f matriz_inversa_Adj(matrix m) {
    
    matrix_f inversa = NULL;
    
    typedata det = determinante(m);
    if(det == 0)
        printf("La matriz no tiene inversa porque su determinante es igual a 0\n");
    else {
        matrix t = transpuesta(m);
        matrix adj = matriz_adjunta(t);
        inversa = producto_escalarFloat(adj,1.0/det);
        remove_matrix(&t);
        remove_matrix(&adj);
    }
    
    return inversa;
}

matrix_f matriz_inversa(matrix m) {
    
    if(is_squareMatrix(m))
        return matriz_inversa_Adj(m);
    
    printf("Error. No se puede calcular la matriz inversa porque la matriz no es cuadrada\n.");
    return NULL;   
}

matrix gauss_Jordan(matrix m) {
    int rows,columns;
    int pivot,k;
    matrix m2 = NULL;
    rows = m->rows;
    columns = m->columns;
    
    crear_matriz(&m2,rows,columns);
    
    if(m2) {
    
        int idx,idx_pivotRow;
        
        copy_matriz(&m2,m);
        
        for(int y = 0; y < rows - 1; ++y ) {
            idx_pivotRow = y * columns + y;
            pivot = m2->m[idx_pivotRow];
            for(int x = y+1; x < rows; ++x) {
                idx = x * columns + y;
                
                if(m2->m[idx] == 0)
                    continue;
                else {
                    if(m2->m[idx] % pivot == 0) {
                        k = m2->m[idx] / pivot;
                        for(int j = 0; j < columns; ++j) {
                            m2->m[idx + j] = m2->m[idx + j] - (k * m2->m[idx_pivotRow + j]);
                        }
                    } else {
                        for(int j = 0; j < columns; ++j) {
                            m2->m[idx + j] = (pivot * m->m[idx + j]) - (m->m[idx] * m2->m[idx_pivotRow + j]);
                        }
                    }
                }  
            }
        }       
    } 
    
    return m2;
}

int n_rowsWithZeros(matrix m) {
    int n_rows = 0;
    int flag = 1;
    
    for(int x = 0; x < m->rows; ++x) {
        for(int y = 0; y < m->columns; ++y) {
            if(m->m[x * m->columns + y] != 0) {
                flag = 0;
                break;
            }
        }
        if(flag)
            ++n_rows;
        else
            flag = 1;
    }
    
    return n_rows;
}

int rango(matrix m) {

    if((m->rows - n_rowsWithZeros(m)) == 0)
        return 0;
    
    int r = m->rows;
    matrix gauss = gauss_Jordan(m);
    printf("Matriz escalonada:\n");
    print_matriz(gauss);
    r -= n_rowsWithZeros(gauss);
    remove_matrix(&gauss);
    
    return r;
}

void print_matriz(matrix m) {

    if(!m)
        return;
    
    for(int x = 0; x < m->rows; ++x) {
        for(int y = 0; y < m->columns; ++y)
            printf("%4d ",m->m[x * m->columns + y]);
        
        printf("\n");
    }
    printf("\n");
}

void print_matrizFloat(matrix_f m) {
    if(!m)
        return;
    
    for(int x = 0; x < m->rows; ++x) {
        for(int y = 0; y < m->columns; ++y)
            printf("% 4.3lf ",m->m[x * m->columns + y]);
        
        printf("\n");
    }
    printf("\n");
}

void remove_matrix(matrix* m) {
    free((*m)->m);
    free(*m);
    *m = NULL;
}

void remove_matrixFloat(matrix_f* m) {
    free((*m)->m);
    free(*m);
    *m = NULL;
}

void mostrar_resultado(matrix* m, const char* str) {
    if(*m) {
        printf("%s:\n",str);
        print_matriz(*m);
        remove_matrix(m);
    }
}

void mostrar_resultadoFloat(matrix_f* m, const char* str) {
    if(*m) {
        printf("%s:\n",str);
        print_matrizFloat(*m);
        remove_matrixFloat(m);
    }
}

