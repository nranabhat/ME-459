import random
import time

from pyMatmul import matmul

for n in [2**7, 2**8, 2**9]:
    A = [[random.random() for j in range(n)] for i in range(n)]
    B = [[random.random() for j in range(n)] for i in range(n)]
    
    start = time.perf_counter()
    C = matmul(A, B)
    end = time.perf_counter()
    
    print("n = "+str(n)+ ', time = '+str(end-start)+'s')
