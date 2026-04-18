## INFERENCE

1. Architecture & Compute Capability
   Tesla T4 GPU, Turing architecture, compute capability 7.5.
2. Max Block Dimensions
   1024 × 1024 × 64
3. Max Threads
   65535×512=33,553,920
4. Why not max threads?
   Memory limits, overhead, thread divergence, unnecessary for small tasks.
5. Limits on threads
   Registers, shared memory, hardware limits, kernel complexity.
6. Shared Memory
   Fast on-chip memory (~48 KB per block).
7. Global Memory
   Main GPU memory (~14912 MB).
8. Constant Memory
   Read-only cached memory (~64 KB).
9. Warp Size
   32 threads execute together.
10. Double Precision
    Supported.
