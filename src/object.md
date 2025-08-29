
# C++ OOP Concepts Recap



## Table of Contents

1. [Classes](#1-classes)
2. [Constructors](#2-constructors)
3. [Special Members](#3-special-members)
4. [Friendship and Inheritance](#4-friendship-and-inheritance)
5. [Polymorphism](#5-polymorphism)
6. [Summary](#6-summary)

---

## 1. Classes

### Description

A **class** in C++ is a user-defined data type that serves as a blueprint for creating objects. It encapsulates data (attributes) and functions (methods) that operate on the data. Classes facilitate the principles of abstraction, encapsulation, and modularity in programming.

### Examples

#### Example 1: Basic Class Definition and Object Creation

```cpp
#include <iostream>

class Car {
public:
    std::string brand;
    int year;

    void displayInfo() {
        std::cout << "Brand: " << brand << ", Year: " << year << "\n";
    }
};

int main() {
    Car car1;
    car1.brand = "Toyota";
    car1.year = 2020;

    car1.displayInfo();

    return 0;
}
```

**Output:**
```
Brand: Toyota, Year: 2020
```

---

#### Example 2: Class with Private Members and Public Methods

```cpp
#include <iostream>

class Rectangle {
private:
    double length;
    double width;

public:
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    double area() const {
        return length * width;
    }
};

int main() {
    Rectangle rect;
    rect.setDimensions(5.0, 3.0);
    std::cout << "Area of Rectangle: " << rect.area() << "\n";

    return 0;
}
```

**Output:**
```
Area of Rectangle: 15
```

---

#### Example 3: Class with Member Functions and Access Specifiers

```cpp
#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0.0) {} // Constructor initializes balance to 0

    void deposit(double amount) {
        if(amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if(amount > 0 && amount <= balance)
            balance -= amount;
        else
            std::cout << "Insufficient funds.\n";
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account;
    account.deposit(500.0);
    account.withdraw(150.0);
    std::cout << "Current Balance: $" << account.getBalance() << "\n";

    account.withdraw(400.0); // Attempt to withdraw more than the balance

    return 0;
}
```

**Output:**
```
Current Balance: $350
Insufficient funds.
```

---

## 2. Constructors

### Description

**Constructors** are special member functions of a class that are invoked automatically when an object of the class is created. They are primarily used to initialize the object's members. C++ supports several types of constructors:

- **Default Constructor**: Takes no arguments.
- **Parameterized Constructor**: Takes arguments to initialize object members.
- **Copy Constructor**: Initializes an object using another object of the same class.

### Examples

#### Example 1: Default Constructor

```cpp
#include <iostream>

class Point {
public:
    int x, y;

    // Default constructor
    Point() : x(0), y(0) {}

    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p;
    p.display();

    return 0;
}
```

**Output:**
```
(0, 0)
```

---

#### Example 2: Parameterized Constructor

```cpp
#include <iostream>

class Point {
public:
    int x, y;

    // Parameterized constructor
    Point(int a, int b) : x(a), y(b) {}

    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(5, 10);
    Point p2(-3, 7);

    p1.display();
    p2.display();

    return 0;
}
```

**Output:**
```
(5, 10)
(-3, 7)
```

---

#### Example 2.1 

```cpp
#include <iostream>

class Point {
public:
    int x, y;

    // Parameterized constructor
    Point(int a, int b) {
        this->x = a;
        this->y = b;
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(50, 100);
    Point p2(-32, 7);

    p1.display();
    p2.display();

    return 0;
}
```
**Output:**
```
(50, 100)
(-32, 7)
```

---

#### Example 3: Copy Constructor

```cpp
#include <iostream>

class Point {
public:
    int x, y;

    // Parameterized constructor
    Point(int a, int b) : x(a), y(b) {}

    // Copy constructor
    Point(const Point &p) : x(p.x), y(p.y) {}

    void display() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

int main() {
    Point p1(8, 12);
    Point p2 = p1; // Invokes copy constructor

    p1.display();
    p2.display();

    return 0;
}
```

**Output:**
```
(8, 12)
(8, 12)
```

---

## 3. Special Members

### Description

**Special Members** in C++ refer to certain member functions that the compiler may generate automatically if they are not explicitly defined by the programmer. These include:

- **Destructor**: Cleans up when an object is destroyed.
- **Copy Constructor**: Initializes an object using another object of the same class.
- **Copy Assignment Operator**: Assigns values from one object to another existing object.
- **Move Constructor**: Initializes an object by transferring resources from another object.
- **Move Assignment Operator**: Assigns values by transferring resources from another object.

Understanding and correctly implementing special members is crucial for managing resources, especially when dealing with dynamic memory.

### Examples

#### Example 1: Destructor

```cpp
#include <iostream>

class Logger {
public:
    Logger() {
        std::cout << "Logger initialized.\n";
    }

    ~Logger() {
        std::cout << "Logger destroyed.\n";
    }
};

int main() {
    {
        Logger log;
    } // log goes out of scope here

    std::cout << "End of main.\n";

    return 0;
}
```

**Output:**
```
Logger initialized.
Logger destroyed.
End of main.
```

---

#### Example 2: Copy Constructor and Copy Assignment Operator

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

    void display() const {
        if(str)
            std::cout << str << "\n";
        else
            std::cout << "Empty String.\n";
    }
};

int main() {
    String s1("Hello");
    String s2 = s1; // Copy constructor
    String s3("World");
    s3 = s1; // Copy assignment

    s1.display();
    s2.display();
    s3.display();

    return 0;
}
```

**Output:**
```
Hello
Hello
Hello
```

---

#### Example 3: Move Constructor and Move Assignment Operator

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

## 4. Friendship and Inheritance

### Description

**Friendship** and **Inheritance** are two fundamental concepts in C++ OOP:

- **Friendship**: Allows one class or function to access the private and protected members of another class.
- **Inheritance**: Enables a new class (derived class) to acquire the properties and behaviors of an existing class (base class), promoting code reusability and hierarchical relationships.

### Examples

#### Example 1: Friend Function

```cpp
#include <iostream>

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    // Declare friend function
    friend void printWidth(const Box &b);
};

// Friend function definition
void printWidth(const Box &b) {
    std::cout << "Width of box: " << b.width << "\n";
}

int main() {
    Box box(12.5);
    printWidth(box);

    return 0;
}
```

**Output:**
```
Width of box: 12.5
```

---

#### Example 2: Friend Class

```cpp
#include <iostream>

class Engine {
private:
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    // Declare friend class
    friend class Car;
};

class Car {
private:
    Engine engine;

public:
    Car(int hp) : engine(hp) {}

    void showEnginePower() const {
        std::cout << "Engine horsepower: " << engine.horsepower << "\n";
    }
};

int main() {
    Car car(250);
    car.showEnginePower();

    return 0;
}
```

**Output:**
```
Engine horsepower: 250
```

---

#### Example 3: Inheritance (Single Inheritance)

```cpp
#include <iostream>

// Base class
class Animal {
public:
    void eat() const {
        std::cout << "Eating...\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() const {
        std::cout << "Barking...\n";
    }
};

int main() {
    Dog dog;
    dog.eat();  // Inherited from Animal
    dog.bark();

    return 0;
}
```

**Output:**
```
Eating...
Barking...
```

---

## 5. Polymorphism

### Description

**Polymorphism** Base class (often abstract) that defines a common interface (pure virtual functions). Derived classes that override those functions with their own behavior.
Base class pointer or reference to call the function, and the correct derived version runs at runtime.

### Examples

#### Example 0: (abstract base + polymorphism) 

```cpp
#include <iostream>

// Abstract class (cannot be instantiated)
class Animal {
public:
    virtual void speak() = 0; // pure virtual function
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Dog barks\n"; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Cat meows\n"; }
};

int main() {
    Animal* a1 = new Dog();  // base class pointer → Dog object
    Animal* a2 = new Cat();  // base class pointer → Cat object

    a1->speak(); // calls Dog::speak → "Dog barks"
    a2->speak(); // calls Cat::speak → "Cat meows"

    delete a1;
    delete a2;
}

```
---

#### Example 1: Function Overloading (Compile-Time Polymorphism)

```cpp
#include <iostream>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add two doubles
double add(double a, double b) {
    return a + b;
}

int main() {
    std::cout << "Sum of integers: " << add(5, 3) << "\n";
    std::cout << "Sum of doubles: " << add(2.5, 4.3) << "\n";

    return 0;
}
```

**Output:**
```
Sum of integers: 8
Sum of doubles: 6.8
```

---

#### Example 2: Virtual Functions (Run-Time Polymorphism)

```cpp
#include <iostream>

class Shape {
public:
    // Virtual function
    virtual void draw() const {
        std::cout << "Drawing Shape.\n";
    }

    virtual ~Shape() {} // Virtual destructor
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle.\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Rectangle.\n";
    }
};

void render(const Shape &s) {
    s.draw();
}

int main() {
    Circle circle;
    Rectangle rectangle;
    Shape shape;

    render(circle);      // Calls Circle::draw
    render(rectangle);   // Calls Rectangle::draw
    render(shape);       // Calls Shape::draw

    return 0;
}
```

**Output:**
```
Drawing Circle.
Drawing Rectangle.
Drawing Shape.
```

---

#### Example 3: Abstract Classes and Pure Virtual Functions

```cpp
#include <iostream>

// Abstract base class
class Animal {
public:
    // Pure virtual function
    virtual void makeSound() const = 0;

    virtual ~Animal() {}
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Meow!\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Woof!\n";
    }
};

int main() {
    // Animal a; // Error: Cannot instantiate abstract class

    Cat cat;
    Dog dog;

    Animal *animals[2] = { &cat, &dog };

    for(auto animal : animals){
        animal->makeSound();
    }

    return 0;
}
```

**Output:**
```
Meow!
Woof!
```

---

## 6. Summary

C++ Object-Oriented Programming (OOP) offers powerful features to create modular, reusable, and maintainable code. Here's a quick overview of the concepts covered:

- **Classes**: Blueprints for creating objects, encapsulating data and functions.
- **Constructors**: Special functions to initialize objects. Includes default, parameterized, and copy constructors.
- **Special Members**: Include destructors, copy/move constructors, and copy/move assignment operators. Essential for resource management.
- **Friendship and Inheritance**:
  - **Friendship**: Grants access to private and protected members across classes or functions.
  - **Inheritance**: Establishes hierarchical relationships, promoting code reuse.
- **Polymorphism**:
  - **Compile-Time**: Achieved through function overloading and templates.
  - **Run-Time**: Achieved through virtual functions, enabling dynamic behavior based on object types.


