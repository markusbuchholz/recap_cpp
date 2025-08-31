#include <iostream>
#include <memory>
#include <vector>
#include <array>
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
    std::cout << "==== Raw pointers ====\n";
    float pi = 3.1415;
    float *ptrPi = &pi;
    std::cout << "pi via pointer: " << *ptrPi << "\n";

    int *ptr = new int;
    *ptr = 25;
    std::cout << "Heap int: " << *ptr << "\n";
    delete ptr;

    int size = 5;
    int *arr = new int[size]; // uninitialized!
    for (int i = 0; i < size; i++) arr[i] = i * 10;
    std::cout << "Dynamic array: ";
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
    delete[] arr;

    int arr2[] = {100, 200, 300, 400, 500};
    int *ptr1 = &arr2[1]; // 200
    int *ptr2 = &arr2[4]; // 500
    std::cout << "arr2[1] via ptr1: " << *ptr1 << "\n";
    std::cout << "arr2[4] via ptr2: " << *ptr2 << "\n";

    std::cout << "\n==== Smart pointers ====\n";
    std::unique_ptr<int> up1; // empty
    auto up2 = std::make_unique<int>(10);
    std::cout << "unique_ptr up2: " << *up2 << "\n";

    int n = 4;
    auto upArr = std::make_unique<int[]>(n);
    for (int i = 0; i < n; i++) upArr[i] = i + 1;
    std::cout << "unique_ptr array: ";
    for (int i = 0; i < n; i++) std::cout << upArr[i] << " ";
    std::cout << "\n";

    auto sp = std::make_shared<int>(99);
    std::cout << "shared_ptr sp: " << *sp << " (use_count=" << sp.use_count() << ")\n";

    std::cout << "\n==== std::vector ====\n";
    std::vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    std::cout << "Vector contents: ";
    for (auto v : vec) std::cout << v << " ";
    std::cout << "\n";

    std::vector<int>* dynamicVector = new std::vector<int>();
    dynamicVector->push_back(10);
    dynamicVector->push_back(20);
    dynamicVector->push_back(30);
    std::cout << "Dynamic vector contents: ";
    for (auto v : *dynamicVector) std::cout << v << " ";
    std::cout << "\n";
    delete dynamicVector;

    std::cout << "\n==== std::array ====\n";
    std::array<int, 5> arr3 = {5, 10, 15, 20, 25};
    for (auto v : arr3) std::cout << v << " ";
    std::cout << "\n";

    std::cout << "\n==== Custom class with new ====\n";
    int numBooks = 2;
    Book *books = new Book[numBooks];
    books[0].title = "C++ Basics"; books[0].price = 29.99;
    books[1].title = "Advanced C++"; books[1].price = 49.99;

    for (int i = 0; i < numBooks; i++) {
        books[i].display();
    }
    delete[] books;

    return 0;
}


/*

==== Raw pointers ====
pi via pointer: 3.1415
Heap int: 25
Dynamic array: 0 10 20 30 40 
arr2[1] via ptr1: 200
arr2[4] via ptr2: 500

==== Smart pointers ====
unique_ptr up2: 10
unique_ptr array: 1 2 3 4 
shared_ptr sp: 99 (use_count=1)

==== std::vector ====
Vector contents: 1 2 3 4 
Dynamic vector contents: 10 20 30 

==== std::array ====
5 10 15 20 25 

==== Custom class with new ====
Title: C++ Basics, Price: $29.99
Title: Advanced C++, Price: $49.99

*/