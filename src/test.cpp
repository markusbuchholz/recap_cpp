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
    
    std::cout << "1. Value of b via ptr_a: " << *ptr_a << std::endl;
    
    b = 9999;
    std::cout << "2. Value of b via ptr_a: " << *ptr_a << std::endl;


    int value_1 = 100;
    int value_2 = 200;
    std::unique_ptr<int> u_ptr;

        // Assign a copy of value_1
    u_ptr = std::make_unique<int>(value_1);
    std::cout << "u_ptr points to: " << *u_ptr << std::endl;

    // Reassign to a copy of value_2
    u_ptr = std::make_unique<int>(value_2);
    std::cout << "1: u_ptr now points to : " << *u_ptr << std::endl;

    value_2 = 500;
    std::cout << "2: u_ptr now points to: " << *u_ptr << std::endl;


    std::shared_ptr<int> s_ptr;

    // ------------------------------------//
    std::weak_ptr<int> w_prt;




    

    
    return 0;
}