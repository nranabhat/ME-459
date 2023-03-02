import sys
sys.path.append(r'C:\Users\Nicor\OneDrive\Documents\Semester 8\ME 459\repo459\A04')
import argparse
import time
import numpy as np
import matplotlib.pyplot as plt
from pyMatmul import matmul

# Set up argument parser
parser = argparse.ArgumentParser(description='Process input.')
parser.add_argument('input', metavar='input', type=int, choices=[0, 1],
                    help='0 or 1')
args = parser.parse_args()

# Set plotBool based on input argument
if args.input == 0:
    plotBool = True
else:
    plotBool = False

# Initialize lists to hold time data
times_list = []
times_np = []

# Loop through values of n
for i in range(5, 9):
    n = 2 ** i
    
    # Generate random matrices
    A_list = [[np.random.uniform(-1, 1) for j in range(n)] for i in range(n)]
    B_list = [[np.random.uniform(-1, 1) for j in range(n)] for i in range(n)]
    A = np.array(A_list)
    B = np.array(B_list)

    # Measure time for list multiplication
    start_time = time.perf_counter()
    C_list = matmul(A_list, B_list)
    end_time = time.perf_counter()
    times_list.append((n, (end_time - start_time) * 1000))

    # Measure time for numpy multiplication
    start_time = time.perf_counter()
    C_np = A @ B
    end_time = time.perf_counter()
    times_np.append((n, (end_time - start_time) * 1000))

    # Print first element of C_list and C_np
    if i == 8:
        print(f"{C_list[0][0]:.4f}\n{times_list[-1][1]:.2f}\n{C_np[0][0]:.4f}\n{times_np[-1][1]:.2f}")

# Generate log-log plot if plotBool is True
if plotBool:
    x = [2 ** i for i in range(5, 9)]
    y_list = [time[1] for time in times_list]
    y_np = [time[1] for time in times_np]

    plt.plot(x, y_list, 'o-', label='List Multiplication')
    plt.plot(x, y_np, 'o-', label='Numpy Multiplication')
    plt.xscale('log', base=2)
    plt.yscale('log', base=10)
    plt.title('Matrix Multiplication Performance Comparison')
    plt.xlabel('Matrix Size (n)')
    plt.ylabel('Time Taken (ms)')
    plt.legend()
    plt.show()
