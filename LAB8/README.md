# REPORT
## ASSIGNMENT - 8

### Introduction

This assignment explores GPU acceleration using CUDA for machine learning workloads. It focuses on understanding how parallel computing improves performance compared to CPU execution. The experiments cover vector operations, memory hierarchy optimization, ML primitives, CNN layers, and full MNIST training. The goal is to analyze speedup, memory behavior, and kernel optimization techniques such as shared memory, tiling, warp execution, and fused kernels.

### Problem 1: CUDA Basics – Architecture & Profiling
#### Objective

To analyze CPU vs GPU performance for vector operations and study CUDA thread configurations and memory transfer overheads.

#### Results
GPU shows significant speedup for large input sizes
CPU performs better for small inputs due to kernel launch overhead
Optimal block size observed at multiples of 32 (warp size)
<img width="929" height="634" alt="Screenshot 2026-04-27 021641" src="https://github.com/user-attachments/assets/dafef5d9-12ab-481f-ae4a-fccd2150ae84" />
<img width="778" height="654" alt="Screenshot 2026-04-27 021735" src="https://github.com/user-attachments/assets/2b0328cf-edb2-4df5-9148-64b9ec0b048e" />
<img width="637" height="678" alt="Screenshot 2026-04-27 021717" src="https://github.com/user-attachments/assets/f22a5c6c-f5e5-4586-af2d-45f464417c4a" />
<img width="778" height="654" alt="Screenshot 2026-04-27 021735" src="https://github.com/user-attachments/assets/47dcebab-16ee-4572-a2c7-4f1921492619" />


#### Observation

GPU becomes efficient only after a crossover point where computation outweighs transfer overhead. Warp-aligned block sizes improve performance significantly.

### Problem 2: Memory Hierarchy & Reduction Optimization
#### Objective

To compare reduction techniques and analyze memory hierarchy effects including shared memory and bank conflicts.

#### Results
Naive reduction: slowest due to global memory access
Shared memory reduction: improved performance
Warp shuffle: best performance (minimal memory overhead)
Bank conflicts increase latency for large strides
Padding resolves shared memory conflicts
<img width="721" height="689" alt="Screenshot 2026-04-27 021824" src="https://github.com/user-attachments/assets/e78ecbbc-f7cd-4cd3-8a43-e5593db13505" />


#### Observation

Memory hierarchy optimization is critical. Warp-level primitives outperform shared memory methods due to reduced latency.

### Problem 3: ML Primitives (Activations, Loss, Optimizer)
#### Objective

To implement deep learning building blocks using CUDA and compare with PyTorch.

#### Results
CUDA kernels match PyTorch outputs (low error)
GPU achieves high throughput for large tensors
Fused optimizer reduces memory operations
<img width="690" height="687" alt="Screenshot 2026-04-27 021836" src="https://github.com/user-attachments/assets/7cc940d4-c4b6-457c-a74c-53d521f85a52" />
<img width="1055" height="603" alt="Screenshot 2026-04-27 021855" src="https://github.com/user-attachments/assets/5510ca66-28a4-448e-a7e4-aae9087681c8" />


#### Observation

Fused kernels significantly reduce overhead and improve training efficiency.

### Problem 4: Tiled GEMM & CNN Benchmarking
#### Objective

To optimize matrix multiplication and benchmark CNN layers on GPU.

#### Results
Naive GEMM: lowest performance
Tiled GEMM: improved due to memory reuse
cuBLAS: highest performance (Tensor Cores + FP16)
Convolution is most expensive CNN operation
<img width="845" height="721" alt="Screenshot 2026-04-27 021916" src="https://github.com/user-attachments/assets/83704196-0b13-4bee-b23a-b5ebb3b3fc59" />
<img width="790" height="592" alt="Screenshot 2026-04-27 021925" src="https://github.com/user-attachments/assets/0490094d-0e1d-4f99-ae37-55d59fa673ad" />


#### Observation

Library-optimized kernels outperform custom implementations due to hardware-level optimizations.

### Conclusion

This assignment demonstrates the power of GPU acceleration in machine learning workloads. CUDA enables massive parallel computation, but performance depends heavily on memory hierarchy, kernel design, and thread configuration. Optimizations like shared memory, warp-level execution, tiling, and fused kernels significantly improve performance. While cuBLAS and cuDNN provide highly optimized implementations, custom CUDA kernels help understand underlying architectural behavior and trade-offs. Overall, GPU computing provides substantial speedup over CPU for large-scale ML tasks.
