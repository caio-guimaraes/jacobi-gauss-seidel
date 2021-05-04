import numpy as np

# def jacobi(dados):
#     # percorrer toda a matriz e guardar valores não nulos em array
#
#         dados = [[1,2,3],[4,5,6],[7,8,9]]
#
#     ##na mesma iteração fazemos
#     nao_nulos = [1,2,3,4,5,6,7,8,9] # TODO =  np.zeros(n)
#
#
#     #para cada elemento do vetor de cima, ele armazena a coluna que o elemento aparece
#     colunas_nao_nulos = [1,2,3,1,2,3,1,2,3] #TODO
#
#     #guardar posicao+1 do primeiro elemento não nulo dessa linha
#     linhas_nao_nulos = [1, 4, 7]
#
#     ##aplicar metodo de jacobi com esses caras

def jacobi(nao_nulos, colunas_nao_nulas, linhas_nao_nulas ,x0,tol,N):
    #preliminares
    #A = A.astype("double")
    #b = b.astype("double")
    x0 = x0.astype("double")


#    n = np.shape(A)[0]
    x = np.zeros(n)
    it = 0
    #iteracoes
    while (it < N):
        it = it+1
        #iteracao de Jacobi
        for i in np.arange(n):
            x[i] = b[i]
            for j in np.concatenate((np.arange(0,i),np.arange(i+1,n))):
                x[i] -= A[i,j]*x0[j]
            x[i] /= A[i,i]
        #tolerancia
        if np.linalg.norm(x - x0, np.inf) < tol:
            return x
        #prepara nova iteracao
        x0 = np.copy(x)
    raise NameError("num. max. de iteracoes excedido.")

----------

A = [[1,2,3],[0,2]]
y = [4,5]

A = [[1,0,0,3],[0,1,0,0]]
y = [2,5]

--------------------------------------------


[1,3]
[]

--------------------------------------------

nao_nulos = [1,3,1]    ---->  [1,3] ---> [1,4]   ============== [x1=-(x4*nao_nulo[1])/nao_nulo[0]]
colunas = [1,4,2]
primeiro_linha = [1, 3] --> 3-1=2 (na primeira linha tenho 2 nao nulos)

PASSO1: posicao de x1 na linha é x[0]-1 / primeira_linha[2]-primeira_linha[1]

----------------------

x1 = (y1 - (2*x2+3*x3))/1
------------------------------------------







