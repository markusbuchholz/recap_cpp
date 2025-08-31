#include <iostream>
#include <memory>
#include <vector>

int main()
{

    int a = 10;
    int *pa;
    pa = &a;
    std::cout << "test 1 " << *pa << std::endl;

   // delete pa; // no delete here, because 'a' is on the stack
    //-------------------//

    int *pb = new int;
    *pb = 20;
    std::cout << "test 2 " << *pb << std::endl;
    delete pb;            // free heap

   
    //-------------------//


    std::unique_ptr<int> p = std::make_unique<int> (30);
    std::cout << "test 3 " << *p << std::endl;

    //-------------------//

    std::unique_ptr<int> pp1; 
    auto pp2 = std::make_unique<int>();
    
    pp1 = std::make_unique<int>(300);
    *pp2 = 400;
    std::cout << "test 4 " << *pp1 << std::endl;
    std::cout << "test 5 " << *pp2 << std::endl;

 


    //-------------------//



}