# C++ Pointers and Dynamic Memory Management Recap

## Table of Contents

1. [Pointers](#1-pointers)
    - [1.1. Basic Pointers](#11-basic-pointers)
    - [1.2. Pointer Arithmetic](#12-pointer-arithmetic)
    - [1.3. Pointers to Pointers](#13-pointers-to-pointers)
    - [1.4. Pointers and Functions](#14-pointers-and-functions)
2. [Dynamic Memory](#2-dynamic-memory)
    - [2.1. Using `new` and `delete`](#21-using-new-and-delete)
    - [2.2. Dynamic Containers](#22-dynamic-arrays)
    - [2.3. Dynamic Memory with Classes](#23-dynamic-memory-with-classes)
3. [Memory Allocation](#3-memory-allocation)
    - [3.1. `malloc` and `free`](#31-malloc-and-free)
    - [3.2. Smart Pointers](#32-smart-pointers)
        - [3.2.1. `std::unique_ptr`](#321-stdunique_ptr)
        - [3.2.2. `std::shared_ptr`](#322-stdshared_ptr)
        - [3.2.3. `std::weak_ptr`](#323-stdweak_ptr)
4. [Summary](#4-summary)

---

## 1. Pointers

### 1.1. Basic Pointers

#### Description

A **pointer** is a variable that stores the memory address of another variable. Pointers are fundamental in C++ for dynamic memory management, arrays, and efficient function parameter passing.

#### Examples

##### Example 1: Declaring and Using Pointers

```cpp
#include <iostream>

int main() {
    int var = 20;    // An integer variable
    int *ptr = &var; // Pointer to var

    std::cout << "Value of var: " << var << "\n";
    std::cout << "Address of var: " << &var << "\n";
    std::cout << "Value stored in ptr (Address of var): " << ptr << "\n";
    std::cout << "Value pointed to by ptr: " << *ptr << "\n";

    return 0;
}
```

**Output:**
```
Value of var: 20
Address of var: 0x7ffee3bff5ac
Value stored in ptr (Address of var): 0x7ffee3bff5ac
Value pointed to by ptr: 20
```

---

##### Example 2: Pointer to a Character

```cpp
#include <iostream>

int main() {
    char letter = 'A';
    char *ptr = &letter;

    std::cout << "Character: " << letter << "\n";
    std::cout << "Address of character: " << static_cast<void*>(ptr) << "\n";
    std::cout << "Character via pointer: " << *ptr << "\n";

    return 0;
}
```

**Output:**
```
Character: A
Address of character: 0x7ffee3bff598
Character via pointer: A
```

---

##### Example 3: Pointer to a Floating-Point Number

```cpp
#include <iostream>

int main() {
    float pi = 3.1415;
    float *ptr = &pi;

    std::cout << "Value of pi: " << pi << "\n";
    std::cout << "Address of pi: " << ptr << "\n";
    std::cout << "Value via pointer: " << *ptr << "\n";

    return 0;
}
```

**Output:**
```
Value of pi: 3.1415
Address of pi: 0x7ffee3bff594
Value via pointer: 3.1415
```

---

### 1.2. Pointer Arithmetic

#### Description

Pointer arithmetic involves performing arithmetic operations on pointers. Since pointers represent memory addresses, arithmetic operations move the pointer to different memory locations based on the data type's size.

#### Examples

##### Example 1: Incrementing a Pointer

```cpp
#include <iostream>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Points to arr[0]

    std::cout << "Initial pointer address: " << ptr << "\n";
    std::cout << "Value at initial pointer: " << *ptr << "\n";

    ptr++; // Move to arr[1]
    std::cout << "Pointer address after increment: " << ptr << "\n";
    std::cout << "Value at new pointer: " << *ptr << "\n";

    return 0;
}
```

**Output:**
```
Initial pointer address: 0x7ffee3bff570
Value at initial pointer: 10
Pointer address after increment: 0x7ffee3bff574
Value at new pointer: 20
```

---

##### Example 2: Traversing an Array with Pointers

```cpp
#include <iostream>

int main() {
    double numbers[] = {2.5, 3.6, 4.7, 5.8};
    double *ptr = numbers;

    std::cout << "Traversing the array using pointers:\n";
    for(int i = 0; i < 4; ++i) {
        std::cout << "Value " << i << ": " << *ptr << "\n";
        ptr++;
    }

    return 0;
}
```

**Output:**
```
Traversing the array using pointers:
Value 0: 2.5
Value 1: 3.6
Value 2: 4.7
Value 3: 5.8
```

---

##### Example 3: Pointer Difference

```cpp
#include <iostream>

int main() {
    int arr[] = {100, 200, 300, 400, 500};
    int *ptr1 = &arr[1]; // Points to 200
    int *ptr2 = &arr[4]; // Points to 500

    std::cout << "ptr1 points to: " << *ptr1 << "\n";
    std::cout << "ptr2 points to: " << *ptr2 << "\n";
    std::cout << "Difference between ptr2 and ptr1: " << ptr2 - ptr1 << "\n";

    return 0;
}
```

**Output:**
```
ptr1 points to: 200
ptr2 points to: 500
Difference between ptr2 and ptr1: 3
```

---

### 1.3. Pointers to Pointers

#### Description

A **pointer to a pointer** is a form of multiple indirection, where a pointer stores the address of another pointer. This is useful in scenarios like dynamic memory allocation for multidimensional arrays and managing dynamic data structures.

#### Examples

##### Example 1: Pointer to a Pointer

```cpp
#include <iostream>

int main() {
    int var = 50;
    int *ptr = &var;
    int **pptr = &ptr;

    std::cout << "Value of var: " << var << "\n";
    std::cout << "Value via ptr: " << *ptr << "\n";
    std::cout << "Value via pptr: " << **pptr << "\n";

    return 0;
}
```

**Output:**
```
Value of var: 50
Value via ptr: 50
Value via pptr: 50
```

---

##### Example 2: Modifying Value Using Pointer to Pointer

```cpp
#include <iostream>

int main() {
    int var = 30;
    int *ptr = &var;
    int **pptr = &ptr;

    std::cout << "Original value: " << var << "\n";

    **pptr = 100; // Modify var using pptr

    std::cout << "Modified value: " << var << "\n";

    return 0;
}
```

**Output:**
```
Original value: 30
Modified value: 100
```

---

##### Example 3: Dynamic Memory Allocation for a Pointer to Pointer

```cpp
#include <iostream>

int main() {
    int rows = 2, cols = 3;

    // Allocate memory for pointer to pointers
    int **matrix = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Initialize the matrix
    for(int i = 0; i < rows; ++i)
        for(int j = 0; j < cols; ++j)
            matrix[i][j] = (i+1) * (j+1);

    // Display the matrix
    std::cout << "Matrix:\n";
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Deallocate memory
    for(int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
```

**Output:**
```
Matrix:
1 2 3 
2 4 6 
```

---

### 1.4. Pointers and Functions

#### Description

Pointers can be passed to functions to allow functions to modify variable values directly, enabling efficient data manipulation and dynamic data structures.

#### Examples

##### Example 1: Passing Pointer to a Function

```cpp
#include <iostream>

// Function to square a number using pointer
void square(int *num) {
    *num = (*num) * (*num);
}

int main() {
    int value = 5;
    std::cout << "Before square: " << value << "\n";
    square(&value);
    std::cout << "After square: " << value << "\n";

    return 0;
}
```

**Output:**
```
Before square: 5
After square: 25
```

---

##### Example 2: Returning Pointer from a Function

```cpp
#include <iostream>

// Function to find the maximum of two integers
int* max(int *a, int *b) {
    return (*a > *b) ? a : b;
}

int main() {
    int x = 10, y = 20;
    int *result = max(&x, &y);

    std::cout << "The maximum value is: " << *result << "\n";

    return 0;
}
```

**Output:**
```
The maximum value is: 20
```

---

##### Example 3: Function Pointers

```cpp
#include <iostream>

// Functions to perform operations
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main() {
    // Declare a function pointer
    int (*funcPtr)(int, int);

    // Assign add function to pointer
    funcPtr = add;
    std::cout << "Addition: " << funcPtr(3, 4) << "\n";

    // Assign multiply function to pointer
    funcPtr = multiply;
    std::cout << "Multiplication: " << funcPtr(3, 4) << "\n";

    return 0;
}
```

**Output:**
```
Addition: 7
Multiplication: 12
```

---

## 2. Dynamic Memory

### 2.1. Using `new` and `delete`

#### Description

C++ provides the `new` and `delete` operators for dynamic memory allocation and deallocation. `new` allocates memory on the heap, and `delete` frees that memory. Proper use of these operators is crucial to prevent memory leaks and undefined behavior.

#### Examples

##### Example 1: Allocating and Deallocating Single Variable

```cpp
#include <iostream>

int main() {
    // Allocate memory for an integer
    int *ptr = new int;
    *ptr = 25;

    std::cout << "Value: " << *ptr << "\n";

    // Deallocate memory
    delete ptr;

    return 0;
}
```

**Output:**
```
Value: 25
```

---

##### Example 2: Allocating and Deallocating Array

```cpp
#include <iostream>

int main() {
    int size = 5;
    // Allocate memory for an array of integers
    int *arr = new int[size];

    // Initialize the array
    for(int i = 0; i < size; ++i)
        arr[i] = i * 10;

    // Display the array
    std::cout << "Array elements: ";
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Deallocate memory
    delete[] arr;

    return 0;
}
```

**Output:**
```
Array elements: 0 10 20 30 40 
```

---

##### Example 3: Dynamic Memory with Classes

```cpp
#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int age;

    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << "\n";
    }
};

int main() {
    // Allocate memory for a Student object
    Student *s = new Student;
    s->name = "Alice";
    s->age = 21;

    s->display();

    // Deallocate memory
    delete s;

    return 0;
}
```

**Output:**
```
Name: Alice, Age: 21
```

---

### 2.2. Dynamic Containers

#### Description

Dynamic arrays are arrays whose size can be determined during runtime. They are created using the `new` operator and must be managed manually using `delete[]` to free the allocated memory.

#### Examples

##### Example 1: Creating a Dynamic Integer Array

```cpp
#include <iostream>

int main() {
    int n;
    std::cout << "Enter number of elements: ";
    std::cin >> n;

    // Allocate memory for n integers
    int *arr = new int[n];

    // Input elements
    std::cout << "Enter " << n << " integers:\n";
    for(int i = 0; i < n; ++i)
        std::cin >> arr[i];

    // Display elements
    std::cout << "You entered: ";
    for(int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Deallocate memory
    delete[] arr;

    return 0;
}
```

**Sample Interaction:**
```
Enter number of elements: 3
Enter 3 integers:
10 20 30
You entered: 10 20 30 
```

---
##### Example 2: Dynamic Containers


```cpp
#include <iostream>
#include <vector>
#include <map>

int main() {
    // Dynamically allocate a std::vector
    std::vector<int>* dynamicVector = new std::vector<int>();

    // Populate the vector
    dynamicVector->push_back(10);
    dynamicVector->push_back(20);
    dynamicVector->push_back(30);

    std::cout << "Dynamic Vector Elements:" << std::endl;
    for (const auto& elem : *dynamicVector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Dynamically allocate a std::vector<std::vector<int>>
    std::vector<std::vector<int>>* dynamicMatrix = new std::vector<std::vector<int>>();

    // Populate the vector of vectors
    dynamicMatrix->push_back({1, 2, 3});
    dynamicMatrix->push_back({4, 5, 6});
    dynamicMatrix->push_back({7, 8, 9});

    std::cout << "Dynamic Matrix Elements:" << std::endl;
    for (const auto& row : *dynamicMatrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // Dynamically allocate a std::map
    std::map<std::string, int>* dynamicMap = new std::map<std::string, int>();

    // Populate the map
    (*dynamicMap)["apple"] = 5;
    (*dynamicMap)["banana"] = 3;
    (*dynamicMap)["cherry"] = 8;

    std::cout << "Dynamic Map Elements:" << std::endl;
    for (const auto& pair : *dynamicMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Free dynamically allocated memory
    delete dynamicVector;
    delete dynamicMatrix;
    delete dynamicMap;

    return 0;
}
```

**Output:**

```
Dynamic Vector Elements:
10 20 30 
Dynamic Matrix Elements:
1 2 3 
4 5 6 
7 8 9 
Dynamic Map Elements:
apple: 5
banana: 3
cherry: 8

```


---
##### Example 3: Dynamic Array of Objects

```cpp
#include <iostream>
#include <string>

class Book {
public:
    std::string title;
    double price;

    void display() const {
        std::cout << "Title: " << title << ", Price: $" << price << "\n";
    }
};

int main() {
    int n;
    std::cout << "Enter number of books: ";
    std::cin >> n;

    // Allocate memory for n Book objects
    Book *books = new Book[n];

    // Input book details
    for(int i = 0; i < n; ++i) {
        std::cout << "Enter title for book " << i+1 << ": ";
        std::cin >> books[i].title;
        std::cout << "Enter price for book " << i+1 << ": ";
        std::cin >> books[i].price;
    }

    // Display book details
    std::cout << "\nBook Details:\n";
    for(int i = 0; i < n; ++i)
        books[i].display();

    // Deallocate memory
    delete[] books;

    return 0;
}
```

**Sample Interaction:**
```
Enter number of books: 2
Enter title for book 1: CppPrimer
Enter price for book 1: 39.99
Enter title for book 2: EffectiveC++
Enter price for book 2: 45.50

Book Details:
Title: CppPrimer, Price: $39.99
Title: EffectiveC++, Price: $45.5
```

---

##### Example 4: Resizing a Dynamic Array (Manual)

```cpp
#include <iostream>

int main() {
    int size = 3;
    // Allocate initial array
    int *arr = new int[size] {1, 2, 3};

    // Display initial array
    std::cout << "Initial array: ";
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Resize the array to size 5
    int newSize = 5;
    int *temp = new int[newSize];

    // Copy existing elements
    for(int i = 0; i < size; ++i)
        temp[i] = arr[i];

    // Initialize new elements
    for(int i = size; i < newSize; ++i)
        temp[i] = i + 1;

    // Deallocate old array and update pointer
    delete[] arr;
    arr = temp;
    size = newSize;

    // Display resized array
    std::cout << "Resized array: ";
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Deallocate memory
    delete[] arr;

    return 0;
}
```

**Output:**
```
Initial array: 1 2 3 
Resized array: 1 2 3 4 5 
```

---

### 2.3. Dynamic Memory with Classes

#### Description

Managing dynamic memory within classes involves allocating memory for class members during object creation and ensuring proper deallocation to prevent memory leaks. This often requires implementing **constructors**, **destructors**, and **copy/move semantics**.

#### Examples

##### Example 1: Dynamic Memory Allocation in Class Constructor and Destructor

```cpp
#include <iostream>
#include <cstring>

class String {
private:
    char *str;

public:
    // Default constructor
    String() : str(nullptr) {}

    // Parameterized constructor
    String(const char *s) {
        if(s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = nullptr;
        }
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Display function
    void display() const {
        if(str)
            std::cout << str << "\n";
        else
            std::cout << "Empty String.\n";
    }
};

int main() {
    String s1("Hello, World!");
    s1.display();

    String s2;
    s2.display();

    return 0;
}
```

**Output:**
```
Hello, World!
Empty String.
```

---

##### Example 2: Implementing Copy Constructor and Copy Assignment Operator

```cpp
#include <iostream>
#include <cstring>

class String {
private:
    char *str;

public:
    // Parameterized constructor
    String(const char *s) {
        if(s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = nullptr;
        }
    }

    // Copy constructor
    String(const String &other) {
        if(other.str) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }

    // Copy assignment operator
    String& operator=(const String &other) {
        if(this == &other)
            return *this;

        delete[] str;

        if(other.str) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        } else {
            str = nullptr;
        }

        return *this;
    }

    // Destructor
    ~String() {
        delete[] str;
    }

    // Display function
    void display() const {
        if(str)
            std::cout << str << "\n";
        else
            std::cout << "Empty String.\n";
    }
};

int main() {
    String s1("C++ Programming");
    String s2 = s1; // Invokes copy constructor
    String s3("Data Structures");
    s3 = s1; // Invokes copy assignment operator

    std::cout << "s1: ";
    s1.display();
    std::cout << "s2: ";
    s2.display();
    std::cout << "s3: ";
    s3.display();

    return 0;
}
```

**Output:**
```
s1: C++ Programming
s2: C++ Programming
s3: C++ Programming
```

---

##### Example 3: Move Constructor and Move Assignment Operator

```cpp
#include <iostream>
#include <utility>

class MoveOnly {
public:
    int *data;

    // Parameterized constructor
    MoveOnly(int value) {
        data = new int(value);
        std::cout << "Constructed with value " << *data << "\n";
    }

    // Move constructor
    MoveOnly(MoveOnly &&other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move constructor called.\n";
    }

    // Move assignment operator
    MoveOnly& operator=(MoveOnly &&other) noexcept {
        if(this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
            std::cout << "Move assignment called.\n";
        }
        return *this;
    }

    // Destructor
    ~MoveOnly() {
        if(data)
            std::cout << "Destructor deleting value " << *data << "\n";
        else
            std::cout << "Destructor with no data.\n";
        delete data;
    }
};

int main() {
    MoveOnly mo1(10);
    MoveOnly mo2 = std::move(mo1); // Move constructor
    MoveOnly mo3(20);
    mo3 = std::move(mo2); // Move assignment

    return 0;
}
```

**Output:**
```
Constructed with value 10
Move constructor called.
Constructed with value 20
Move assignment called.
Destructor deleting value 20
Destructor with no data.
Destructor with no data.
```

---

## 3. Memory Allocation

### 3.1. `malloc` and `free`

#### Description

While C++ primarily uses `new` and `delete` for dynamic memory management, it is compatible with C's `malloc` and `free` functions from the `<cstdlib>` library. However, using `new` and `delete` is generally preferred in C++ for object initialization and destructors.

#### Examples

##### Example 1: Using `malloc` and `free` for Single Variable

```cpp
#include <iostream>
#include <cstdlib> // For malloc and free

int main() {
    // Allocate memory for an integer
    int *ptr = (int*) malloc(sizeof(int));
    if(ptr == nullptr) {
        std::cerr << "Memory allocation failed.\n";
        return 1;
    }

    *ptr = 42;
    std::cout << "Value: " << *ptr << "\n";

    // Deallocate memory
    free(ptr);

    return 0;
}
```

**Output:**
```
Value: 42
```

---

##### Example 2: Using `malloc` and `free` for Array

```cpp
#include <iostream>
#include <cstdlib> // For malloc and free

int main() {
    int size = 4;
    // Allocate memory for an array of integers
    int *arr = (int*) malloc(size * sizeof(int));
    if(arr == nullptr) {
        std::cerr << "Memory allocation failed.\n";
        return 1;
    }

    // Initialize the array
    for(int i = 0; i < size; ++i)
        arr[i] = (i + 1) * 5;

    // Display the array
    std::cout << "Array elements: ";
    for(int i = 0; i < size; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    // Deallocate memory
    free(arr);

    return 0;
}
```

**Output:**
```
Array elements: 5 10 15 20 
```

---

##### Example 3: Allocating Memory for Struct Using `malloc`

```cpp
#include <iostream>
#include <cstdlib> // For malloc and free
#include <cstring>

struct Person {
    char name[50];
    int age;
};

int main() {
    // Allocate memory for a Person
    Person *p = (Person*) malloc(sizeof(Person));
    if(p == nullptr) {
        std::cerr << "Memory allocation failed.\n";
        return 1;
    }

    // Initialize the struct
    strcpy(p->name, "Bob");
    p->age = 28;

    // Display the struct
    std::cout << "Name: " << p->name << ", Age: " << p->age << "\n";

    // Deallocate memory
    free(p);

    return 0;
}
```

**Output:**
```
Name: Bob, Age: 28
```

---

### 3.2. Smart Pointers

#### Description

Smart pointers in C++ provide automatic memory management, helping to prevent memory leaks and dangling pointers. They are part of the `<memory>` header and include:

- **`std::unique_ptr`**: Exclusive ownership; cannot be copied, only moved.
- **`std::shared_ptr`**: Shared ownership; maintains a reference count.
- **`std::weak_ptr`**: Non-owning reference to an object managed by `std::shared_ptr`.

#### 3.2.1. `std::unique_ptr`

##### Example 1: Basic Usage of `std::unique_ptr`

```cpp
#include <iostream>
#include <memory>

int main() {
    // Create a unique_ptr to an integer
    std::unique_ptr<int> ptr(new int(100));

    std::cout << "Value: " << *ptr << "\n";

    // unique_ptr automatically deallocates memory when it goes out of scope

    return 0;
}
```

**Output:**
```
Value: 100
```

---

##### Example 2: Transferring Ownership with `std::unique_ptr`

```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr1(new int(50));
    std::cout << "ptr1 points to: " << *ptr1 << "\n";

    // Transfer ownership to ptr2
    std::unique_ptr<int> ptr2 = std::move(ptr1);

    if(ptr1 == nullptr)
        std::cout << "ptr1 is now nullptr.\n";

    std::cout << "ptr2 points to: " << *ptr2 << "\n";

    return 0;
}
```

**Output:**
```
ptr1 points to: 50
ptr1 is now nullptr.
ptr2 points to: 50
```

---

##### Example 3: Using `std::unique_ptr` with Custom Classes

```cpp
#include <iostream>
#include <memory>

class Widget {
public:
    Widget() { std::cout << "Widget created.\n"; }
    ~Widget() { std::cout << "Widget destroyed.\n"; }

    void doSomething() const {
        std::cout << "Widget is doing something.\n";
    }
};

int main() {
    {
        std::unique_ptr<Widget> wPtr(new Widget());
        wPtr->doSomething();
    } // Widget is automatically destroyed here

    return 0;
}
```

**Output:**
```
Widget created.
Widget is doing something.
Widget destroyed.
```

---

#### 3.2.2. `std::shared_ptr`

##### Example 1: Basic Usage of `std::shared_ptr`

```cpp
#include <iostream>
#include <memory>

int main() {
    // Create a shared_ptr to an integer
    std::shared_ptr<int> ptr1 = std::make_shared<int>(200);
    std::cout << "ptr1 count: " << ptr1.use_count() << "\n"; // Count: 1

    {
        std::shared_ptr<int> ptr2 = ptr1;
        std::cout << "ptr1 count after ptr2 copy: " << ptr1.use_count() << "\n"; // Count: 2
        std::cout << "ptr2 count: " << ptr2.use_count() << "\n"; // Count: 2
    }

    std::cout << "ptr1 count after ptr2 out of scope: " << ptr1.use_count() << "\n"; // Count: 1

    return 0;
}
```

**Output:**
```
ptr1 count: 1
ptr1 count after ptr2 copy: 2
ptr2 count: 2
ptr1 count after ptr2 out of scope: 1
```

---

##### Example 2: `std::shared_ptr` with Custom Classes

```cpp
#include <iostream>
#include <memory>

class Device {
public:
    Device() { std::cout << "Device created.\n"; }
    ~Device() { std::cout << "Device destroyed.\n"; }

    void operate() const {
        std::cout << "Device is operating.\n";
    }
};

int main() {
    std::shared_ptr<Device> dPtr1 = std::make_shared<Device>();
    {
        std::shared_ptr<Device> dPtr2 = dPtr1;
        dPtr2->operate();
        std::cout << "dPtr1 count: " << dPtr1.use_count() << "\n"; // Count: 2
    }
    std::cout << "dPtr1 count after dPtr2 out of scope: " << dPtr1.use_count() << "\n"; // Count: 1

    return 0;
}
```

**Output:**
```
Device created.
Device is operating.
dPtr1 count: 2
Device destroyed.
dPtr1 count after dPtr2 out of scope: 1
```

---

##### Example 3: `std::shared_ptr` with Arrays

```cpp
#include <iostream>
#include <memory>

int main() {
    // Create a shared_ptr managing a dynamic array
    std::shared_ptr<int[]> arrPtr(new int[3]{10, 20, 30}, std::default_delete<int[]>());

    std::cout << "Array elements: ";
    for(int i = 0; i < 3; ++i)
        std::cout << arrPtr[i] << " ";
    std::cout << "\n";

    return 0;
}
```

**Output:**
```
Array elements: 10 20 30 
```

---

#### 3.2.3. `std::weak_ptr`

##### Example 1: Basic Usage of `std::weak_ptr`

```cpp
#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sptr = std::make_shared<int>(500);
    std::weak_ptr<int> wptr = sptr;

    std::cout << "sptr count: " << sptr.use_count() << "\n"; // Count: 1
    std::cout << "wptr expired? " << (wptr.expired() ? "Yes" : "No") << "\n"; // No

    sptr.reset(); // Release ownership

    std::cout << "After resetting sptr:\n";
    std::cout << "wptr expired? " << (wptr.expired() ? "Yes" : "No") << "\n"; // Yes

    return 0;
}
```

**Output:**
```
sptr count: 1
wptr expired? No
After resetting sptr:
wptr expired? Yes
```

---

##### Example 2: Using `std::weak_ptr` to Break Cyclic References

```cpp
#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> ptrB;
    ~A() { std::cout << "A destroyed.\n"; }
};

class B {
public:
    std::weak_ptr<A> ptrA; // Use weak_ptr to prevent cyclic reference
    ~B() { std::cout << "B destroyed.\n"; }
};

int main() {
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();
        a->ptrB = b;
        b->ptrA = a;
    } // Both A and B are destroyed properly

    return 0;
}
```

**Output:**
```
B destroyed.
A destroyed.
```

---

##### Example 3: Accessing Data with `std::weak_ptr`

```cpp
#include <iostream>
#include <memory>

class Resource {
public:
    void greet() const {
        std::cout << "Hello from Resource!\n";
    }
};

int main() {
    std::shared_ptr<Resource> sptr = std::make_shared<Resource>();
    std::weak_ptr<Resource> wptr = sptr;

    if(auto locked = wptr.lock()) { // Attempt to get shared_ptr
        locked->greet();
    } else {
        std::cout << "Resource no longer exists.\n";
    }

    sptr.reset(); // Destroy Resource

    if(auto locked = wptr.lock()) {
        locked->greet();
    } else {
        std::cout << "Resource no longer exists.\n";
    }

    return 0;
}
```

**Output:**
```
Hello from Resource!
Resource no longer exists.
```

---

## 4. Summary

C++ provides powerful tools for managing memory and data through pointers and dynamic memory allocation. Understanding these concepts is crucial for writing efficient and safe C++ programs. Here's a quick overview of the topics covered:

- **Pointers**:
  - Store memory addresses of variables.
  - Enable dynamic memory management and efficient data manipulation.
  - Support multiple levels of indirection (pointers to pointers).

- **Dynamic Memory**:
  - Managed using `new` and `delete` operators.
  - Allows allocation of memory at runtime, enabling flexible data structures.
  - Requires careful management to prevent memory leaks and dangling pointers.

- **Memory Allocation**:
  - C++ prefers `new` and `delete` over C's `malloc` and `free` for object-oriented features.
  - **Smart Pointers** (`std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`) provide automatic memory management.
    - **`std::unique_ptr`**: Exclusive ownership, prevents multiple ownership scenarios.
    - **`std::shared_ptr`**: Shared ownership with reference counting.
    - **`std::weak_ptr`**: Non-owning reference, helps in breaking cyclic dependencies.

