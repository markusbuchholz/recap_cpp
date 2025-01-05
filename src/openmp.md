
# C++ OpenMP Recap


## Table of Contents

1. [Introduction to OpenMP](#1-introduction-to-openmp)
2. [Basic OpenMP Directives](#2-basic-openmp-directives)
    - [2.1. Parallel Regions](#21-parallel-regions)
    - [2.2. Parallel For Loops](#22-parallel-for-loops)
    - [2.3. Parallel Sections](#23-parallel-sections)
3. [Work-Sharing Constructs](#3-work-sharing-constructs)
    - [3.1. for Directive](#31-for-directive)
    - [3.2. sections Directive](#32-sections-directive)
    - [3.3. single Directive](#33-single-directive)
4. [Synchronization Constructs](#4-synchronization-constructs)
    - [4.1. Critical Sections](#41-critical-sections)
    - [4.2. Atomic Operations](#42-atomic-operations)
    - [4.3. Barriers](#43-barriers)
5. [Reduction Operations](#5-reduction-operations)
    - [5.1. Simple Reduction](#51-simple-reduction)
    - [5.2. Custom Reduction](#52-custom-reduction)
6. [Advanced Features](#6-advanced-features)
    - [6.1. Task Parallelism](#61-task-parallelism)
    - [6.2. Nested Parallelism](#62-nested-parallelism)
    - [6.3. Threadprivate Variables](#63-threadprivate-variables)
7. [Performance Considerations](#7-performance-considerations)
    - [7.1. Load Balancing](#71-load-balancing)
    - [7.2. False Sharing](#72-false-sharing)
8. [Summary](#8-summary)


---

## 1. Introduction to OpenMP

### Description

**OpenMP** is an API that supports multi-platform shared memory multiprocessing programming in C, C++, and Fortran. It enables developers to write parallel code using compiler directives, library routines, and environment variables. OpenMP simplifies parallel programming by abstracting the complexities of thread management, synchronization, and data sharing. <br>

- [introduction](https://hpc-tutorials.llnl.gov/openmp/introduction/)
- [OpenMP-API specification](https://www.openmp.org/wp-content/uploads/OpenMP-API-Specification-5-2.pdf)

### Key Features

- **Compiler Directives**: Pragmas that instruct the compiler to parallelize code sections.
- **Dynamic Thread Management**: Ability to adjust the number of threads at runtime.
- **Work-Sharing Constructs**: Efficient division of work among threads.
- **Synchronization Constructs**: Mechanisms to prevent race conditions and ensure data integrity.
- **Scalability**: Supports nested parallelism and task-based parallelism for complex applications.

---

## 2. Basic OpenMP Directives

### 2.1. Parallel Regions

#### Description

A **parallel region** defines a block of code that will be executed by multiple threads simultaneously. Each thread has its own copy of variables unless specified otherwise.

#### Example 1: Basic Parallel Region

```cpp
// File: parallel_region.cpp
#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        std::cout << "Hello from thread " << thread_id << "\n";
    }
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp parallel_region.cpp -o parallel_region
```

**Output:**
```
Hello from thread 0
Hello from thread 1
Hello from thread 2
Hello from thread 3
```

*Note: The number of threads and their IDs may vary based on the system and OpenMP settings.*

---

### 2.2. Parallel For Loops

#### Description

The **parallel for loop** distributes loop iterations among available threads, enabling concurrent execution of loop bodies.

#### Example 2: Parallel For Loop

```cpp
// File: parallel_for.cpp
#include <iostream>
#include <omp.h>

int main() {
    const int N = 10;
    int arr[N];

    #pragma omp parallel for
    for(int i = 0; i < N; ++i) {
        arr[i] = i * i;
        int thread_id = omp_get_thread_num();
        std::cout << "Thread " << thread_id << " computed arr[" << i << "] = " << arr[i] << "\n";
    }

    std::cout << "\nArray Contents:\n";
    for(int i = 0; i < N; ++i)
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp parallel_for.cpp -o parallel_for
```

**Output:**
```
Thread 0 computed arr[0] = 0
Thread 1 computed arr[1] = 1
Thread 2 computed arr[2] = 4
Thread 3 computed arr[3] = 9
Thread 0 computed arr[4] = 16
Thread 1 computed arr[5] = 25
Thread 2 computed arr[6] = 36
Thread 3 computed arr[7] = 49
Thread 0 computed arr[8] = 64
Thread 1 computed arr[9] = 81

Array Contents:
arr[0] = 0
arr[1] = 1
arr[2] = 4
arr[3] = 9
arr[4] = 16
arr[5] = 25
arr[6] = 36
arr[7] = 49
arr[8] = 64
arr[9] = 81
```

*Note: The order of thread outputs may vary.*

---

### 2.3. Parallel Sections

#### Description

The **parallel sections** construct allows different sections of code to be executed concurrently by different threads. It's useful when tasks are independent and can be performed in parallel.

#### Example 3: Parallel Sections

```cpp
// File: parallel_sections.cpp
#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            std::cout << "Section 1 executed by thread " << omp_get_thread_num() << "\n";
        }

        #pragma omp section
        {
            std::cout << "Section 2 executed by thread " << omp_get_thread_num() << "\n";
        }

        #pragma omp section
        {
            std::cout << "Section 3 executed by thread " << omp_get_thread_num() << "\n";
        }
    }
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp parallel_sections.cpp -o parallel_sections
```

**Output:**
```
Section 1 executed by thread 0
Section 2 executed by thread 1
Section 3 executed by thread 2
```

*Note: The number of sections and thread assignments may vary.*

---

## 3. Work-Sharing Constructs

### 3.1. for Directive

#### Description

The **for directive** is used within a parallel region to distribute loop iterations among threads. It optimizes loop execution by balancing the workload.

#### Example 1: Parallelizing a Computation-Intensive Loop

```cpp
// File: work_sharing_for.cpp
#include <iostream>
#include <omp.h>

int main() {
    const int N = 100;
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 1; i <= N; ++i) {
        sum += 1.0 / i;
    }

    std::cout << "Harmonic sum of first " << N << " terms: " << sum << "\n";
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp work_sharing_for.cpp -o work_sharing_for
```

**Output:**
```
Harmonic sum of first 100 terms: 5.18738
```

*Note: The actual sum may vary slightly due to floating-point precision.*

---

### 3.2. sections Directive

#### Description

The **sections directive** allows multiple code blocks (sections) to be executed in parallel by different threads. Each section is executed by one thread.

#### Example 2: Parallel Processing of Independent Tasks

```cpp
// File: work_sharing_sections.cpp
#include <iostream>
#include <omp.h>
#include <cmath>

void computeSqrt(int id, double num) {
    double result = sqrt(num);
    std::cout << "Thread " << id << " computed sqrt(" << num << ") = " << result << "\n";
}

int main() {
    double numbers[] = {16.0, 25.0, 36.0, 49.0};

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            computeSqrt(omp_get_thread_num(), numbers[0]);
        }

        #pragma omp section
        {
            computeSqrt(omp_get_thread_num(), numbers[1]);
        }

        #pragma omp section
        {
            computeSqrt(omp_get_thread_num(), numbers[2]);
        }

        #pragma omp section
        {
            computeSqrt(omp_get_thread_num(), numbers[3]);
        }
    }

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp work_sharing_sections.cpp -o work_sharing_sections
```

**Output:**
```
Thread 0 computed sqrt(16) = 4
Thread 1 computed sqrt(25) = 5
Thread 2 computed sqrt(36) = 6
Thread 3 computed sqrt(49) = 7
```

*Note: Thread assignments may vary.*

---

### 3.3. single Directive

#### Description

The **single directive** ensures that a particular section of code is executed by only one thread in a parallel region. It's useful for tasks that should not be duplicated, such as initializing shared resources.

#### Example 3: Initializing Shared Resource Once

```cpp
// File: work_sharing_single.cpp
#include <iostream>
#include <omp.h>
#include <vector>

int main() {
    std::vector<int> data;

    #pragma omp parallel
    {
        #pragma omp single
        {
            std::cout << "Thread " << omp_get_thread_num() << " is initializing data.\n";
            for(int i = 0; i < 10; ++i)
                data.push_back(i * i);
        }

        // All threads can now use 'data'
        #pragma omp for
        for(int i = 0; i < data.size(); ++i) {
            std::cout << "Thread " << omp_get_thread_num() << " processing data[" << i << "] = " << data[i] << "\n";
        }
    }

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp work_sharing_single.cpp -o work_sharing_single
```

**Output:**
```
Thread 0 is initializing data.
Thread 1 processing data[0] = 0
Thread 2 processing data[1] = 1
Thread 3 processing data[2] = 4
Thread 0 processing data[3] = 9
Thread 1 processing data[4] = 16
Thread 2 processing data[5] = 25
Thread 3 processing data[6] = 36
Thread 0 processing data[7] = 49
Thread 1 processing data[8] = 64
Thread 2 processing data[9] = 81
```

*Note: The thread executing the single directive may vary.*

---

## 4. Synchronization Constructs

### 4.1. Critical Sections

#### Description

The **critical section** ensures that only one thread executes a particular section of code at a time, preventing race conditions when accessing shared resources.

#### Example 1: Preventing Race Conditions with Critical

```cpp
// File: synchronization_critical.cpp
#include <iostream>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel for
    for(int i = 0; i < 1000; ++i) {
        #pragma omp critical
        {
            ++counter;
        }
    }

    std::cout << "Final counter value: " << counter << "\n";
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp synchronization_critical.cpp -o synchronization_critical
```

**Output:**
```
Final counter value: 1000
```

*Note: Without the critical section, the final counter value could be less than 1000 due to race conditions.*

---

### 4.2. Atomic Operations

#### Description

The **atomic directive** ensures that a specific memory location is updated atomically, providing a lightweight synchronization mechanism compared to critical sections. It's suitable for simple operations like increments or additions.

#### Example 2: Using Atomic for Safe Increment

```cpp
// File: synchronization_atomic.cpp
#include <iostream>
#include <omp.h>

int main() {
    int counter = 0;

    #pragma omp parallel for
    for(int i = 0; i < 1000; ++i) {
        #pragma omp atomic
        ++counter;
    }

    std::cout << "Final counter value: " << counter << "\n";
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp synchronization_atomic.cpp -o synchronization_atomic
```

**Output:**
```
Final counter value: 1000
```

*Note: Atomic operations are faster but limited to simple operations.*

---

### 4.3. Barriers

#### Description

A **barrier** synchronizes all threads at a certain point in the code, ensuring that no thread proceeds beyond the barrier until all have reached it. It's useful for coordinating phases of parallel computation.

#### Example 3: Using Barrier to Synchronize Threads

```cpp
// File: synchronization_barrier.cpp
#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();
        std::cout << "Thread " << thread_id << " performing initial work.\n";

        // Synchronize all threads here
        #pragma omp barrier

        if(thread_id == 0) {
            std::cout << "All threads have reached the barrier.\n";
        }

        std::cout << "Thread " << thread_id << " proceeding after barrier.\n";
    }
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp synchronization_barrier.cpp -o synchronization_barrier
```

**Output:**
```
Thread 0 performing initial work.
Thread 1 performing initial work.
Thread 2 performing initial work.
Thread 3 performing initial work.
All threads have reached the barrier.
Thread 0 proceeding after barrier.
Thread 1 proceeding after barrier.
Thread 2 proceeding after barrier.
Thread 3 proceeding after barrier.
```

*Note: The order of initial work messages may vary.*

---

## 5. Reduction Operations

### 5.1. Simple Reduction

#### Description

The **reduction clause** allows the accumulation of values across threads, such as summing elements or finding the maximum value. It handles the necessary synchronization to ensure correct results.

#### Example 1: Summing Array Elements with Reduction

```cpp
// File: reduction_simple.cpp
#include <iostream>
#include <omp.h>

int main() {
    const int N = 1000;
    double array[N];
    for(int i = 0; i < N; ++i)
        array[i] = 1.0; // Initialize all elements to 1.0

    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for(int i = 0; i < N; ++i) {
        sum += array[i];
    }

    std::cout << "Sum of array elements: " << sum << "\n";
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp reduction_simple.cpp -o reduction_simple
```

**Output:**
```
Sum of array elements: 1000
```

---

### 5.2. Custom Reduction

#### Description

OpenMP allows defining **custom reduction operations** for user-defined types or complex aggregation logic.

#### Example 2: Custom Reduction for Vector Addition

```cpp
// File: reduction_custom.cpp
#include <iostream>
#include <omp.h>
#include <vector>

struct Vec {
    double x, y, z;

    Vec() : x(0), y(0), z(0) {}
    Vec(double a, double b, double c) : x(a), y(b), z(c) {}

    Vec operator+(const Vec &other) const {
        return Vec(x + other.x, y + other.y, z + other.z);
    }
};

// Define a custom reduction operation for Vec
#pragma omp declare reduction(vec_add : Vec : omp_out = omp_out + omp_in) initializer(omp_priv = Vec())

int main() {
    const int N = 100;
    std::vector<Vec> vectors(N, Vec(1.0, 2.0, 3.0)); // Initialize 100 vectors

    Vec total;

    #pragma omp parallel for reduction(vec_add:total)
    for(int i = 0; i < N; ++i) {
        total = total + vectors[i];
    }

    std::cout << "Total Vector: (" << total.x << ", " << total.y << ", " << total.z << ")\n";
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp reduction_custom.cpp -o reduction_custom
```

**Output:**
```
Total Vector: (100, 200, 300)
```

*Explanation: Each vector has (1,2,3). Summing 100 vectors results in (100,200,300).*

---

## 6. Advanced Features

### 6.1. Task Parallelism

#### Description

**Task parallelism** allows defining tasks that can be executed concurrently, enabling more flexible parallel execution patterns beyond loop-based parallelism.

#### Example 1: Creating and Executing Tasks

```cpp
// File: task_parallelism.cpp
#include <iostream>
#include <omp.h>
#include <cmath>

void compute(int id, double num) {
    double result = sqrt(num);
    std::cout << "Task " << id << " computed sqrt(" << num << ") = " << result << "\n";
}

int main() {
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            compute(1, 25.0);

            #pragma omp task
            compute(2, 49.0);

            #pragma omp task
            compute(3, 81.0);
        }
    }
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp task_parallelism.cpp -o task_parallelism
```

**Output:**
```
Task 1 computed sqrt(25) = 5
Task 2 computed sqrt(49) = 7
Task 3 computed sqrt(81) = 9
```

*Note: The order of task execution may vary.*

---

### 6.2. Nested Parallelism

#### Description

**Nested parallelism** allows creating parallel regions within parallel regions. It can enhance performance for certain applications but may introduce overhead if not managed properly.

#### Example 2: Enabling Nested Parallelism

```cpp
// File: nested_parallelism.cpp
#include <iostream>
#include <omp.h>

int main() {
    // Enable nested parallelism
    omp_set_nested(1);

    #pragma omp parallel num_threads(2)
    {
        int outer_thread = omp_get_thread_num();
        std::cout << "Outer Parallel Region - Thread " << outer_thread << "\n";

        #pragma omp parallel num_threads(2)
        {
            int inner_thread = omp_get_thread_num();
            std::cout << "  Inner Parallel Region - Thread " << inner_thread << " (from outer thread " << outer_thread << ")\n";
        }
    }
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp nested_parallelism.cpp -o nested_parallelism
```

**Output:**
```
Outer Parallel Region - Thread 0
  Inner Parallel Region - Thread 0 (from outer thread 0)
  Inner Parallel Region - Thread 1 (from outer thread 0)
Outer Parallel Region - Thread 1
  Inner Parallel Region - Thread 0 (from outer thread 1)
  Inner Parallel Region - Thread 1 (from outer thread 1)
```

*Note: The actual number of threads may vary based on system capabilities and OpenMP settings.*

---

### 6.3. Threadprivate Variables

#### Description

**Threadprivate variables** allow each thread to have its own instance of a variable, preventing data races and ensuring thread-specific data storage.

#### Example 3: Using Threadprivate Variables

```cpp
// File: threadprivate_variables.cpp
#include <iostream>
#include <omp.h>

int counter = 0;
#pragma omp threadprivate(counter)

int main() {
    #pragma omp parallel num_threads(4)
    {
        counter = omp_get_thread_num() * 10;
        std::cout << "Thread " << omp_get_thread_num() << " has counter = " << counter << "\n";
    }

    // Outside parallel region
    std::cout << "Outside parallel region:\n";
    std::cout << "Counter: " << counter << "\n"; // Last thread's counter

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp threadprivate_variables.cpp -o threadprivate_variables
```

**Output:**
```
Thread 0 has counter = 0
Thread 1 has counter = 10
Thread 2 has counter = 20
Thread 3 has counter = 30
Outside parallel region:
Counter: 30
```

*Note: Each thread has its own `counter` variable. The main thread accesses the last thread's `counter` value.*

---

## 7. Performance Considerations

### 7.1. Load Balancing

#### Description

**Load balancing** ensures that work is evenly distributed among threads to prevent some threads from being idle while others are overloaded, maximizing parallel efficiency.

#### Example 1: Using Dynamic Scheduling for Load Balancing

```cpp
// File: load_balancing.cpp
#include <iostream>
#include <omp.h>

int main() {
    const int N = 20;

    #pragma omp parallel for schedule(dynamic, 2)
    for(int i = 0; i < N; ++i) {
        int thread_id = omp_get_thread_num();
        std::cout << "Thread " << thread_id << " processing iteration " << i << "\n";
    }

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp load_balancing.cpp -o load_balancing
```

**Output:**
```
Thread 0 processing iteration 0
Thread 1 processing iteration 1
Thread 2 processing iteration 2
Thread 3 processing iteration 3
Thread 0 processing iteration 4
Thread 1 processing iteration 5
...
```

*Note: The dynamic scheduling assigns chunks of iterations to threads as they become available, promoting better load balancing.*

---

### 7.2. False Sharing

#### Description

**False sharing** occurs when threads on different processors modify variables that reside on the same cache line, leading to performance degradation. It can be mitigated by aligning or padding data structures.

#### Example 2: Demonstrating False Sharing

```cpp
// File: false_sharing.cpp
#include <iostream>
#include <omp.h>
#include <vector>

struct alignas(64) Counter {
    int value;
};

int main() {
    const int num_threads = 4;
    std::vector<Counter> counters(num_threads, Counter{0});

    #pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();
        for(int i = 0; i < 1000000; ++i) {
            counters[thread_id].value++;
        }
    }

    for(int i = 0; i < num_threads; ++i)
        std::cout << "Counter[" << i << "] = " << counters[i].value << "\n";

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -fopenmp false_sharing.cpp -o false_sharing
```

**Output:**
```
Counter[0] = 1000000
Counter[1] = 1000000
Counter[2] = 1000000
Counter[3] = 1000000
```

*Note: Using `alignas(64)` ensures each `Counter` is on a separate cache line, preventing false sharing.*

---

## 8. Summary

OpenMP is a powerful tool for parallel programming in C++, simplifying the development of multi-threaded applications. Here's a quick overview of the topics covered:

- **Introduction to OpenMP**: Understanding the basics and key features.
- **Basic OpenMP Directives**:
  - **Parallel Regions**: Defining blocks of code for parallel execution.
  - **Parallel For Loops**: Distributing loop iterations among threads.
  - **Parallel Sections**: Executing independent code sections concurrently.
- **Work-Sharing Constructs**:
  - **for Directive**: Efficient loop parallelization with work-sharing.
  - **sections Directive**: Dividing independent tasks among threads.
  - **single Directive**: Executing code blocks by a single thread.
- **Synchronization Constructs**:
  - **Critical Sections**: Preventing race conditions in shared resources.
  - **Atomic Operations**: Ensuring atomic updates for simple operations.
  - **Barriers**: Synchronizing threads at specific points.
- **Reduction Operations**:
  - **Simple Reduction**: Aggregating values across threads.
  - **Custom Reduction**: Defining reductions for user-defined types.
- **Advanced Features**:
  - **Task Parallelism**: Executing independent tasks concurrently.
  - **Nested Parallelism**: Creating parallel regions within parallel regions.
  - **Threadprivate Variables**: Maintaining thread-specific data.
- **Performance Considerations**:
  - **Load Balancing**: Distributing workload evenly among threads.
  - **False Sharing**: Optimizing data structures to prevent cache contention.

