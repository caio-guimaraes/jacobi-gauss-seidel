#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <math.h>
#include <vector>

void jacobi_csr(std::vector<int> values, std::vector<int> column_index, std::vector<int> row_index, std::vector<float> b, float epsilon, int max_iter){
    std::cout << "\nCSR JACOBI" << std::endl;

    /* Esse algoritmo serve para Matriz AA onde a diagonal é dominante
     Caso não seja dominante, deve-se realizar trocas entre linhas */

    int valuesize = values.size();                                              // Tamanho de VAA
    printf ("valuesize = %d \n", valuesize);
    int n = row_index.size();                                                   // Tamanho do array row_index
    printf ("rowsize = %d \n", n);

    float x_new[] = {0, 0, 0};                                                  // Valores de x na iteração k+1
    float x_old[] = {0, 0, 0};                                                  // Valores de x na iteração k
    int iter_counter = 0;                                                       // Contador de passos do loop while

    // float epsilon = 0.0001;                                                     // Erro admissível
    float iter_error = epsilon*2;                                               // Erro na iteração
    // int max_iter = 1000;                                                        // Máximo de iterações

    float s;                                                                    // Para armazenar a operação (B - aij*x[i])
    int current_row_index,  next_row_index;                                     // Valor do índice armazenado em VIA[i], Valor do próximo indice de VIA[i+1]

    while ((iter_counter < max_iter) && (iter_error > epsilon)){                // Passos do método iterativo
        iter_error = 0;
        for (int i = 0; i < n; i++) {                                           // Loop i até n = tamanho do array VIA (ex.: 3)
            current_row_index = row_index[i];                                   // Valor do índice armazenado em VIA[i]

            if (i != (n - 1)) {                                                 // Essa condicional é para garantir que quando chegar em n, o next_row_index não pegue o valor de VIA[n+1], fora do array
                next_row_index = row_index[i + 1];
            } else {
                next_row_index = valuesize;
            }

            float sum = 0;
            for (int j = current_row_index; j <= next_row_index - 1; j++) {     // Esse loop vai calcular Somatório de aij*x[i], os indíces são consultados nas matrizes VJA
                if (i != column_index[j]) {                                     // Essa condicional evita calcular o da diagonal e pegar aii*x[i]
                    sum = sum + values[j] * x_old[column_index[j]];             // aij*x[i]
                }
            }

            s = b[i] - sum;                                                     // b[i] - Som(aij*x[i])
            for (int j = current_row_index; j <= next_row_index - 1; j++) {     // Esse loop vai calcular (b[i] - Sum)/aii
                if (i == column_index[j]) {                                     // Apenas para calcular quando for o índice da diagonal aii
                    x_new[i] = (s/values[j]);
                }
            }
            printf("###");

            iter_error += abs((x_new[i] - x_old[i]));                           // Calcula o erro de x (k+1) e x(k)
        }
        for (int m = 0 ; m < n; m++) {
        x_old[m] = x_new[m];                                                    // Atualiza x_k para ter os novos valores e ser usado na próxima iteração
        }
        iter_error = abs(sqrt(iter_error));                                     // Calcula o erro global da iteração - equivale a função Norm
        iter_counter++;

        printf("\nit = %d ======> ", iter_counter);                                 
         for (int i=0;i<n;i++){
            printf (" x%d = %lf ",i, x_new[i]);                                 // Plota os resultados
        }
        printf("\n");
    }
}