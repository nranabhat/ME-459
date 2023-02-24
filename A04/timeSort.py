import random
import time

from pySort import sorter

for n in [10**3, 10**4, 10**5, 10**6]:
    A = [random.random() for i in range(n)]
    before = A[0]
    
    start = time.perf_counter()
    sorter(A)
    end = time.perf_counter()
    
    after = A[0]
    
    print("n = "+str(n)+", time = " +str(end-start)+"s, before = "+str(before)+", after = " +str(after))
