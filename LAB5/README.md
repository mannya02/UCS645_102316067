# ASSIGNMENT - 5
## REPORT


### Introduction

This assignment investigates the principles of parallel and distributed computing using the Message Passing Interface (MPI). The objective is to understand how computational problems behave under parallel execution and to evaluate scalability, communication overhead, synchronization cost, and load balancing strategies.

### Theoretical Background
2.1 Parallel Speedup

Speedup is defined as:

𝑆
(
𝑝
)
=
𝑇
1
𝑇
𝑝
S(p)=
T
p
	​

T
1
	​

	​


Where:

𝑇
1
T
1
	​

 = serial execution time

𝑇
𝑝
T
p
	​

 = parallel execution time with p processes

Ideal speedup is linear:

𝑆
(
𝑝
)
=
𝑝
S(p)=p

However, in real systems, speedup is limited by communication and synchronization overhead.

2.2 Efficiency
𝐸
(
𝑝
)
=
𝑆
(
𝑝
)
𝑝
E(p)=
p
S(p)
	​


Efficiency measures how effectively processes are utilized.

2.3 Amdahl’s Law

Amdahl’s Law states that the maximum theoretical speedup is limited by the serial portion of a program:

𝑆
(
𝑝
)
=
1
𝑓
+
1
−
𝑓
𝑝
S(p)=
f+
p
1−f
	​

1
	​


Where:

𝑓
f = fraction of serial work

This explains why speedup eventually saturates as processes increase.

3. Theoretical Discussion per Problem
Q1 – DAXPY (Data Parallelism)
Computational Nature

Regular data parallel problem.

Requires data distribution (Scatter) and collection (Gather).

Theoretical Behavior

The total execution time can be modeled as:

𝑇
𝑝
=
𝑇
𝑠
𝑐
𝑎
𝑡
𝑡
𝑒
𝑟
+
𝑇
𝑐
𝑜
𝑚
𝑝
𝑢
𝑡
𝑒
+
𝑇
𝑔
𝑎
𝑡
ℎ
𝑒
𝑟
T
p
	​

=T
scatter
	​

+T
compute
	​

+T
gather
	​


Even though computation reduces proportionally to 
1
/
𝑝
1/p, communication cost does not reduce.

Scalability Analysis

If computation time is small compared to communication, speedup will be limited.

For small vector sizes, communication dominates.

For very large vectors, computation dominates, improving scalability.

Conclusion

DAXPY demonstrates that parallel efficiency strongly depends on the compute-to-communication ratio.

Q2 – Broadcast Race
Manual Broadcast

Manual implementation performs:

𝑃
−
1
 point-to-point sends
P−1 point-to-point sends

Time complexity:

𝑂
(
𝑃
)
O(P)
MPI_Bcast

MPI uses optimized tree-based or pipeline algorithms:

𝑂
(
log
⁡
𝑃
)
O(logP)
Theoretical Implication

As process count increases:

Manual broadcast time increases linearly.

MPI_Bcast increases logarithmically.

Conclusion

Collective operations provided by MPI are optimized and scale significantly better than manual implementations.

Q3 – Distributed Dot Product
Computational Nature

Embarrassingly parallel problem.

Minimal communication.

One broadcast + one reduction.

Time Model
𝑇
𝑝
=
𝑇
𝑏
𝑟
𝑜
𝑎
𝑑
𝑐
𝑎
𝑠
𝑡
+
𝑇
𝑐
𝑜
𝑚
𝑝
𝑢
𝑡
𝑒
𝑝
+
𝑇
𝑟
𝑒
𝑑
𝑢
𝑐
𝑒
T
p
	​

=T
broadcast
	​

+
p
T
compute
	​

	​

+T
reduce
	​


Since computation dominates (500 million operations), communication overhead is relatively small.

Scalability

Near-linear speedup achievable.

Eventually limited by reduction overhead and memory bandwidth.

Conclusion

Dot product represents an ideal parallel workload with strong scalability characteristics.

Q4 – Prime Number Search (Dynamic Scheduling)
Workload Characteristics

Non-uniform workload.

Some numbers require more computation than others.

Static vs Dynamic Partitioning

Static partitioning → load imbalance.

Dynamic master–slave → better resource utilization.

Theoretical Time
𝑇
𝑝
=
𝑇
𝑐
𝑜
𝑚
𝑝
𝑢
𝑡
𝑒
/
𝑝
+
𝑇
𝑐
𝑜
𝑚
𝑚
𝑢
𝑛
𝑖
𝑐
𝑎
𝑡
𝑖
𝑜
𝑛
+
𝑇
𝑐
𝑜
𝑜
𝑟
𝑑
𝑖
𝑛
𝑎
𝑡
𝑖
𝑜
𝑛
T
p
	​

=T
compute
	​

/p+T
communication
	​

+T
coordination
	​


As p increases:

Compute term decreases.

Coordination overhead increases.

Master may become bottleneck.

Conclusion

Dynamic scheduling improves load balance but introduces central coordination cost.

Q5 – Perfect Number Search
Computational Nature

Divisor summation per number.

Higher computational intensity per task.

Workload irregularity.

Behavior

Similar to Q4 but with heavier per-task computation.

Scalability

Better scaling than light workloads.

Eventually limited by master communication and synchronization.

Conclusion

Master–slave architecture provides flexibility but does not scale infinitely.

4. Comparative Theoretical Insights
Problem	Compute Intensity	Communication	Scalability
Q1	Low–Moderate	High (Scatter/Gather)	Limited
Q2	Low	Communication-dominated	MPI_Bcast scales well
Q3	High	Very Low	Strong scaling
Q4	Moderate	Frequent coordination	Medium
Q5	High	Frequent coordination	Medium
5. Overall Conclusions

Scalability depends primarily on compute-to-communication ratio.

Collective MPI operations are more efficient than manual message passing.

Embarrassingly parallel problems scale better.

Master–slave models improve load balance but introduce central bottlenecks.

Amdahl’s Law limits achievable speedup.

6. Graphs to Include

For a strong theoretical submission, include:

1. Execution Time vs Processes (All Problems)

Shows scalability trend.

2. Speedup vs Processes (Q1 & Q3)

Include ideal linear speedup line for comparison.

3. Manual vs MPI_Bcast Comparison (Q2)

Clearly demonstrates algorithmic complexity difference.

4. Efficiency vs Processes (Optional but recommended)

Shows diminishing returns.

7. Final Theoretical Statement

This assignment demonstrates that parallel performance is governed not only by computation division but also by communication overhead, synchronization cost, load balancing strategy, and inherent serial components of the algorithm. Effective parallel design requires minimizing communication while maximizing independent computation.
