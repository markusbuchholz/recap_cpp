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
    Point p1(5, 10);
    Point p2(-32, 7);

    p1.display();
    p2.display();

    return 0;
}