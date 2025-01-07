# Parallel Algorithms with `std::execution::par` in C++

This repository demonstrates how to use parallel algorithms in C++ with the `std::execution::par` policy introduced in C++17. These examples showcase the power of parallelism for improved performance on multicore systems.

- [execution_policy](https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag)

---
The main differences between the execution policies in C++ (`std::execution::seq`, `std::execution::par`, `std::execution::par_unseq`, and `std::execution::unseq`) lie in their behavior regarding parallelism, vectorization, and determinism. <br>
These policies provide options for controlling how algorithms are executed to optimize performance.<br>

---

## Compilation

```bash
g++ -std=c++17 -pthread -ltbb program.cpp -o program
```



### 1. **`std::execution::seq` (Sequential Execution)**

- **Description**: Executes the algorithm sequentially, one element at a time, in the order they appear.
- **Parallelism**: None (single-threaded).
- **Vectorization**: None.
- **Deterministic**: Yes (output is predictable and consistent).
- **Use case**: When performance is not critical, or debugging is needed for predictable and repeatable behavior.

**Example**:
```cpp
std::for_each(std::execution::seq, vec.begin(), vec.end(), [](int& x) { x *= 2; });
```

---

### 2. **`std::execution::par` (Parallel Execution)**

- **Description**: Executes the algorithm in parallel using multiple threads. Each thread works on a subset of the range.
- **Parallelism**: Yes (multithreaded).
- **Vectorization**: None.
- **Deterministic**: Not guaranteed (output may vary depending on thread scheduling).
- **Use case**: For large datasets or computationally expensive operations that benefit from multithreading.

**Example**:
```cpp
std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& x) { x *= 2; });
```

---

### 3. **`std::execution::par_unseq` (Parallel and Unsequenced Execution)**

- **Description**: Combines parallelism (multithreading) and vectorization (SIMD). It splits work across threads, and within each thread, operations are vectorized.
- **Parallelism**: Yes (multithreaded).
- **Vectorization**: Yes (SIMD within each thread).
- **Deterministic**: Not guaranteed (non-deterministic due to thread scheduling and SIMD).
- **Use case**: When maximizing performance is critical, and the order of operations or consistency is not a concern.

**Example**:
```cpp
std::for_each(std::execution::par_unseq, vec.begin(), vec.end(), [](int& x) { x *= 2; });
```

---

### 4. **`std::execution::unseq` (Unsequenced Execution)**

- **Description**: Focuses on vectorization only (SIMD). It processes multiple elements simultaneously in a single thread using vector instructions.
- **Parallelism**: No (single-threaded).
- **Vectorization**: Yes (SIMD).
- **Deterministic**: Not guaranteed (due to vectorization order).
- **Use case**: For operations that benefit from SIMD on a single thread (e.g., on smaller datasets or when multithreading is unnecessary).

**Example**:
```cpp
std::for_each(std::execution::unseq, vec.begin(), vec.end(), [](int& x) { x *= 2; });
```

---

### Comparison Table

| Policy                    | Parallelism   | Vectorization | Deterministic | Use Case                                       |
|---------------------------|---------------|---------------|---------------|------------------------------------------------|
| `std::execution::seq`     | No            | No            | Yes           | Debugging, predictable results, smaller datasets. |
| `std::execution::par`     | Yes           | No            | No            | Multithreaded tasks, large datasets, performance improvement. |
| `std::execution::par_unseq` | Yes           | Yes           | No            | Maximum performance with multithreading and SIMD. |
| `std::execution::unseq`   | No            | Yes           | No            | SIMD processing on single-threaded operations. |

---

## Algorithms Demonstrated
This repository includes examples of the following algorithms with parallel execution:
1. [`std::for_each`](#stdfor_each)
2. [`std::count`](#stdcount)
3. [`std::find`](#stdfind)
4. [`std::find_if`](#stdfind_if)
5. [`std::any_of`](#stdany_of)
6. [`std::find_if_not`](#stdfind_if_not)
7. [`std::all_of`](#stdall_of)
8. [`std::sort`](#stdsort)
9. [`std::binary_search`](#stdbinary_search)

---

### `std::for_each`
Applies a function to each element in a range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::for_each(std::execution::par, vec.begin(), vec.end(), [](int& x) {
        x *= 2;
    });

    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    return 0;
}
```

**Output:**
```
2 4 6 8 10
```

---

### `std::count`
Counts the occurrences of a specific value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{1, 2, 3, 2, 4, 2};
    int count = std::count(std::execution::par, vec.begin(), vec.end(), 2);

    std::cout << "Number of 2s: " << count << "\n";
    return 0;
}
```

**Output:**
```
Number of 2s: 3
```

---

### `std::find`
Finds the first occurrence of a specific value.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{1, 3, 5, 7, 9};
    auto it = std::find(std::execution::par, vec.begin(), vec.end(), 5);

    if (it != vec.end()) {
        std::cout << "Found 5 at position: " << std::distance(vec.begin(), it) << "\n";
    } else {
        std::cout << "5 not found.\n";
    }
    return 0;
}
```

**Output:**
```
Found 5 at position: 2
```

---

### `std::find_if`
Finds the first element that satisfies a condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{1, 3, 5, 7, 9};
    auto it = std::find_if(std::execution::par, vec.begin(), vec.end(), [](int x) {
        return x > 5;
    });

    if (it != vec.end()) {
        std::cout << "First element greater than 5: " << *it << "\n";
    } else {
        std::cout << "No element found.\n";
    }
    return 0;
}
```

**Output:**
```
First element greater than 5: 7
```

---

### `std::any_of`
Checks if any element satisfies a condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{1, 3, 5, 7, 9};
    bool result = std::any_of(std::execution::par, vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;
    });

    std::cout << "Contains even numbers: " << (result ? "Yes" : "No") << "\n";
    return 0;
}
```

**Output:**
```
Contains even numbers: No
```

---

### `std::find_if_not`
Finds the first element that does not satisfy a condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{2, 4, 6, 7, 8};
    auto it = std::find_if_not(std::execution::par, vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;
    });

    if (it != vec.end()) {
        std::cout << "First non-even element: " << *it << "\n";
    } else {
        std::cout << "All elements are even.\n";
    }
    return 0;
}
```

**Output:**
```
First non-even element: 7
```

---

### `std::all_of`
Checks if all elements satisfy a condition.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{2, 4, 6, 8, 10};
    bool result = std::all_of(std::execution::par, vec.begin(), vec.end(), [](int x) {
        return x % 2 == 0;
    });

    std::cout << "All elements are even: " << (result ? "Yes" : "No") << "\n";
    return 0;
}
```

**Output:**
```
All elements are even: Yes
```

---

### `std::sort`
Sorts the elements in ascending order.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{9, 3, 7, 1, 5};
    std::sort(std::execution::par, vec.begin(), vec.end());

    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    return 0;
}
```

**Output:**
```
1 3 5 7 9
```

---

### `std::binary_search`
Checks if a value exists in a sorted range.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main() {
    std::vector<int> vec{1, 3, 5, 7, 9};
    bool found = std::binary_search(std::execution::par, vec.begin(), vec.end(), 5);

    std::cout << "5 found: " << (found ? "Yes" : "No") << "\n";
    return 0;
}
```

**Output:**
```
5 found: Yes
```

---

## Notes
- The degree of speedup achieved with `std::execution::par` depends on the hardware, data size, and specific algorithm.
- Parallel execution policies are designed to optimize performance but may not always yield a speedup for small datasets.
- `std::binary_search` is inherently less parallelizable because of its sequential dependencies.

