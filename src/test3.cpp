#include <iostream>

class Animal {
public:
         virtual void speak() { // virtual → can be overridden
         std::cout << "Animal speaks\n";
         }
        //virtual void speak() = 0;
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Dog barks\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Cat meows\n";
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    Animal a3;    

    //Animal a;
    a1->speak();  // "Dog barks"
    a2->speak();  // "Cat meows"


    delete a1;
    delete a2;
}
