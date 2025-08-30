#include <iostream>
#include <algorithm>
#include <vector>

void print(int x)
{

    std::cout << " vec :" << x << std::endl;
}

int main()
{

    auto hello = []()
    { std::cout << "hello world" << std::endl; };

    hello();

    std::vector<int> vec = {10, 20, 30, 40};

    std::for_each(vec.begin(), vec.end(), print);

    std::for_each(vec.begin(), vec.end(), [](int x)
                  { std::cout << "run " << x << std::endl; });

    std::for_each(vec.begin(), vec.end(), [](int &x)

                  {
                      std::cout << "run before :" << x << std::endl;

                      x = x + 1;
                  });

    std::size_t i = 0;              
    for (auto &ii : vec){

        std::cout << "ii :" << ii  << std::endl;
        i++;
    }
}