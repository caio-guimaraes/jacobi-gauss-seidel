#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <math.h>
#include <vector>
#include "jacobi.h"
#include <fstream>
#include<string>

void displayArray(std::vector<int> v){
    for(int i=0; i<v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << "\n";
}

void displayMatrix(int **matrix, int linhas, int colunas){
  for(int i=0; i<linhas; i++){
    for(int j=0; j<colunas; j++){
        std::cout << matrix[i][j] << " "; 
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

int **iniatilizeMatrix(int linhas, int colunas){
    int i,j;
    int **m = (int **)malloc(sizeof(int *)*linhas);
    for(i=0; i<linhas; i++){
        m[i] = (int *)malloc(sizeof(int)*colunas);
    }
    return m;
}

int **fillMatrix(char *nameFile, int *linhas, int *colunas){
    std::fstream myFile(nameFile, std::ios_base::in);
    myFile >> *linhas >> *colunas;
 
    int **matrix = iniatilizeMatrix(*linhas, *colunas);
    for (int i=0; i<*linhas; i++){
        for (int j=0; j<*colunas; j++)
            myFile >> matrix[i][j];      
    }
 
    myFile.close();
    return matrix;
}

void csr(int **matrix, int linhas, int colunas, std::vector<int> &values, std::vector<int> &column_index, std::vector<int> &row_index){
    for (int i=0; i<linhas; i++){
        row_index.push_back(values.size());
        for (int j=0; j<colunas; j++){
            if(matrix[i][j] != 0){
                values.push_back(matrix[i][j]);
                column_index.push_back(j);
            }
        }
    }
}

int main(int argc, char **argv) {
    char *nameFile = argv[1];
    int linhas, colunas;
    int **matrix = fillMatrix(nameFile, &linhas, &colunas);
    printf("\n----- Matriz ------\n");
    displayMatrix(matrix, linhas, colunas);

    std::vector<int> values, column_index, row_index;
    csr(matrix, linhas, colunas, values, column_index, row_index);
    std::cout << "values: ";
    displayArray(values);
    std::cout << "column_index: ";
    displayArray(column_index);
    std::cout << "row_index: ";
    displayArray(row_index);
    float b[] = {1,-1};
    jacobi_csr(values, column_index, row_index, b);
    return 0;
}