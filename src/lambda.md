# C++ Lambda Functions

## Table of Contents

1. [Introduction to Lambda Functions](#1-introduction-to-lambda-functions)
2. [Lambda Function Syntax](#2-lambda-function-syntax)
3. [Captures in Lambda Functions](#3-captures-in-lambda-functions)
4. [Common Usages with Standard Algorithms](#4-common-usages-with-standard-algorithms)
    - [4.1. `std::for_each`](#41-stdforeach)
    - [4.2. `std::sort`](#42-stdsort)
    - [4.3. `std::find_if`](#43-stdfind_if)
    - [4.4. `std::transform`](#44-stdtransform)
    - [4.5. `std::accumulate`](#45-stdaccumulate)
    - [4.6. `std::remove_if`](#46-stdremove_if)
    - [4.7. `std::count_if`](#47-stdcount_if)
    - [4.8. `std::partition`](#48-stdpartition)
    - [4.9. `std::binary_search`](#49-stdbinary_search)
    - [4.10. `std::any_of`, `std::all_of`, `std::none_of`](#410-stdany_of-stdall_of-stdnone_of)
5. [Advanced Lambda Features](#5-advanced-lambda-features)
6. [Best Practices](#6-best-practices)
7. [Performance Considerations](#7-performance-considerations)
8. [Conclusion](#8-conclusion)

---

## 1. Introduction to Lambda Functions

Lambda functions are **anonymous**, **inline**, **function objects** defined directly in the code where they are used. They are particularly useful for short operations where defining a separate named function would be unnecessarily verbose.

**Benefits of Lambda Functions:**
- **Conciseness:** Reduce boilerplate code by eliminating the need for separate function declarations.
- **Flexibility:** Easily capture local variables from the surrounding context.
- **Readability:** Keep related logic close together, enhancing code clarity.

---

## 2. Lambda Function Syntax

A lambda function in C++ has the following general syntax:

```cpp
[captures] (parameters) -> return_type {
    // function body
};
```

**Components:**
- **Capture List (`[]`):** Specifies which variables from the surrounding scope are accessible within the lambda.
- **Parameters (`()`):** Defines the input parameters, similar to regular functions.
- **Return Type (`-> return_type`):** (Optional) Specifies the return type. Often omitted due to type inference.
- **Function Body (`{}`):** Contains the executable code.

**Basic Example:**

```cpp
auto greet = []() {
    std::cout << "Hello, World!\n";
};

greet(); // Outputs: Hello, World!
```

---

## 3. Captures in Lambda Functions

The **capture list** determines how the lambda accesses variables from its surrounding scope. There are several ways to capture variables:

### 3.1. Capture by Value `[=]`

All variables used inside the lambda are captured **by value**, meaning a copy is made.

```cpp
int x = 10;
auto printX = [=]() {
    std::cout << "x = " << x << "\n";
};
```

### 3.2. Capture by Reference `[&]`

All variables used inside the lambda are captured **by reference**, allowing modification of the original variables.

```cpp
int x = 10;
auto incrementX = [&]() {
    x++;
};
```

### 3.3. Mixed Captures

You can specify a default capture mode and override specific variables.

```cpp
int x = 10;
int y = 20;

// Capture all by value, but capture y by reference
auto func = [=, &y]() {
    // x is captured by value, y by reference
};
```

### 3.4. Explicit Captures

Capture specific variables, either by value or by reference.

```cpp
int x = 10;
int y = 20;

// Capture x by value and y by reference
auto func = [x, &y]() {
    // ...
};
```

### 3.5. Capturing `this`

When working within a class, you can capture the `this` pointer to access class members.

```cpp
class MyClass {
    int value;
public:
    void printValue() {
        auto func = [this]() {
            std::cout << "Value: " << value << "\n";
        };
        func();
    }
};
```

---

## 4. Common Usages with Standard Algorithms

Lambda functions shine when used with C++ Standard Library algorithms. Below are some common algorithms paired with lambda examples.

### 4.1. `std::for_each`

Applies a function to each element in a range.

**Example: Printing Elements**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 1 2 3 4 5 
    return 0;
}
```

**Example: Modifying Elements**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::for_each(vec.begin(), vec.end(), [](int &x) {
        x *= 2;
    });
    
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 2 4 6 8 10 
    return 0;
}
```

### 4.2. `std::sort`

Sorts elements in a range. By default, in ascending order, but can be customized with a comparator.

**Example: Sorting in Ascending Order (Default)**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {50, 20, 40, 10, 30};
    
    std::sort(vec.begin(), vec.end());
    
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 10 20 30 40 50 
    return 0;
}
```

**Example: Sorting in Descending Order (Custom Comparator)**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {50, 20, 40, 10, 30};
    
    std::sort(vec.begin(), vec.end(), [](int a, int b) -> bool {
        return a > b; // Descending order
    });
    
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 50 40 30 20 10 
    return 0;
}
```

**Example: Sorting Strings by Length**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "kiwi", "banana", "fig", "cherry"};
    
    std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) -> bool {
        return a.length() < b.length();
    });
    
    std::for_each(words.begin(), words.end(), [](const std::string &s) {
        std::cout << s << " ";
    });
    std::cout << "\n"; // Output: fig kiwi apple banana cherry 
    return 0;
}
```

### 4.3. `std::find_if`

Finds the first element in a range that satisfies a predicate.

**Example: Finding the First Even Number**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 5, 6, 7, 8};
    
    auto it = std::find_if(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    if(it != vec.end()) {
        std::cout << "First even number: " << *it << "\n"; // Output: 6
    } else {
        std::cout << "No even number found.\n";
    }
    
    return 0;
}
```

**Example: Finding the First String Longer Than 5 Characters**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "banana", "fig", "cherry", "date"};
    
    auto it = std::find_if(words.begin(), words.end(), [](const std::string &s) -> bool {
        return s.length() > 5;
    });
    
    if(it != words.end()) {
        std::cout << "First word longer than 5 characters: " << *it << "\n"; // Output: banana
    } else {
        std::cout << "No word longer than 5 characters found.\n";
    }
    
    return 0;
}
```

### 4.4. `std::transform`

Applies a function to each element in a range and stores the result in another range.

**Example: Squaring Each Element**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination(source.size());
    
    std::transform(source.begin(), source.end(), destination.begin(), [](int x) -> int {
        return x * x;
    });
    
    std::for_each(destination.begin(), destination.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 1 4 9 16 25 
    return 0;
}
```

**Example: Converting Characters to Uppercase**

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string source = "Hello World";
    std::string destination(source.size(), ' ');
    
    std::transform(source.begin(), source.end(), destination.begin(), [](char c) -> char {
        return std::toupper(c);
    });
    
    std::cout << "Uppercase string: " << destination << "\n"; // Output: HELLO WORLD
    return 0;
}
```

**Example: Merging Two Vectors Element-wise**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> merged(vec1.size());
    
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), merged.begin(), [](int a, int b) -> int {
        return a + b;
    });
    
    std::for_each(merged.begin(), merged.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 5 7 9 
    return 0;
}
```

### 4.5. `std::accumulate`

While `std::accumulate` is part of the `<numeric>` header and not `<algorithm>`, it's commonly used alongside algorithms. It computes the sum (or other accumulation) of elements in a range.

**Example: Summing Elements**

```cpp
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    int sum = std::accumulate(vec.begin(), vec.end(), 0, [](int total, int x) -> int {
        return total + x;
    });
    
    std::cout << "Sum of elements: " << sum << "\n"; // Output: 15
    return 0;
}
```

**Example: Concatenating Strings**

```cpp
#include <iostream>
#include <numeric>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"Hello", " ", "World", "!"};
    
    std::string sentence = std::accumulate(words.begin(), words.end(), std::string(),
        [](const std::string &a, const std::string &b) -> std::string {
            return a + b;
        });
    
    std::cout << "Concatenated string: " << sentence << "\n"; // Output: Hello World!
    return 0;
}
```

### 4.6. `std::remove_if`

Removes elements that satisfy a predicate by shifting non-matching elements forward. The container size remains unchanged; to actually remove elements, use `erase`.

**Example: Removing Odd Numbers**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    
    auto newEnd = std::remove_if(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 != 0;
    });
    
    vec.erase(newEnd, vec.end());
    
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    std::cout << "\n"; // Output: 2 4 6 
    return 0;
}
```

**Example: Removing Vowels from a String**

```cpp
#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string s = "Hello World";
    
    auto newEnd = std::remove_if(s.begin(), s.end(), [](char c) -> bool {
        return std::strchr("AEIOUaeiou", c) != nullptr;
    });
    
    s.erase(newEnd, s.end());
    
    std::cout << "After removing vowels: " << s << "\n"; // Output: Hll Wrld
    return 0;
}
```

### 4.7. `std::count_if`

Counts the number of elements that satisfy a predicate.

**Example: Counting Even Numbers**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 4, 5, 6, 7, 8};
    
    int count = std::count_if(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "Number of even elements: " << count << "\n"; // Output: 4
    return 0;
}
```

**Example: Counting Strings Starting with 'A'**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"Apple", "Banana", "Apricot", "Cherry", "Avocado"};
    
    int count = std::count_if(words.begin(), words.end(), [](const std::string &s) -> bool {
        return !s.empty() && s[0] == 'A';
    });
    
    std::cout << "Number of words starting with 'A': " << count << "\n"; // Output: 3
    return 0;
}
```

### 4.8. `std::partition`

Rearranges elements in a range so that elements satisfying a predicate come before those that do not. The relative order within each group is not preserved.

**Example: Partitioning Even and Odd Numbers**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 4, 3, 6, 7, 8, 2, 5};
    
    std::partition(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "After partitioning (evens first): ";
    for(auto x : vec)
        std::cout << x << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Possible Output:**
```
After partitioning (evens first): 4 6 8 2 7 5 3 1 
```

**Example: Partitioning Strings by Length**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"apple", "kiwi", "banana", "fig", "cherry"};
    
    std::partition(words.begin(), words.end(), [](const std::string &s) -> bool {
        return s.length() > 4;
    });
    
    std::cout << "After partitioning (length > 4 first): ";
    for(auto &s : words)
        std::cout << s << " ";
    std::cout << "\n";
    
    return 0;
}
```

**Possible Output:**
```
After partitioning (length > 4 first): apple banana cherry fig kiwi 
```

### 4.9. `std::binary_search`

Performs a binary search on a sorted range to determine if a value exists.

**Example: Binary Searching in a Sorted Vector**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    
    int target = 30;
    
    bool found = std::binary_search(vec.begin(), vec.end(), target, [](int a, int b) -> bool {
        return a < b;
    });
    
    std::cout << "Is " << target << " in the vector? " << (found ? "Yes" : "No") << "\n"; // Output: Yes
    return 0;
}
```

**Example: Binary Searching with Custom Comparator**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> vec = {"apple", "banana", "cherry", "date", "fig"};
    
    std::string target = "Cherry";
    
    // Case-insensitive comparator
    auto cmp = [](const std::string &a, const std::string &b) -> bool {
        std::string lower_a = a, lower_b = b;
        std::transform(lower_a.begin(), lower_a.end(), lower_a.begin(), ::tolower);
        std::transform(lower_b.begin(), lower_b.end(), lower_b.begin(), ::tolower);
        return lower_a < lower_b;
    };
    
    // Sort the vector with the comparator
    std::sort(vec.begin(), vec.end(), cmp);
    
    bool found = std::binary_search(vec.begin(), vec.end(), target, cmp);
    
    std::cout << "Is \"" << target << "\" in the vector? " << (found ? "Yes" : "No") << "\n"; // Output: Yes
    return 0;
}
```

### 4.10. `std::any_of`, `std::all_of`, `std::none_of`

These algorithms check conditions across a range:

- **`std::any_of`**: Returns `true` if **any** element satisfies the predicate.
- **`std::all_of`**: Returns `true` if **all** elements satisfy the predicate.
- **`std::none_of`**: Returns `true` if **no** elements satisfy the predicate.

**Example: Using `std::any_of`**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9};
    
    bool hasEven = std::any_of(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "Vector has even numbers: " << (hasEven ? "Yes" : "No") << "\n"; // Output: No
    return 0;
}
```

**Example: Using `std::all_of`**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {2, 4, 6, 8, 10};
    
    bool allEven = std::all_of(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "All elements are even: " << (allEven ? "Yes" : "No") << "\n"; // Output: Yes
    return 0;
}
```

**Example: Using `std::none_of`**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 5, 7, 9};
    
    bool noneEven = std::none_of(vec.begin(), vec.end(), [](int x) -> bool {
        return x % 2 == 0;
    });
    
    std::cout << "No even numbers in the vector: " << (noneEven ? "Yes" : "No") << "\n"; // Output: Yes
    return 0;
}
```

---

## 5. Advanced Lambda Features

### 5.1. Mutable Lambdas

By default, lambda captures are **constant**. To modify captured variables (captured by value), use the `mutable` keyword.

**Example: Incrementing a Captured Variable**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int total = 0;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    std::for_each(vec.begin(), vec.end(), [total](int x) mutable {
        total += x;
        std::cout << "Running total: " << total << "\n";
    });
    
    std::cout << "Final total (original total remains unchanged): " << total << "\n"; // Output: 0
    return 0;
}
```

**Output:**
```
Running total: 1
Running total: 3
Running total: 6
Running total: 10
Running total: 15
Final total (original total remains unchanged): 0
```

*Note: The `total` inside the lambda is a separate copy and does not affect the original `total` variable.*

### 5.2. Generic Lambdas (C++14 and Later)

C++14 introduced **generic lambdas** that use `auto` in their parameter lists, allowing them to work with multiple types.

**Example: Generic Lambda with `std::for_each`**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words = {"Hello", "World"};
    
    std::for_each(words.begin(), words.end(), [](auto &s) {
        std::cout << s << " ";
    });
    std::cout << "\n"; // Output: Hello World 
    return 0;
}
```

### 5.3. Capturing Move-Only Types

Sometimes you need to capture objects that are move-only (e.g., `std::unique_ptr`). Use `std::move` in the capture list.

**Example: Capturing `std::unique_ptr` by Move**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<int>> vec;
    vec.emplace_back(std::make_unique<int>(10));
    vec.emplace_back(std::make_unique<int>(20));
    
    std::for_each(vec.begin(), vec.end(), [ptr = std::move(vec[0])](const std::unique_ptr<int> &x) {
        if(ptr) {
            std::cout << "Captured unique_ptr value: " << *ptr << "\n";
        }
        if(x) {
            std::cout << "Element value: " << *x << "\n";
        }
    });
    
    return 0;
}
```

**Output:**
```
Captured unique_ptr value: 10
Element value: 20
```

*Note: After moving `vec[0]` into the lambda, `vec[0]` becomes `nullptr`.*

---

## 6. Best Practices

- **Keep Lambdas Short:** Use lambdas for small, concise operations. For more complex logic, consider defining a separate function or using `std::bind`.
  
- **Capture Wisely:** Only capture the variables you need. Prefer capturing by value when you don't need to modify the original variables, and capture by reference when necessary.
  
- **Avoid Unnecessary Copies:** When capturing large objects by value, it may lead to performance issues. Capture by reference or use `std::move` if appropriate.
  
- **Use Explicit Return Types:** While often optional, specifying return types can improve code clarity, especially for complex expressions.
  
- **Leverage Generic Lambdas:** Utilize `auto` parameters for flexibility, especially when working with templates or multiple types.

---

## 7. Performance Considerations

Lambda functions are generally efficient as they are **inlined** by the compiler, eliminating function call overhead. However, be mindful of:

- **Capturing by Value:** Copying large objects can be costly. Prefer capturing by reference or move semantics when dealing with large data structures.
  
- **Mutable Lambdas:** Modifying captured variables can lead to copies, which might not reflect outside the lambda's scope. Ensure this behavior aligns with your intentions.
  
- **Generic Lambdas:** They can lead to code bloat if used extensively with many types due to the creation of separate function objects for each type.

---

## 8. Conclusion

Lambda functions are a cornerstone of modern C++ programming, offering a blend of flexibility and conciseness. When paired with Standard Library algorithms, they empower developers to write expressive and efficient code. By understanding their syntax, capture mechanisms, and best practices, you can harness their full potential to create robust and maintainable applications.

---

## Appendix: Full Example Integrating Multiple Algorithms with Lambdas

To illustrate the synergy between lambda functions and multiple algorithms, here's a comprehensive example that performs various operations on a dataset.

**Scenario:** You have a list of students with their names and scores. You want to:

1. Print all students.
2. Increase scores of students below a threshold.
3. Find students who passed.
4. Calculate the average score.
5. Sort students by score.
6. Remove students who failed.

**Code Example:**

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

struct Student {
    std::string name;
    double score;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 85.5},
        {"Bob", 67.0},
        {"Charlie", 92.3},
        {"David", 58.4},
        {"Eve", 76.8},
        {"Frank", 45.2},
        {"Grace", 88.9}
    };
    
    // 1. Print all students
    std::cout << "All Students:\n";
    std::for_each(students.begin(), students.end(), [](const Student &s) {
        std::cout << s.name << ": " << s.score << "\n";
    });
    std::cout << "\n";
    
    // 2. Increase scores below 60 by 10%
    std::for_each(students.begin(), students.end(), [](Student &s) {
        if(s.score < 60.0) {
            s.score *= 1.10;
            std::cout << "Increased " << s.name << "'s score to " << s.score << "\n";
        }
    });
    std::cout << "\n";
    
    // 3. Find students who passed (score >= 60)
    std::vector<Student> passed;
    std::copy_if(students.begin(), students.end(), std::back_inserter(passed), [](const Student &s) -> bool {
        return s.score >= 60.0;
    });
    
    std::cout << "Students who passed:\n";
    std::for_each(passed.begin(), passed.end(), [](const Student &s) {
        std::cout << s.name << ": " << s.score << "\n";
    });
    std::cout << "\n";
    
    // 4. Calculate average score
    double total = std::accumulate(students.begin(), students.end(), 0.0, [](double sum, const Student &s) -> double {
        return sum + s.score;
    });
    double average = total / students.size();
    std::cout << "Average score: " << average << "\n\n";
    
    // 5. Sort students by score in descending order
    std::sort(students.begin(), students.end(), [](const Student &a, const Student &b) -> bool {
        return a.score > b.score;
    });
    
    std::cout << "Students sorted by score (descending):\n";
    std::for_each(students.begin(), students.end(), [](const Student &s) {
        std::cout << s.name << ": " << s.score << "\n";
    });
    std::cout << "\n";
    
    // 6. Remove students who failed (score < 60)
    auto newEnd = std::remove_if(students.begin(), students.end(), [](const Student &s) -> bool {
        return s.score < 60.0;
    });
    students.erase(newEnd, students.end());
    
    std::cout << "Final list of students (only those who passed):\n";
    std::for_each(students.begin(), students.end(), [](const Student &s) {
        std::cout << s.name << ": " << s.score << "\n";
    });
    
    return 0;
}
```

**Expected Output:**
```
All Students:
Alice: 85.5
Bob: 67
Charlie: 92.3
David: 58.4
Eve: 76.8
Frank: 45.2
Grace: 88.9

Increased David's score to 64.24
Increased Frank's score to 49.72

Students who passed:
Alice: 85.5
Bob: 67
Charlie: 92.3
David: 64.24
Eve: 76.8
Grace: 88.9

Average score: 72.37

Students sorted by score (descending):
Charlie: 92.3
Grace: 88.9
Alice: 85.5
Eve: 76.8
David: 64.24
Bob: 67
Frank: 49.72

Final list of students (only those who passed):
Charlie: 92.3
Grace: 88.9
Alice: 85.5
Eve: 76.8
David: 64.24
Bob: 67
```

