import sys
sys.path.append(r'C:\Users\Nicor\OneDrive\Documents\Semester 8\ME 459\repo459\A04')
import argparse
import time
import numpy as np
import matplotlib.pyplot as plt
from pySort import sorter
import copy

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

# Create A_list with random integers
n_values = [2**i for i in range(10, 15)]
sorter_times = []
python_sort_times = []
numpy_sort_times = []

for n in n_values:
    # Create A_list with random integers
    A_list = [np.random.randint(-10, 11) for i in range(n)]
    B_list = copy.deepcopy(A_list)

    # Create numpy array A with the same elements as A_list
    A = np.array(A_list)

    # Sort A_list in-place using sorter function
    start_time = time.perf_counter()
    sorter(A_list)
    end_time = time.perf_counter()
    time_taken = (end_time - start_time) * 1000
    sorter_times.append(time_taken)

    # Sort B_list in-place using Python's sorting function
    start_time = time.perf_counter()
    B_list.sort()
    end_time = time.perf_counter()
    time_taken = (end_time - start_time) * 1000
    python_sort_times.append(time_taken)

    # Sort numpy array A using numpy's sorting function
    start_time = time.perf_counter()
    np.sort(A)
    end_time = time.perf_counter()
    time_taken = (end_time - start_time) * 1000
    numpy_sort_times.append(time_taken)

    # Print first element 
    if n == 2**14:
        print(f"{A_list[0]}\n{sorter_times[-1]:.2f}\n{B_list[0]}\n{python_sort_times[-1]:.2f}\n{A[0]}\n{numpy_sort_times[-1]:.2f}\n")

# Generate log-log plot if plotBool is True
if plotBool:
    # plt.loglog(n_values, sorter_times, label='sorter')
    # plt.loglog(n_values, python_sort_times, label='Python sort')
    # plt.loglog(n_values, numpy_sort_times, label='numpy sort')

    # # Set plot title, X and Y axis labels, and legend
    # plt.title('Comparison of Sorting Methods')
    # plt.xlabel('n (log base 2)')
    # plt.ylabel('Time Taken (ms) (log base 10)')
    # plt.legend()

    # # Show the plot
    #plt.show()

    x = [2 ** i for i in range(10, 15)]

    plt.plot(x, sorter_times, 'o-', label='sorter')
    plt.plot(x, python_sort_times, 'o-', label='Python sort')
    plt.plot(x, numpy_sort_times, 'o-', label='numpy sort')
    plt.xscale('log', base=2)
    plt.yscale('log', base=10)
    plt.title('Comparison of Sorting Methods')
    plt.xlabel('Matrix Size (n)')
    plt.ylabel('Time Taken (ms)')
    plt.legend()
    plt.show()