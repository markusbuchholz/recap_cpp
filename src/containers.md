# C++ STL Containers Recap

This repository provides a comprehensive recap of various C++ Standard Template Library (STL) containers, complete with simple examples and their corresponding outputs. Whether you're a beginner or looking to refresh your knowledge, this guide covers:

- **Associative Containers**: `map`, `set`, `multimap`, `multiset`
- **Unordered Associative Containers**: `unordered_map`, `unordered_set`, `unordered_multimap`, `unordered_multiset`
- **Container Adapters**: `queue`, `stack`
- **Sequence Containers**: `deque`

---

## Table of Contents

1. [std::map](#1-stdmap)
2. [std::set](#2-stdset)
3. [std::unordered_map](#3-stdunordered_map)
4. [std::unordered_set](#4-stdunordered_set)
5. [std::multimap](#5-stdmultimap)
6. [std::multiset](#6-stdmultiset)
7. [std::unordered_multiset](#7-stdunordered_multiset)
8. [std::unordered_multimap](#8-stdunordered_multimap)
9. [std::queue](#9-stdqueue)
10. [std::stack](#10-stdstack)
11. [std::deque](#11-stddeque)
12. [Summary](#12-summary)

---

## 1. `std::map`

### Description

`std::map` is an associative container that stores elements as key-value pairs in a specific order (typically ascending). Each key is unique.

### Examples

#### Example 1: Basic Usage

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> age;
    age["Alice"] = 30;
    age["Bob"] = 25;
    age["Charlie"] = 35;

    for (const auto &pair : age) {
        std::cout << pair.first << " is " << pair.second << " years old.\n";
    }

    return 0;
}
```

**Output:**
```
Alice is 30 years old.
Bob is 25 years old.
Charlie is 35 years old.
```

---

#### Example 2: Finding Elements

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> students = { {1, "John"}, {2, "Emma"}, {3, "Liam"} };
    
    int key = 2;
    auto it = students.find(key);
    if (it != students.end()) {
        std::cout << "Student with ID " << key << " is " << it->second << ".\n";
    } else {
        std::cout << "Student with ID " << key << " not found.\n";
    }

    return 0;
}
```

**Output:**
```
Student with ID 2 is Emma.
```

---

#### Example 3: Iterating in Reverse Order

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<char, int> alphabet = { {'a', 1}, {'b', 2}, {'c', 3} };
    
    for(auto it = alphabet.rbegin(); it != alphabet.rend(); ++it){
        std::cout << it->first << ": " << it->second << "\n";
    }

    return 0;
}
```

**Output:**
```
c: 3
b: 2
a: 1
```

---

## 2. `std::set`

### Description

`std::set` is an associative container that contains a sorted set of unique objects of type `Key`. It automatically orders the elements and ensures that no duplicates exist.

### Examples

#### Example 1: Inserting Elements

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> numbers = {5, 3, 9, 1};
    numbers.insert(7);
    numbers.insert(3); // Duplicate, won't be added

    for(const auto &num : numbers){
        std::cout << num << " ";
    }

    return 0;
}
```

**Output:**
```
1 3 5 7 9 
```

---

#### Example 2: Checking for Existence

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<std::string> fruits = {"apple", "banana", "cherry"};
    
    std::string fruit = "banana";
    if(fruits.find(fruit) != fruits.end()){
        std::cout << fruit << " is in the set.\n";
    } else {
        std::cout << fruit << " is not in the set.\n";
    }

    return 0;
}
```

**Output:**
```
banana is in the set.
```

---

#### Example 3: Size and Clear

```cpp
#include <iostream>
#include <set>

int main() {
    std::set<char> letters = {'x', 'y', 'z'};
    std::cout << "Size before clear: " << letters.size() << "\n";
    
    letters.clear();
    std::cout << "Size after clear: " << letters.size() << "\n";

    return 0;
}
```

**Output:**
```
Size before clear: 3
Size after clear: 0
```

---

## 3. `std::unordered_map`

### Description

`std::unordered_map` is an associative container that stores key-value pairs with unique keys using a hash table. It provides average constant-time complexity for lookups, insertions, and deletions. The elements are not stored in any particular order.

### Examples

#### Example 1: Basic Insertion and Access

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, double> products;
    products["Laptop"] = 999.99;
    products["Smartphone"] = 499.49;
    products["Tablet"] = 299.99;

    std::cout << "Laptop price: $" << products["Laptop"] << "\n";

    return 0;
}
```

**Output:**
```
Laptop price: $999.99
```

---

#### Example 2: Iterating Over Elements

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, char> code = { {1, 'A'}, {2, 'B'}, {3, 'C'} };
    
    for(const auto &pair : code){
        std::cout << pair.first << " : " << pair.second << "\n";
    }

    return 0;
}
```

**Possible Output:**
```
1 : A
2 : B
3 : C
```
*Note: The order may vary since `unordered_map` does not maintain order.*

---

#### Example 3: Checking Size and Emplacing

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> inventory;
    inventory.emplace("Pens", 100);
    inventory.emplace("Notebooks", 50);
    inventory.emplace("Erasers", 75);

    std::cout << "Inventory size: " << inventory.size() << "\n";

    return 0;
}
```

**Output:**
```
Inventory size: 3
```

---

## 4. `std::unordered_set`

### Description

`std::unordered_set` is an associative container that contains a set of unique objects of type `Key`. It uses a hash table for storage, providing average constant-time complexity for lookups, insertions, and deletions. Elements are not stored in any particular order.

### Examples

#### Example 1: Basic Insertion and Display

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> colors = {"red", "green", "blue"};
    colors.insert("yellow");
    colors.insert("green"); // Duplicate, won't be added

    for(const auto &color : colors){
        std::cout << color << " ";
    }

    return 0;
}
```

**Possible Output:**
```
blue green red yellow 
```
*Note: The order may vary.*

---

#### Example 2: Checking Presence

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> primes = {2, 3, 5, 7, 11};
    
    int number = 7;
    if(primes.find(number) != primes.end()){
        std::cout << number << " is a prime number.\n";
    } else {
        std::cout << number << " is not a prime number.\n";
    }

    return 0;
}
```

**Output:**
```
    7 is a prime number.
```

---

#### Example 3: Erasing Elements

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    vowels.erase('i');

    for(const auto &vowel : vowels){
        std::cout << vowel << " ";
    }

    return 0;
}
```

**Possible Output:**
```
a e o u 
```
*Note: The order may vary.*

---

## 5. `std::multimap`

### Description

`std::multimap` is similar to `std::map` but allows multiple elements with the same key. It is useful when you need to associate multiple values with a single key.

### Examples

#### Example 1: Multiple Values per Key

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<std::string, int> scores;
    scores.emplace("Alice", 85);
    scores.emplace("Bob", 90);
    scores.emplace("Alice", 95);

    for(const auto &pair : scores){
        std::cout << pair.first << " scored " << pair.second << "\n";
    }

    return 0;
}
```

**Output:**
```
Alice scored 85
Alice scored 95
Bob scored 90
```

---

#### Example 2: Counting Elements with a Key

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<char, int> letters = { {'a', 1}, {'b', 2}, {'a', 3}, {'c', 4} };
    
    char key = 'a';
    std::cout << "Number of elements with key '" << key << "': " << letters.count(key) << "\n";

    return 0;
}
```

**Output:**
```
Number of elements with key 'a': 2
```

---

#### Example 3: Range of Elements with a Key

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> events = { {1, "Start"}, {2, "Middle"}, {1, "Initialization"}, {3, "End"} };
    
    int key = 1;
    auto range = events.equal_range(key);
    std::cout << "Events with key " << key << ":\n";
    for(auto it = range.first; it != range.second; ++it){
        std::cout << it->second << "\n";
    }

    return 0;
}
```

**Output:**
```
Events with key 1:
Start
Initialization
```

---

## 6. `std::multiset`

### Description

`std::multiset` is similar to `std::set` but allows multiple elements with equivalent values. It maintains elements in a specific order and permits duplicates.

### Examples

#### Example 1: Inserting Duplicate Elements

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<int> numbers = {1, 2, 2, 3, 4};
    numbers.insert(2);
    
    for(const auto &num : numbers){
        std::cout << num << " ";
    }

    return 0;
}
```

**Output:**
```
1 2 2 2 3 4 
```

---

#### Example 2: Counting Specific Elements

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<std::string> animals = {"cat", "dog", "cat", "bird"};
    
    std::string target = "cat";
    std::cout << target << " appears " << animals.count(target) << " times.\n";

    return 0;
}
```

**Output:**
```
cat appears 2 times.
```

---

#### Example 3: Erasing All Instances of a Value

```cpp
#include <iostream>
#include <set>

int main() {
    std::multiset<char> letters = {'a', 'b', 'a', 'c', 'a'};
    letters.erase('a');

    for(const auto &ch : letters){
        std::cout << ch << " ";
    }

    return 0;
}
```

**Output:**
```
b c 
```

---

## 7. `std::unordered_multiset`

### Description

`std::unordered_multiset` is similar to `std::multiset` but uses a hash table for storage. It allows multiple equivalent elements with average constant-time complexity for operations. Elements are not stored in any particular order.

### Examples

#### Example 1: Inserting Elements with Duplicates

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> nums = {1, 2, 2, 3};
    nums.emplace(2);
    
    for(const auto &num : nums){
        std::cout << num << " ";
    }

    return 0;
}
```

**Possible Output:**
```
1 2 2 3 2 
```
*Note: The order may vary.*

---

#### Example 2: Counting Elements

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<std::string> words = {"hello", "world", "hello"};
    
    std::cout << "\"hello\" appears " << words.count("hello") << " times.\n";

    return 0;
}
```

**Output:**
```
"hello" appears 2 times.
```

---

#### Example 3: Erasing Specific Instances

```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<char> chars = {'x', 'y', 'x', 'z'};
    auto it = chars.find('x');
    if(it != chars.end()){
        chars.erase(it); // Erases only one 'x'
    }

    for(const auto &ch : chars){
        std::cout << ch << " ";
    }

    return 0;
}
```

**Possible Output:**
```
y x z 
```
*Note: The order may vary.*

---

## 8. `std::unordered_multimap`

### Description

`std::unordered_multimap` is similar to `std::multimap` but uses a hash table for storage. It allows multiple elements with equivalent keys and does not maintain any specific order.

### Examples

#### Example 1: Inserting Multiple Values per Key

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_multimap<std::string, int> grades;
    grades.emplace("Alice", 85);
    grades.emplace("Bob", 90);
    grades.emplace("Alice", 95);

    for(const auto &pair : grades){
        std::cout << pair.first << " has grade " << pair.second << "\n";
    }

    return 0;
}
```

**Possible Output:**
```
Alice has grade 85
Alice has grade 95
Bob has grade 90
```
*Note: The order may vary.*

---

#### Example 2: Finding All Values for a Key

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_multimap<char, std::string> events = { {'A', "Apple"}, {'B', "Banana"}, {'A', "Avocado"} };
    
    char key = 'A';
    auto range = events.equal_range(key);
    std::cout << "Events with key '" << key << "':\n";
    for(auto it = range.first; it != range.second; ++it){
        std::cout << it->second << "\n";
    }

    return 0;
}
```

**Possible Output:**
```
Events with key 'A':
Apple
Avocado
```
*Note: The order may vary.*

---

#### Example 3: Counting Entries for a Key

```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_multimap<int, std::string> data = { {1, "One"}, {2, "Two"}, {1, "Uno"} };
    
    int key = 1;
    std::cout << "Number of entries with key " << key << ": " << data.count(key) << "\n";

    return 0;
}
```

**Output:**
```
Number of entries with key 1: 2
```

---

## 9. `std::queue`

### Description

`std::queue` is a container adapter that provides FIFO (First-In-First-Out) data structure operations. It allows insertion at the back and removal from the front.

### Examples

#### Example 1: Basic Queue Operations

```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    while(!q.empty()){
        std::cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
```

**Output:**
```
10 20 30 
```

---

#### Example 2: Checking Size and Front Element

```cpp
#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> q;
    q.push("first");
    q.push("second");

    std::cout << "Queue size: " << q.size() << "\n";
    std::cout << "Front element: " << q.front() << "\n";

    return 0;
}
```

**Output:**
```
Queue size: 2
Front element: first
```

---

#### Example 3: Using Queue with Custom Data Types

```cpp
#include <iostream>
#include <queue>

struct Point {
    int x, y;
};

int main() {
    std::queue<Point> q;
    q.push(Point{1, 2});
    q.push(Point{3, 4});

    while(!q.empty()){
        Point p = q.front();
        std::cout << "(" << p.x << ", " << p.y << ") ";
        q.pop();
    }

    return 0;
}
```

**Output:**
```
(1, 2) (3, 4) 
```

---

## 10. `std::stack`

### Description

`std::stack` is a container adapter that provides LIFO (Last-In-First-Out) data structure operations. It allows insertion and removal only from the top of the stack.

### Examples

#### Example 1: Basic Stack Operations

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(100);
    s.push(200);
    s.push(300);

    while(!s.empty()){
        std::cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
```

**Output:**
```
300 200 100 
```

---

#### Example 2: Checking Top Element

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<std::string> s;
    s.push("apple");
    s.push("banana");

    std::cout << "Top element: " << s.top() << "\n";

    return 0;
}
```

**Output:**
```
Top element: banana
```

---

#### Example 3: Using Stack with Custom Data Types

```cpp
#include <iostream>
#include <stack>

struct Employee {
    std::string name;
    int id;
};

int main() {
    std::stack<Employee> s;
    s.push(Employee{"Alice", 101});
    s.push(Employee{"Bob", 102});

    while(!s.empty()){
        Employee e = s.top();
        std::cout << "Employee: " << e.name << ", ID: " << e.id << "\n";
        s.pop();
    }

    return 0;
}
```

**Output:**
```
Employee: Bob, ID: 102
Employee: Alice, ID: 101
```

---

## 11. `std::deque`

### Description

`std::deque` (double-ended queue) is a sequence container that allows fast insertion and deletion at both the front and the back. It supports random access to elements, similar to `std::vector`.

### Examples

#### Example 1: Inserting at Both Ends

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);

    for(const auto &num : d){
        std::cout << num << " ";
    }

    return 0;
}
```

**Output:**
```
2 1 3 
```

---

#### Example 2: Accessing Elements by Index

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<std::string> dq = {"alpha", "beta", "gamma"};
    
    std::cout << "First element: " << dq[0] << "\n";
    std::cout << "Third element: " << dq[2] << "\n";

    return 0;
}
```

**Output:**
```
First element: alpha
Third element: gamma
```

---

#### Example 3: Iterating and Modifying Elements

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> d = {10, 20, 30, 40};
    
    // Double each element
    for(auto &num : d){
        num *= 2;
    }

    for(const auto &num : d){
        std::cout << num << " ";
    }

    return 0;
}
```

**Output:**
```
20 40 60 80 
```

---

## 12. Summary

C++ offers a rich set of container classes in its Standard Template Library (STL) to manage data efficiently. Here's a quick overview of the containers discussed:

- **Associative Containers**:
  - `std::map`: Unique key-value pairs, ordered.
  - `std::set`: Unique elements, ordered.
  - `std::multimap`: Multiple key-value pairs with the same key, ordered.
  - `std::multiset`: Multiple identical elements, ordered.

- **Unordered Associative Containers**:
  - `std::unordered_map`: Unique key-value pairs, unordered.
  - `std::unordered_set`: Unique elements, unordered.
  - `std::unordered_multimap`: Multiple key-value pairs with the same key, unordered.
  - `std::unordered_multiset`: Multiple identical elements, unordered.

- **Container Adapters**:
  - `std::queue`: FIFO (First-In-First-Out).
  - `std::stack`: LIFO (Last-In-First-Out).

- **Sequence Containers**:
  - `std::deque`: Double-ended queue, allows insertion/removal from both ends.

