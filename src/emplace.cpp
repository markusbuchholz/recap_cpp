#include <iostream>
#include <vector>
#include <string>

struct Robot {
    std::string name;
    int id;

    Robot(std::string n, int i) : name(std::move(n)), id(i) {
        std::cout << "Robot constructed: " << name << "\n";
    }
};

int main() {
    std::vector<Robot> robots;

    // push_back: create a Robot first, then copy/move into vector
    robots.push_back(Robot("Alpha", 1));

    // emplace_back: construct Robot directly in the vector
    robots.emplace_back("Beta", 2);
}
