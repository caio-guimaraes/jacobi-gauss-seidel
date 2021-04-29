from __future__ import division  
from numpy import linalg  
import numpy as np

def jacobi(A,b,x0,tol,N):  
    #preliminares  
    A = A.astype("double")  
    b = b.astype("double")  
    x0 = x0.astype("double")  
 
    n=np.shape(A)[0]  
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
        if (np.linalg.norm(x-x0,np.inf) < tol):  
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

def eliminacaoGauss(matriz):
    for k in range(0,5):
        for i in range(k+1, 6):
            temp = matriz[i][k]/matriz[k][k]
            print(temp)
		

def main():
    matriz = np.loadtxt("matriz.txt", dtype="int")
   
    A = np.array([[3,1,-1],  
               [-1,-4,1],  
               [1,-2,5]],  
               dtype="double")  
    D = np.diag(np.diag(A))  
    L = np.tril(A)-D  
    U=np.triu(A)-D

    print(A)
    print(D)
    print(L)
    print(U)

    J = -np.linalg.inv(D).dot(L+U);  
    cJ = np.linalg.inv(D).dot(b);

if __name__ == '__main__':
    main()
        