#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <math.h>
// #include <bits/stdc++.h>

void imprime(){
    printf("Hello Wolrd!\n");
}

int main() {
    std::cout << "CSR JACOBI - DIAGONAL DOMINANTE" << std::endl;

    //Esse algoritmo serve para Matriz AA onde a diagonal é dominante
    //Caso não seja dominante, deve-se realizar trocas entre linhas
    

    float values[] = {8, 1, -1, 1, -7, 2, 2, 1, 9};     //VAA
    int column_index[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};   //VJA
    int row_index[] = {0, 3, 6};                        //VIA
    float b[] = {8, -4, 12};


    // RESPOSTA x = {1, 2, 3}

    int valuesize = (int)sizeof(values)/sizeof(float); //Tamanho de VAA
    printf ("valuesize = %d \n", valuesize);
    int n = (int)sizeof(row_index)/sizeof(float);      //Tamanho do array row_index
    printf ("n= rowsize = %d \n", n);

    float x_new[] = {0, 0, 0};                         //Valores de x na iteração k+1
    float x_old[] = {0, 0, 0};                         //Valores de x na iteração k
    int iter_counter = 0;                              //Contador de passos do loop while

    float epsilon = 0.0001;                            //Erro admissível
    float iter_error = epsilon*2;                      //Erro na iteração
    int max_iter = 1000;                               // Máximo de iterações

    float s;                                           // Para armazenar a operação (B - aij*x[i])
    int current_row_index,  next_row_index;            //Valor do índice armazenado em VIA[i], Valor do próximo indice de VIA[i+1]

    while ((iter_counter < max_iter) && (iter_error > epsilon)){ // Passos do método iterativo
        iter_error = 0;
        for (int i = 0; i < n; i++) {                           //Loop i até n = tamanho do array VIA (ex.: 3)
            current_row_index = row_index[i];                   //Valor do índice armazenado em VIA[i]

            if (i != (n - 1)) {                                 // Essa condicional é para garantir que quando chegar em n, o next_row_index não pegue o valor de VIA[n+1], fora do array
                next_row_index = row_index[i + 1];
            } else {
                next_row_index = valuesize;
            }

            float sum = 0;
            for (int j = current_row_index; j <= next_row_index - 1; j++) {  // Esse loop vai calcular Somatório de aij*x[i], os indíces são consultados nas matrizes VJA
                if (i != column_index[j]) {                                 // Essa condicional evita calcular o da diagonal e pegar aii*x[i]
                    sum = sum + values[j] * x_old[column_index[j]];         //aij*x[i]
                    //printf(" i = %d, j = %d, value = %f , xold[%d] = %f", i, j, values[j], column_index[j], x_old[column_index[j]]);

                }
            }

            s = b[i] - sum;                                                 //b[i] - Som(aij*x[i])
            for (int j = current_row_index; j <= next_row_index - 1; j++) { //Esse loop vai calcular (b[i] - Sum)/aii
                if (i == column_index[j]) {                                 //Apenas para calcular quando for o índice da diagonal aii
                    x_new[i] = (s/values[j]);
                    //printf(" \n <<<<i = %d, j = %d, s= %f, value = %f >>>", i, j, s, values[j]);
                }
            }
            printf(" # ");

            iter_error += abs((x_new[i] - x_old[i]));                    //Calcula o erro de x (k+1) e x(k)
        }
        for (int m = 0 ; m < n; m++) {
            x_old[m] = x_new[m];                                            // Atualiza x_k para ter os novos valores e ser usado na próxima iteração
        }
        iter_error = abs(sqrt(iter_error));                                 // Calcula o erro global da iteração - equivale a função Norm
        iter_counter++;
        printf("\n it = %d", iter_counter);                                 //
        printf ("\n ======> x1 = %lf, x2 = %lf , x3 = %lf ", x_new[0], x_new[1], x_new[2]); // Plota os resultados
        printf(" \n");
    }

    return 0;
}
