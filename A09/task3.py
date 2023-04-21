import random
import time

# initialize matrices A and B with random values
A = [[random.uniform(-1, 1) for j in range(1400)] for i in range(3400)]
B = [[random.uniform(-1, 1) for j in range(1400)] for i in range(3400)]

# print last entry of A and B
print(f"Last entry of A: {A[-1][-1]}, Last entry of B: {B[-1][-1]}")

# swap each entry of the two matrices row by row using for loops
start_time = time.time()
for i in range(3400):
    for j in range(1400):
        temp = A[i][j]
        A[i][j] = B[i][j]
        B[i][j] = temp
end_time = time.time()

# print last entry of A and B and timing result in milliseconds
print(f"Last entry of A: {A[-1][-1]}, Last entry of B: {B[-1][-1]}")
print(f"Time taken to swap by row: {(end_time - start_time) * 1000:.2f} ms")

# swap each entry of the two matrices column by column using for loops
start_time = time.time()
for j in range(1400):
    for i in range(3400):
        temp = A[i][j]
        A[i][j] = B[i][j]
        B[i][j] = temp
end_time = time.time()

# print last entry of A and B and timing result in milliseconds
print(f"Last entry of A: {A[-1][-1]}, Last entry of B: {B[-1][-1]}")
print(f"Time taken to swap by column: {(end_time - start_time) * 1000:.2f} ms")
