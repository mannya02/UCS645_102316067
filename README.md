# UCS645
## LAB1

### 1. Hello World (eg1.c)
A simple OpenMP program to verify thread creation and execution.

### 2. DAXPY Operation (daxpy.c)
Operation performed:
X[i] = a * X[i] + Y[i]
#### Execution Time vs Threads

| Number of Threads | Time (seconds) |
|------------------|----------------|
| 2 | 0.000609 |
| 3 | 0.001476 |
| 4 | 0.000415 |
| 5 | 0.000427 |
| 6 | 0.020272 |
| 7 | 0.028002 |
| 8 | 0.000869 |
| 9 | 0.038839 |
| 10 | 0.035419 |

**Observation:**  
Execution time improves as threads increase up to the number of available CPU cores. Beyond this point, performance degrades due to thread management overhead and memory bandwidth limitations.

### 3. Matrix Multiplication – 1D Threading (matrix_1d.c)
Matrix size: 1000 × 1000  
Parallelization: Outer loop only

#### Execution Time vs Threads

| Number of Threads | Time (seconds) |
|------------------|----------------|
| 2 | 19.009500 |
| 3 | 19.947340 |
| 4 | 23.728935 |
| 5 | 21.889700 |
| 6 | 6.762350 |
| 7 | 6.127166 |
| 8 | 6.515316 |

**Observation:**  
1D threading provides limited parallelism. Performance improves significantly only when thread count approaches the number of CPU cores.

### 4. Matrix Multiplication – 2D Threading (matrix_2d.c)
Matrix size: 1000 × 1000  
Parallelization: Nested loops using `collapse(2)`

#### Execution Time vs Threads

| Number of Threads | Time (seconds) |
|------------------|----------------|
| 2 | 0.331976 |
| 3 | 0.226784 |
| 4 | 0.233577 |
| 5 | 0.154990 |
| 6 | 0.160894 |
| 7 | 0.144686 |
| 8 | 0.134341 |

**Observation:**  
2D threading gives significantly better performance due to improved workload distribution. The best performance was achieved at 8 threads.

### 5. Calculation of π (pi.c)
π is approximated using numerical integration:
π = ∫₀¹ 4 / (1 + x²) dx
Parallelization is achieved using OpenMP with `reduction(+:sum)` to avoid race conditions.
