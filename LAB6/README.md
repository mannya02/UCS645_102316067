# ASSIGNMENT 6

## REPORT

### Introduction

This experiment focuses on understanding GPU architecture using CUDA and comparing its performance with traditional CPU execution. CUDA enables parallel computation by utilizing thousands of GPU threads, making it highly efficient for data-parallel tasks. The objective is to analyze device properties and evaluate performance improvements in array summation and matrix addition using CUDA over CPU.

### Q1: Device Query Analysis

The system uses a Tesla T4 GPU based on Turing architecture with compute capability 7.5. It supports large-scale parallel execution with a maximum block dimension of 1024 × 1024 × 64 and can launch millions of threads. However, practical limits depend on memory, registers, and kernel design. The GPU provides approximately 15 GB global memory, 64 KB shared memory per block, and 64 KB constant memory. It operates with a warp size of 32 threads and supports double precision, making it suitable for high-performance parallel computation.

### Q2: Array Sum (CPU vs CUDA)
#### Problem Description

Compute the sum of a large array of floating-point numbers.

#### CPU Approach

The CPU executes the summation sequentially using a loop, processing one element at a time. This results in higher execution time as the input size increases.

#### CUDA Approach

CUDA divides the array among multiple GPU threads and performs parallel reduction. Each thread processes a portion of the data, significantly reducing computation time.

#### Observation

CUDA execution is much faster than CPU for large arrays due to parallel processing. The speedup increases as the input size grows.

#### Performance Comparison (Array Sum)
Implementation	Time 
| CPU |	0.00410134 seconds |
| CUDA|	0.000251 seconds |

### Q3: Matrix Addition (CPU vs CUDA)
#### Problem Description

Perform addition of two large matrices.

#### CPU Approach

Matrix elements are added sequentially using nested loops, resulting in slower execution for large matrices.

#### CUDA Approach

Each GPU thread computes one element independently using:
C[i][j] = A[i][j] + B[i][j]

This allows thousands of elements to be processed simultaneously.

#### Analysis

The operation involves N × N additions, with 2 × N × N memory reads and N × N writes. CUDA executes these operations in parallel, improving performance significantly.

#### Observation

Matrix addition is highly parallelizable, and CUDA achieves faster execution compared to CPU.

#### Performance Comparison (Matrix Addition)
Implementation	Time 
| CPU |	0.02287272 seconds |
| CUDA|	0.012951 seconds |

 ### Conclusion

The experiment demonstrates that CUDA significantly outperforms CPU execution for data-parallel tasks such as array summation and matrix addition. GPU acceleration reduces execution time by utilizing massive parallelism, making it highly suitable for large-scale computations.
