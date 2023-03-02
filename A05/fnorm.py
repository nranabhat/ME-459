import numpy as np
import sys

# Read the filename from command line argument
filename = sys.argv[1]

# Load the CSV file into a numpy array
arr = np.loadtxt(filename + '.csv', delimiter=',')

# Compute the Frobenius norm of the array
fro_norm = np.linalg.norm(arr, ord='fro')

# Print the Frobenius norm
print(f'{fro_norm:.3f}')

