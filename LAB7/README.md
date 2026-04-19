# ASSIGNMENT 7

## REPORT

### Introduction

CUDA (Compute Unified Device Architecture) is a parallel computing platform developed by NVIDIA that enables the use of GPU resources for general-purpose computing. Unlike CPUs, which execute tasks sequentially, GPUs can execute thousands of threads simultaneously, making them highly efficient for data-parallel tasks. This assignment explores fundamental CUDA concepts such as kernel execution, memory management, thread organization, and performance analysis through practical problems.

### Problem 1: Sum of First N Integers
#### Objective

To compute the sum of the first N integers using CUDA by assigning different tasks to different threads.

#### Approach
An array of size N (1024) was created and initialized.
Data was transferred from host (CPU) to device (GPU).
Two threads were launched:
Thread 0 computes sum using iterative approach.
Thread 1 computes sum using direct formula.
Results were copied back to host.

#### Result
<img width="600" height="85" alt="Screenshot 2026-04-20 011602" src="https://github.com/user-attachments/assets/75d760e3-1aca-4a65-b8fb-a2c2b5eaefa0" />

#### Inference

Both methods produced the same result, validating correctness. The formula-based approach is more efficient as it computes the result in constant time, whereas the iterative method takes linear time. This shows that algorithmic efficiency is as important as parallel execution.

### Problem 2: Merge Sort (CPU vs CUDA)
#### Objective

To implement merge sort using:

(a) CPU pipelined approach
(b) CUDA parallel approach
(c) Compare performance
#### (a) CPU Pipelined Merge Sort
Implemented bottom-up (iterative) merge sort.
Eliminates recursion overhead.
Still executes sequentially on CPU.
#### (b) CUDA Merge Sort
Implemented parallel merging using CUDA threads.
Each thread handles merging of subarrays.
Uses grid and block configuration for parallelism.
#### Results 
| Method                   | Approach              | Execution Type     | Time Complexity | Execution Time (ms) | Remarks                                          |
| ------------------------ | --------------------- | ------------------ | --------------- | ------------------- | ------------------------------------------------ |
| Serial Merge Sort        | Recursive             | Sequential         | O(n log n)      |  0.132000 ms               | Higher time due to recursion overhead            |
| CPU Pipelined Merge Sort | Iterative (Bottom-Up) | Sequential         | O(n log n)      |  0.112000 ms                | Better than recursive, no function call overhead |
| CUDA Merge Sort          | Parallel              | GPU-based Parallel | O(n log n)      | 25.470049 ms                 | Much slower due to GPU overhead for small input  |


#### Inference

The CUDA implementation enables parallel execution of merge operations, which can significantly improve performance for large datasets. The pipelined CPU approach is more efficient than recursive merge sort but remains sequential. For smaller datasets (N=1000), CUDA performance gains are limited due to overheads such as memory transfer and kernel launch.

### Problem 3: Vector Addition & Bandwidth Analysis
#### Objective

To implement vector addition using CUDA and analyze memory bandwidth.

#### Approach
Two vectors were added using CUDA kernel.
Device properties were queried using cudaDeviceProp.
Theoretical bandwidth was calculated using memory clock rate and bus width.
Measured bandwidth was computed using execution time and memory operations.
#### Results
<img width="430" height="120" alt="Screenshot 2026-04-20 011622" src="https://github.com/user-attachments/assets/3898716f-ece7-45ae-b334-6de5b45f65c5" />

#### Inference

The measured bandwidth is significantly lower than the theoretical bandwidth due to practical limitations such as memory latency, kernel launch overhead, and non-optimal memory access patterns. This highlights the difference between ideal hardware performance and real-world execution.

### Conclusion

This assignment demonstrated the effectiveness of CUDA for parallel computing. While GPUs offer significant speedup for large-scale problems, performance depends on factors such as input size, memory access patterns, and overheads. It was observed that parallel algorithms outperform sequential ones for large datasets, but for smaller inputs, CPU implementations can be equally efficient or even faster.
