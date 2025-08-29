#include <iostream>
#include <memory>

class Demo {
public:
    Demo(int v) : value(v) {
        std::cout << "Demo(" << value << ") created\n";
    }
    ~Demo() {
        std::cout << "Demo(" << value << ") destroyed\n";
    }
    int value;
};

int main() {
    // ---------- UNIQUE_PTR ----------
    {
        std::unique_ptr<Demo> u1 = std::make_unique<Demo>(1);
        // std::unique_ptr<Demo> u2 = u1; //  not allowed (no copy) !!!!!!!!
        std::unique_ptr<Demo> u2 = std::move(u1); //  transfer ownership

        std::cout << "unique_ptr owns Demo(1)\n";
    } // u2 goes out of scope -> automatically destroyed


    // ---------- SHARED_PTR ----------
    {
        std::shared_ptr<Demo> s1 = std::make_shared<Demo>(2);
        std::shared_ptr<Demo> s2 = s1; // copy -> both share ownership
        std::cout << "shared_ptr use_count = " << s1.use_count() << "\n";
    } // last shared_ptr goes out of scope -> destroyed here


    // ---------- WEAK_PTR ----------
    {
        std::shared_ptr<Demo> s3 = std::make_shared<Demo>(3);
        std::weak_ptr<Demo> w = s3; // weak observer, no ownership

        std::cout << "shared_ptr use_count = " << s3.use_count() << "\n";
        if (auto sp = w.lock()) { // try to promote weak_ptr to shared_ptr
            std::cout << "Accessing Demo(3): " << sp->value << "\n";
        }

        s3.reset(); // destroy managed object
        std::cout << "After reset, weak_ptr expired = " << w.expired() << "\n";
    } // weak_ptr doesn’t delete the object, just observes
}
