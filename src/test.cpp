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

    
    int a = 20;
    int b = 40;

    int *ptr_a = new int;

    int *ptr_b;

    ptr_b = &b;

    std::cout << "Value of b via ptr_b: " << *ptr_b << std::endl;
    
    ptr_a = &b;
    
    std::cout << "Value of b via ptr_a: " << *ptr_a << std::endl;

    return 0;
}