# ASSIGNMENT - 5
## REPORT


### Introduction

This assignment investigates the principles of parallel and distributed computing using the Message Passing Interface (MPI). The objective is to understand how computational problems behave under parallel execution and to evaluate scalability, communication overhead, synchronization cost, and load balancing strategies.

### Theory
##### Parallel Speedup

Speedup is defined as:

S(p)=T1​/Tp​​
	​
Where:

𝑇1 = serial execution time

𝑇𝑝 = parallel execution time with p processes

Ideal speedup is linear:
𝑆(𝑝)=𝑝

However, in real systems, speedup is limited by communication and synchronization overhead.

##### Efficiency
𝐸(𝑝)=𝑆(𝑝)/𝑝
	​
Efficiency measures how effectively processes are utilized.

 ##### Amdahl’s Law

Amdahl’s Law states that the maximum theoretical speedup is limited by the serial portion of a program:

𝑆(𝑝)=1/(𝑓+(1−(𝑓/𝑝)))

Where:

𝑓 = fraction of serial work

This explains why speedup eventually saturates as processes increase.

#### Q1 – DAXPY (Data Parallelism)

###### Description
Implements the operation:
X[i]=a⋅X[i]+Y[i]

The data is divided among processes using:

MPI_Scatter

Local computation

MPI_Gather

###### Observations

Performance improvement is limited.

Communication overhead (Scatter/Gather) impacts scalability.

Small data size reduces parallel efficiency.

###### Inference

Parallelization is less effective for small problem sizes due to communication cost dominating computation.

#### Q2 – Broadcast Race (MyBcast vs MPI_Bcast)
###### Description

Two broadcast methods were compared:

Manual broadcast using MPI_Send and MPI_Recv

Optimized MPI_Bcast

###### Observations

Manual broadcast time increases significantly as processes increase.

MPI_Bcast performs much better due to tree-based communication.

###### Inference

Built-in collective communication (MPI_Bcast) is more scalable and efficient than manual implementation.

#### Q3 – Distributed Dot Product
###### Description

Total dot product of a large dataset (500 million operations) was computed using:

MPI_Bcast

Local computation

MPI_Reduce

###### Observations

Good speedup achieved.

Communication cost is low compared to computation.

###### Inference

This problem shows strong scalability due to high compute-to-communication ratio.

#### Q4 – Prime Number Search (Master–Slave)
###### Description

Dynamic scheduling was implemented:

Master assigns numbers

Slaves test primality

Results returned dynamically

###### Observations

Good load balancing.

Execution time decreases as processes increase.

At high process count, master becomes bottleneck.

###### Inference

Dynamic scheduling improves efficiency but scalability is limited by centralized coordination.

#### Q5 – Perfect Number Search (Master–Slave)
###### Description

Similar to Q4 but checks for perfect numbers by computing divisor sums.

###### Observations

Heavier computation than prime testing.

Parallelization reduces time significantly.

Master bottleneck appears at higher process counts.

###### Inference

Dynamic master–slave approach improves utilization but does not scale infinitely.
