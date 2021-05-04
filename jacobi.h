#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <math.h>
#include <vector>

void jacobi_csr(std::vector<int> values, std::vector<int> column_index, std::vector<int> row_index, float b[]);