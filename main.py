from __future__ import division
from numpy import linalg
import numpy as np

def jacobi_csr(aa, jr, jc, b, tol, N):
    it = 0 ### ou 1
    total_linhas = len(jc)
    x = [np.zeros(total_linhas),np.zeros(total_linhas)]
    while it < N:
        cont = 0
        for i in range(1,total_linhas): # ordem -> poderia ser ordem de linha
            total_elementos_linha = jc[i+1]-jc[i]
            j = total_elementos_linha ## nao sabemos se faz diferença
            for ii in range(1, total_elementos_linha):
                cont = cont+1
                if jr[cont] != i:
                    x[1][i] -= x[0][jr[cont]]*aa[cont]
                else:
                    x[1][i] += b[i]
                    j = cont
            x[1][i] /= aa[j]
        if np.linalg.norm(x[1] - x[0], np.inf) < tol:
            return x
        x[0] = x[1]
        it += 1





def jacobi(A,b,x0,tol,N):  
    #preliminares  
    A = A.astype("double")  
    b = b.astype("double")  
    x0 = x0.astype("double")  


    n = np.shape(A)[0]
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




def gauss_seidel(A,b,x0,tol,N):  
    #preliminares  
    A = A.astype("double")  
    b = b.astype("double")  
    x0 = x0.astype("double")  
 
    n=np.shape(A)[0]  
    x = np.copy(x0)  
    it = 0  
    #iteracoes  
    while (it < N):  
        it = it+1  
        #iteracao de Jacobi  
        for i in np.arange(n):  
            x[i] = b[i]  
            for j in np.concatenate((np.arange(0,i),np.arange(i+1,n))):
                x[i] -= A[i,j]*x[j]
            x[i] /= A[i,i]  
            print(x[i],A[i,i])  
        #tolerancia  
        if (np.linalg.norm(x-x0,np.inf) < tol):  
            return x  
        #prepara nova iteracao  
        x0 = np.copy(x)  
    raise NameError("num. max. de iteracoes excedido.")


def main():
    matriz = np.loadtxt("matriz.txt", dtype="int")
    # forma matricial do sistema Ax = b
   
    # Matriz dos coeficientes
    A = np.array([[3,1,-1],     
               [-1,-4,1],  
               [1,-2,5]],  
               dtype="double") 
                
    # Vetor dos termos constantes  
    b = np.array([2, -10, 0], dtype="double") 

    print("Matriz A: \n", A, "\n") 
    print("Vetor b: \n", b, "\n") 

    D = np.diag(np.diag(A))     # matriz diagonal
    L = np.tril(A)-D            # matriz triangular inferior
    U=np.triu(A)-D              # matriz triangular superior
    
    print("Matriz D: \n", D, "\n") 
    print("Matriz L: \n", L, "\n") 
    print("Matriz U: \n", U, "\n") 

    # Jacobi
    J = -np.linalg.inv(D).dot(L+U)      # Matriz de iteração Tj
    cJ = np.linalg.inv(D).dot(b)        # vetor de iteração cj

    print("Matriz J: \n", J, "\n")
    print("Vetor cJ: \n", cJ, "\n")

    # Gauss-Seidel
    TG = -np.linalg.inv(L+D).dot(U)     # Matriz de iteração Tg
    cG = np.linalg.inv(L+D).dot(b)      # vetor de iteração cG

if __name__ == '__main__':
    main()
        