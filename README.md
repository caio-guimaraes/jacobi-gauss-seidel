# Trabalho de Programação Científica

## O objetivo deste trabalho é implementar o método de Jacobi e método de Gauss-Seidel para matrizes esparsas

### Os métodos utilizam a técnica de armazenamento CSR

### Execução

Para executar o programa basta escrever no terminal a linha abaixo:

```
./main matriz.txt 0.0001 1000
```

matriz.txt é o arquivo onde estão as matrizes de coeficientes e o vetor de constantes, 0.0001 é o erro admissível e 1000 é o número máximo de iterações
O formato do arquivo está ilustrado a seguir:

```
5 5
1 0 2 0 0
0 3 0 4 0
5 0 6 0 7
0 0 8 9 0
1 0 0 0 11

2 0 3 4 2
```

A primeira linha do arquivo indica o número de linhas e o número de colunas respectivamente
<br/>
A última linha representa o vetor de constantes
