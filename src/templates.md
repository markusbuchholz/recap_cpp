# C++ Templates Recap

## Table of Contents

1. [Introduction to Templates](#1-introduction-to-templates)
2. [Function Templates](#2-function-templates)
    - [2.1. Basic Function Template](#21-basic-function-template)
    - [2.2. Template with Multiple Parameters](#22-template-with-multiple-parameters)
    - [2.3. Template Argument Deduction](#23-template-argument-deduction)
3. [Class Templates](#3-class-templates)
    - [3.1. Basic Class Template](#31-basic-class-template)
    - [3.2. Template with Multiple Parameters](#32-template-with-multiple-parameters)
    - [3.3. Member Function Templates](#33-member-function-templates)
4. [Template Specialization](#4-template-specialization)
    - [4.1. Full Specialization](#41-full-specialization)
    - [4.2. Partial Specialization](#42-partial-specialization)
5. [Variadic Templates](#5-variadic-templates)
    - [5.1. Basic Variadic Template](#51-basic-variadic-template)
    - [5.2. Variadic Template with Recursion](#52-variadic-template-with-recursion)
6. [Template Metaprogramming](#6-template-metaprogramming)
    - [6.1. Compile-Time Calculations](#61-compile-time-calculations)
    - [6.2. Type Traits](#62-type-traits)
7. [Summary](#7-summary)

---

## 1. Introduction to Templates

### Description

**Templates** in C++ allow functions and classes to operate with generic types. This enables code reusability and type safety without sacrificing performance. Templates are a cornerstone of generic programming in C++ and are widely used in the Standard Template Library (STL).

There are two primary types of templates:

- **Function Templates**: Enable functions to operate with generic types.
- **Class Templates**: Enable classes to operate with generic types.

---

## 2. Function Templates

### Description

**Function Templates** allow you to write a single function that can work with different data types. The compiler generates the appropriate function code based on the arguments provided during function invocation.

### 2.1. Basic Function Template

#### Example 1: Generic Swap Function

```cpp
#include <iostream>

// Function template to swap two variables
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    swapValues(x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << "\n\n";

    double a = 1.5, b_d = 2.5;
    std::cout << "Before swap: a = " << a << ", b = " << b_d << "\n";
    swapValues(a, b_d);
    std::cout << "After swap: a = " << a << ", b = " << b_d << "\n";

    return 0;
}
```

**Output:**
```
Before swap: x = 10, y = 20
After swap: x = 20, y = 10

Before swap: a = 1.5, b = 2.5
After swap: a = 2.5, b = 1.5
```

---

### 2.2. Template with Multiple Parameters

#### Example 2: Function Template with Multiple Types

```cpp
#include <iostream>

// Function template to display two variables of possibly different types
template <typename T1, typename T2>
void displayPair(const T1 &first, const T2 &second) {
    std::cout << "First: " << first << ", Second: " << second << "\n";
}

int main() {
    displayPair(100, 3.14);
    displayPair("Hello", 200);
    displayPair('A', "World");
    
    return 0;
}
```

**Output:**
```
First: 100, Second: 3.14
First: Hello, Second: 200
First: A, Second: World
```

---

### 2.3. Template Argument Deduction

#### Example 3: Automatic Type Deduction

```cpp
#include <iostream>

// Function template to add two numbers
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    auto sum1 = add(5, 10);           // T deduced as int
    auto sum2 = add(2.5, 3.7);        // T deduced as double
    auto sum3 = add('A', 5);          // T deduced as char (promoted to int)

    std::cout << "Sum1: " << sum1 << "\n";
    std::cout << "Sum2: " << sum2 << "\n";
    std::cout << "Sum3: " << sum3 << "\n";

    return 0;
}
```

**Output:**
```
Sum1: 15
Sum2: 6.2
Sum3: 70
```

*Note: In `sum3`, `'A'` is promoted to its ASCII integer value `65`, so `65 + 5 = 70`.*

---

## 3. Class Templates

### Description

**Class Templates** allow you to define classes with generic types. This enables the creation of data structures and classes that can work with any data type, enhancing code reusability and flexibility.

### 3.1. Basic Class Template

#### Example 1: Generic Pair Class

```cpp
#include <iostream>

// Class template to hold a pair of values
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {}

    void display() const {
        std::cout << "(" << first << ", " << second << ")\n";
    }
};

int main() {
    Pair<int, double> p1(1, 2.5);
    p1.display();

    Pair<std::string, char> p2("Age", 'A');
    p2.display();

    Pair<char, char> p3('X', 'Y');
    p3.display();

    return 0;
}
```

**Output:**
```
(1, 2.5)
(Age, A)
(X, Y)
```

---

### 3.2. Template with Multiple Parameters

#### Example 2: Stack Class Template

```cpp
#include <iostream>
#include <vector>

// Class template for a generic Stack
template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T &item) {
        elements.push_back(item);
    }

    void pop() {
        if(!elements.empty())
            elements.pop_back();
    }

    T top() const {
        if(!elements.empty())
            return elements.back();
        throw std::out_of_range("Stack is empty");
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    std::cout << "Top of intStack: " << intStack.top() << "\n";
    intStack.pop();
    std::cout << "Top of intStack after pop: " << intStack.top() << "\n\n";

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Top of stringStack: " << stringStack.top() << "\n";
    stringStack.pop();
    std::cout << "Top of stringStack after pop: " << stringStack.top() << "\n";

    return 0;
}
```

**Output:**
```
Top of intStack: 20
Top of intStack after pop: 10

Top of stringStack: World
Top of stringStack after pop: Hello
```

---

### 3.3. Member Function Templates

#### Example 3: Template Member Function in a Class Template

```cpp
#include <iostream>
#include <string>

// Class template with a member function template
template <typename T>
class Container {
private:
    T element;

public:
    Container(T elem) : element(elem) {}

    // Member function template to compare with another type
    template <typename U>
    bool isEqual(const U &other) const {
        return element == other;
    }

    void display() const {
        std::cout << "Element: " << element << "\n";
    }
};

int main() {
    Container<int> intContainer(100);
    std::cout << "intContainer: ";
    intContainer.display();
    std::cout << "Is equal to 100? " << (intContainer.isEqual(100) ? "Yes" : "No") << "\n";
    std::cout << "Is equal to 200? " << (intContainer.isEqual(200) ? "Yes" : "No") << "\n\n";

    Container<std::string> stringContainer("C++");
    std::cout << "stringContainer: ";
    stringContainer.display();
    std::cout << "Is equal to \"C++\"? " << (stringContainer.isEqual(std::string("C++")) ? "Yes" : "No") << "\n";
    std::cout << "Is equal to \"Java\"? " << (stringContainer.isEqual(std::string("Java")) ? "Yes" : "No") << "\n";

    return 0;
}
```

**Output:**
```
intContainer: Element: 100
Is equal to 100? Yes
Is equal to 200? No

stringContainer: Element: C++
Is equal to "C++"? Yes
Is equal to "Java"? No
```

---

## 4. Template Specialization

### Description

**Template Specialization** allows you to provide custom implementations of templates for specific data types. This can be useful when a generic implementation is not optimal or requires special handling for certain types.

There are two types of specialization:

- **Full Specialization**: Provides a complete specialized version for a specific type.
- **Partial Specialization**: Provides a specialized version for a subset of types (applicable to class templates only).

### 4.1. Full Specialization

#### Example 1: Full Specialization of a Class Template

```cpp
#include <iostream>

// Generic class template
template <typename T>
class Printer {
public:
    void print(const T &data) const {
        std::cout << "Generic Printer: " << data << "\n";
    }
};

// Full specialization for std::string
template <>
class Printer<std::string> {
public:
    void print(const std::string &data) const {
        std::cout << "String Printer: " << data << "\n";
    }
};

int main() {
    Printer<int> intPrinter;
    intPrinter.print(123);

    Printer<std::string> stringPrinter;
    stringPrinter.print("Hello, Templates!");

    return 0;
}
```

**Output:**
```
Generic Printer: 123
String Printer: Hello, Templates!
```

---

### 4.2. Partial Specialization

#### Example 2: Partial Specialization of a Class Template

```cpp
#include <iostream>

// Primary template
template <typename T, typename U>
class Pair {
public:
    void display() const {
        std::cout << "Generic Pair\n";
    }
};

// Partial specialization when both types are the same
template <typename T>
class Pair<T, T> {
public:
    void display() const {
        std::cout << "Specialized Pair with identical types\n";
    }
};

int main() {
    Pair<int, double> p1;
    p1.display();

    Pair<std::string, std::string> p2;
    p2.display();

    return 0;
}
```

**Output:**
```
Generic Pair
Specialized Pair with identical types
```

*Note: The second `Pair` instance uses the partially specialized version because both template parameters are the same.*

---

#### Example 3: Partial Specialization for Pointer Types

```cpp
#include <iostream>

// Primary template
template <typename T>
class TypeInfo {
public:
    void print() const {
        std::cout << "Type is not a pointer.\n";
    }
};

// Partial specialization for pointer types
template <typename T>
class TypeInfo<T*> {
public:
    void print() const {
        std::cout << "Type is a pointer.\n";
    }
};

int main() {
    TypeInfo<int> ti1;
    ti1.print();

    TypeInfo<double*> ti2;
    ti2.print();

    return 0;
}
```

**Output:**
```
Type is not a pointer.
Type is a pointer.
```

---

## 5. Variadic Templates

### Description

**Variadic Templates** allow templates to accept an arbitrary number of template parameters. They are useful for functions and classes that need to handle multiple arguments of varying types, such as tuple implementations or logging functions.

### 5.1. Basic Variadic Template

#### Example 1: Sum Function with Variadic Templates

```cpp
#include <iostream>

// Base case: no arguments
int sum() {
    return 0;
}

// Variadic template function to calculate sum
template <typename T, typename... Args>
int sum(T first, Args... args) {
    return first + sum(args...);
}

int main() {
    std::cout << "Sum1: " << sum(1, 2, 3, 4, 5) << "\n";
    std::cout << "Sum2: " << sum(10, 20) << "\n";
    std::cout << "Sum3: " << sum() << "\n"; // Base case

    return 0;
}
```

**Output:**
```
Sum1: 15
Sum2: 30
Sum3: 0
```

---

### 5.2. Variadic Template with Recursion

#### Example 2: Printing Multiple Arguments

```cpp
#include <iostream>

// Base case: single argument
void printArgs(const std::string &msg) {
    std::cout << msg << "\n";
}

// Recursive variadic template function to print multiple arguments
template <typename T, typename... Args>
void printArgs(const T &first, const Args &... args) {
    std::cout << first << " ";
    printArgs(args...);
}

int main() {
    printArgs("C++", "Templates", "are", "powerful!");
    printArgs(1, 2.5, 'A', "Mixing", "Types");

    return 0;
}
```

**Output:**
```
C++ Templates are powerful!
1 2.5 A Mixing Types
```

---

## 6. Template Metaprogramming

### Description

**Template Metaprogramming** leverages templates to perform computations at compile time. It can lead to highly optimized code by moving calculations from runtime to compile time. Common uses include type traits, static assertions, and compile-time constants.

### 6.1. Compile-Time Calculations

#### Example 1: Factorial Computation at Compile Time

```cpp
#include <iostream>

// Template to compute factorial at compile time
template <int N>
struct Factorial {
    static const int value = N * Factorial<N - 1>::value;
};

// Specialization for N = 0
template <>
struct Factorial<0> {
    static const int value = 1;
};

int main() {
    std::cout << "Factorial of 5: " << Factorial<5>::value << "\n";
    std::cout << "Factorial of 0: " << Factorial<0>::value << "\n";
    std::cout << "Factorial of 7: " << Factorial<7>::value << "\n";

    return 0;
}
```

**Output:**
```
Factorial of 5: 120
Factorial of 0: 1
Factorial of 7: 5040
```

---

### 6.2. Type Traits

#### Example 2: Checking if a Type is a Pointer

```cpp
#include <iostream>
#include <type_traits>

// Template function to check if a type is a pointer
template <typename T>
void checkPointer() {
    if(std::is_pointer<T>::value)
        std::cout << "Type is a pointer.\n";
    else
        std::cout << "Type is not a pointer.\n";
}

int main() {
    checkPointer<int>();        // Not a pointer
    checkPointer<int*>();       // Pointer
    checkPointer<double>();     // Not a pointer
    checkPointer<double*>();    // Pointer

    return 0;
}
```

**Output:**
```
Type is not a pointer.
Type is a pointer.
Type is not a pointer.
Type is a pointer.
```

---

#### Example 3: Removing Const Qualifier

```cpp
#include <iostream>
#include <type_traits>
#include <string>

// Function to print type information
template <typename T>
void printTypeInfo() {
    std::cout << "Is const: " << std::is_const<T>::value << "\n";
    using NonConstT = typename std::remove_const<T>::type;
    std::cout << "After removing const: Is const: " << std::is_const<NonConstT>::value << "\n\n";
}

int main() {
    printTypeInfo<const int>();
    printTypeInfo<int>();
    printTypeInfo<const std::string>();
    printTypeInfo<std::string>();

    return 0;
}
```

**Output:**
```
Is const: 1
After removing const: Is const: 0

Is const: 0
After removing const: Is const: 0

Is const: 1
After removing const: Is const: 0

Is const: 0
After removing const: Is const: 0
```

---

## 7. Summary

C++ Templates are a cornerstone of generic programming, enabling the creation of flexible and reusable code. Here's a quick overview of the topics covered:

- **Function Templates**:
  - Allow functions to operate with generic types.
  - Support multiple template parameters and automatic type deduction.

- **Class Templates**:
  - Enable classes to handle generic types.
  - Facilitate the creation of generic data structures like pairs, stacks, and more.
  - Support member function templates for additional flexibility.

- **Template Specialization**:
  - **Full Specialization**: Customize template behavior for specific types.
  - **Partial Specialization**: Customize template behavior for a subset of types.

- **Variadic Templates**:
  - Allow templates to accept an arbitrary number of parameters.
  - Useful for functions and classes that handle multiple arguments of varying types.

- **Template Metaprogramming**:
  - Perform compile-time computations for optimized code.
  - Includes techniques like factorial computation and type traits.

