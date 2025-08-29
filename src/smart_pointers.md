# C++ Smart Pointers Recap


## Table of Contents

1. [Introduction to Smart Pointers](#1-introduction-to-smart-pointers)
2. [Types of Smart Pointers](#2-types-of-smart-pointers)
    - [2.1. `std::unique_ptr`](#21-stdunique_ptr)
    - [2.2. `std::shared_ptr`](#22-stdshared_ptr)
    - [2.3. `std::weak_ptr`](#23-stdweak_ptr)
3. [Common Operations](#3-common-operations)
    - [3.1. Creating Smart Pointers](#31-creating-smart-pointers)
    - [3.2. Transferring Ownership](#32-transferring-ownership)
    - [3.3. Custom Deleters](#33-custom-deleters)
4. [Best Practices](#4-best-practices)
5. [Summary](#5-summary)


---

## 1. Introduction to Smart Pointers

### Description

**Smart Pointers** in C++ are template classes provided by the C++ Standard Library that manage the lifetime of dynamically allocated objects. They ensure that memory is properly released when it is no longer needed, thereby preventing memory leaks and dangling pointers. Smart pointers leverage the RAII (Resource Acquisition Is Initialization) idiom, which ties resource management to object lifetime.

### Key Benefits

- **Automatic Memory Management**: Automatically deallocate memory when no longer needed.
- **Exception Safety**: Prevent memory leaks even when exceptions are thrown.
- **Clear Ownership Semantics**: Define ownership models (`unique`, `shared`, `weak`) explicitly.
- **Ease of Use**: Simplify dynamic memory management compared to raw pointers.

---

## 2. Types of Smart Pointers

C++ provides several smart pointers, each with distinct ownership semantics and use cases.

### 2.1. `std::unique_ptr`

#### Description

`std::unique_ptr` represents exclusive ownership of a dynamically allocated object. Only one `unique_ptr` can own a given resource at a time. It cannot be copied, but it can be moved to transfer ownership.

#### Example 1: Basic Usage of `std::unique_ptr`

```cpp
#include <iostream>
#include <memory>

int main() {
    // Create a unique_ptr to an integer
    //old
    std::unique_ptr<int> ptr(new int(42));

    std::cout << "Value: " << *ptr << "\n";

    // unique_ptr automatically deallocates memory when it goes out of scope

    auto p = std::make_unique<int>(42);

    std::unique_ptr<int> q;               // empty (nullptr), to be set later
    q = std::make_unique<int>(7);         // assign later

    int n = 20;
    auto arr = std::make_unique<int[]>(n); // dynamic array
    
    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic unique_ptr_basic.cpp -o unique_ptr_basic
```

**Output:**

```
Value: 42
```

---

#### Example 2: Transferring Ownership with `std::unique_ptr`

```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr1(new int(100));
    std::cout << "ptr1 points to: " << *ptr1 << "\n";

    // Transfer ownership to ptr2 using std::move
    std::unique_ptr<int> ptr2 = std::move(ptr1);

    if(ptr1 == nullptr)
        std::cout << "ptr1 is now nullptr.\n";

    std::cout << "ptr2 points to: " << *ptr2 << "\n";

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic unique_ptr_move.cpp -o unique_ptr_move
```

**Output:**

```
ptr1 points to: 100
ptr1 is now nullptr.
ptr2 points to: 100
```

---

#### Example 3: Using `std::unique_ptr` with Custom Classes

```cpp
#include <iostream>
#include <memory>
#include <string>

class Person {
public:
    std::string name;

    Person(const std::string &n) : name(n) {
        std::cout << "Person " << name << " created.\n";
    }

    ~Person() {
        std::cout << "Person " << name << " destroyed.\n";
    }

    void greet() const {
        std::cout << "Hello, my name is " << name << ".\n";
    }
};

int main() {
    {
        std::unique_ptr<Person> personPtr(new Person("Alice"));
        personPtr->greet();
    } // Person is automatically destroyed here

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic unique_ptr_class.cpp -o unique_ptr_class
```

**Output:**

```
Person Alice created.
Hello, my name is Alice.
Person Alice destroyed.
```

---

### 2.2. `std::shared_ptr`

#### Description

`std::shared_ptr` represents shared ownership of a dynamically allocated object. Multiple `shared_ptr` instances can own the same resource, and the resource is deallocated when the last `shared_ptr` is destroyed or reset. It uses reference counting to manage ownership.

#### Example 1: Basic Usage of `std::shared_ptr`

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

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic shared_ptr_basic.cpp -o shared_ptr_basic
```

**Output:**

```
ptr1 count: 1
ptr1 count after ptr2 copy: 2
ptr2 count: 2
ptr1 count after ptr2 out of scope: 1
```

---

#### Example 2: `std::shared_ptr` with Custom Classes

```cpp
#include <iostream>
#include <memory>
#include <string>

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

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic shared_ptr_class.cpp -o shared_ptr_class
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

#### Example 3: `std::shared_ptr` with Arrays

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

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic shared_ptr_array.cpp -o shared_ptr_array
```

**Output:**

```
Array elements: 10 20 30 
```

*Note: `std::shared_ptr` can manage arrays by specifying a custom deleter like `std::default_delete<int[]>`.*

---

### 2.3. `std::weak_ptr`

#### Description

`std::weak_ptr` provides a non-owning reference to an object managed by `std::shared_ptr`. It is used to prevent cyclic references that can lead to memory leaks. `weak_ptr` can be converted to `shared_ptr` using the `lock()` method, which returns a `shared_ptr` if the managed object still exists.

#### Example 1: Basic Usage of `std::weak_ptr`

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

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic weak_ptr_basic.cpp -o weak_ptr_basic
```

**Output:**

```
sptr count: 1
wptr expired? No
After resetting sptr:
wptr expired? Yes
```

---

#### Example 2: Using `std::weak_ptr` to Break Cyclic References

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

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic weak_ptr_cycle.cpp -o weak_ptr_cycle
```

**Output:**

```
A destroyed.
B destroyed.
```

*Note: Without using `weak_ptr` in class `B`, both `A` and `B` would keep each other alive, resulting in a memory leak.*

---

#### Example 3: Accessing Data with `std::weak_ptr`

```cpp
#include <iostream>
#include <memory>
#include <string>

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

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic weak_ptr_access.cpp -o weak_ptr_access
```

**Output:**

```
Hello from Resource!
Resource no longer exists.
```

---

## 3. Common Operations

### 3.1. Creating Smart Pointers

#### Example 1: Using `std::make_unique` and `std::make_shared`

```cpp
#include <iostream>
#include <memory>
#include <string>

class Widget {
public:
    Widget() { std::cout << "Widget created.\n"; }
    ~Widget() { std::cout << "Widget destroyed.\n"; }

    void doSomething() const {
        std::cout << "Widget is doing something.\n";
    }
};

int main() {
    // Creating unique_ptr using make_unique (C++14 and above)
    auto uniquePtr = std::make_unique<Widget>();
    uniquePtr->doSomething();

    // Creating shared_ptr using make_shared
    auto sharedPtr = std::make_shared<Widget>();
    sharedPtr->doSomething();

    return 0;
}
```

**Compilation Instructions:**

For C++14 and above (since `std::make_unique` is introduced in C++14):

```bash
g++ -std=c++14 -Wall -Wextra -pedantic smart_pointers_create.cpp -o smart_pointers_create
```

**Output:**

```
Widget created.
Widget is doing something.
Widget created.
Widget is doing something.
Widget destroyed.
Widget destroyed.
```

*Note: Using `make_unique` and `make_shared` is preferred over direct `new` to avoid potential memory leaks and for better performance.*

---

### 3.2. Transferring Ownership

#### Example 2: Moving `std::unique_ptr` and Sharing `std::shared_ptr`

```cpp
#include <iostream>
#include <memory>
#include <string>

class Entity {
public:
    std::string name;

    Entity(const std::string &n) : name(n) {
        std::cout << "Entity " << name << " created.\n";
    }

    ~Entity() {
        std::cout << "Entity " << name << " destroyed.\n";
    }

    void display() const {
        std::cout << "Entity: " << name << "\n";
    }
};

int main() {
    // unique_ptr ownership transfer
    std::unique_ptr<Entity> uPtr1 = std::make_unique<Entity>("Player");
    uPtr1->display();

    // Transfer ownership to uPtr2
    std::unique_ptr<Entity> uPtr2 = std::move(uPtr1);

    if(uPtr1 == nullptr)
        std::cout << "uPtr1 is now nullptr.\n";

    uPtr2->display();

    // shared_ptr sharing ownership
    std::shared_ptr<Entity> sPtr1 = std::make_shared<Entity>("Enemy");
    std::cout << "sPtr1 count: " << sPtr1.use_count() << "\n";

    std::shared_ptr<Entity> sPtr2 = sPtr1;
    std::cout << "sPtr1 count after copy: " << sPtr1.use_count() << "\n";
    std::cout << "sPtr2 count: " << sPtr2.use_count() << "\n";

    sPtr1->display();
    sPtr2->display();

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -std=c++14 -Wall -Wextra -pedantic smart_pointers_transfer.cpp -o smart_pointers_transfer
```

**Output:**

```
Entity Player created.
Entity: Player
uPtr1 is now nullptr.
Entity: Player
Entity Enemy created.
sPtr1 count: 1
sPtr1 count after copy: 2
sPtr2 count: 2
Entity: Enemy
Entity: Enemy
Entity Player destroyed.
Entity Enemy destroyed.
```

*Note: `unique_ptr` cannot be copied, only moved. `shared_ptr` can be copied, sharing ownership and increasing the reference count.*

---

### 3.3. Custom Deleters

#### Example 3: Using Custom Deleters with Smart Pointers

```cpp
#include <iostream>
#include <memory>
#include <functional>

struct Resource {
    void sayHello() const {
        std::cout << "Hello from Resource!\n";
    }
};

// Custom deleter for Resource
struct ResourceDeleter {
    void operator()(Resource* ptr) const {
        std::cout << "Custom deleter called. Deleting Resource.\n";
        delete ptr;
    }
};

int main() {
    // unique_ptr with custom deleter
    std::unique_ptr<Resource, ResourceDeleter> uPtr(new Resource());
    uPtr->sayHello();

    // shared_ptr with custom deleter
    std::shared_ptr<Resource> sPtr(new Resource(), [](Resource* ptr) {
        std::cout << "Lambda deleter called. Deleting Resource.\n";
        delete ptr;
    });
    sPtr->sayHello();

    return 0;
}
```

**Compilation Instructions:**

```bash
g++ -std=c++11 -Wall -Wextra -pedantic smart_pointers_deleter.cpp -o smart_pointers_deleter
```

**Output:**

```
Hello from Resource!
Hello from Resource!
Custom deleter called. Deleting Resource.
Lambda deleter called. Deleting Resource.
```

*Note: Custom deleters are useful when you need to perform additional cleanup or manage resources other than memory.*

---

## 4. Best Practices

- **Prefer `std::make_unique` and `std::make_shared`**: They are safer and more efficient compared to using `new` directly.
  
  ```cpp
  auto ptr = std::make_unique<MyClass>();
  auto sharedPtr = std::make_shared<MyClass>();
  ```

- **Use `std::unique_ptr` for Exclusive Ownership**: When a resource is owned by a single entity.
  
  ```cpp
  std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
  ```

- **Use `std::shared_ptr` for Shared Ownership**: When multiple entities need to share ownership of a resource.
  
  ```cpp
  std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
  std::shared_ptr<MyClass> ptr2 = ptr1; // Shared ownership
  ```

- **Use `std::weak_ptr` to Prevent Cyclic References**: Especially in scenarios like parent-child relationships in trees or graphs.
  
  ```cpp
  std::shared_ptr<Child> child = parent->childPtr;
  std::weak_ptr<Parent> weakParent = parent;
  ```

- **Avoid Mixing Raw and Smart Pointers**: Stick to smart pointers for ownership semantics to prevent memory leaks and undefined behavior.

- **Be Mindful of Overhead**: `std::shared_ptr` has overhead due to reference counting. Use `std::unique_ptr` when shared ownership is not required.

- **Custom Deleters**: Use them only when necessary. They can complicate the ownership semantics and performance.

- **Thread Safety**: `std::shared_ptr` is thread-safe for copying and assigning but not for modifying the managed object. Ensure proper synchronization when accessing shared resources across threads.

---

## 5. Summary

C++ Smart Pointers provide robust and automatic memory management, enhancing code safety and maintainability. Here's a quick overview of the topics covered:

- **Types of Smart Pointers**:
  - **`std::unique_ptr`**: Exclusive ownership, non-copyable, movable.
  - **`std::shared_ptr`**: Shared ownership with reference counting.
  - **`std::weak_ptr`**: Non-owning reference to prevent cyclic dependencies.

- **Common Operations**:
  - **Creating Smart Pointers**: Using `std::make_unique` and `std::make_shared` for efficient and safe memory allocation.
  - **Transferring Ownership**: Moving `unique_ptr` and copying `shared_ptr`.
  - **Custom Deleters**: Defining custom behaviors during object destruction.

- **Best Practices**:
  - Prefer factory functions (`make_unique`, `make_shared`).
  - Use the appropriate smart pointer based on ownership requirements.
  - Avoid mixing raw and smart pointers to maintain clear ownership semantics.
  - Be cautious of the overhead associated with `shared_ptr`.



---

### Additional Tips

- **Syntax Highlighting**: The code blocks use triple backticks with `cpp` to enable C++ syntax highlighting on GitHub, enhancing readability.

- **Formatting**: Clear section headers and subheaders improve navigation and comprehension.

- **Examples**: Multiple examples with varying complexity demonstrate different aspects of each concept.

- **Comments**: Inline comments within code snippets clarify the purpose and functionality of specific lines or sections.

- **Notes**: Important observations, such as the behavior of `weak_ptr` or the benefits of `make_unique`, are highlighted to prevent common misunderstandings.

- **Best Practices**: Emphasizes the importance of using smart pointers over raw pointers, leveraging factory functions, and understanding ownership semantics.

- **Performance Considerations**: Highlights the overhead of `shared_ptr` due to reference counting and advises using `unique_ptr` when shared ownership is not required.

