#include <iostream>
#include <memory>

// Abstract base class (interface for all sensors)

/*
Sensor is an abstract class because it has a pure virtual function (= 0).
It acts as an interface: it tells all derived classes “you must implement readData()”.
You cannot do Sensor s; because abstract classes cannot be instantiated.
But you can use a pointer or reference to Sensor (e.g., std::unique_ptr<Sensor>) to access derived objects.
*/
class Sensor {
public:
    virtual void readData() = 0; // pure virtual → must be implemented
    virtual ~Sensor() = default; // virtual destructor (important!)

    virtual int compute(int a, int b) { 
        std::cout << "Default compute\n"; 
        return 0; 
    }
};

// Derived class: Camera sensor
class Camera : public Sensor {
public:
    void readData() override {
        std::cout << "Camera capturing image...\n";
    }
};

// Derived class: IMU sensor
class IMU : public Sensor {
public:
    void readData() override {
        std::cout << "IMU measuring acceleration and orientation...\n";
    }
};

// Derived class: Sonar sensor

class Sonar : public Sensor {
public:
    void readData() override {
        std::cout << "Sonar detecting distance to obstacle...\n";
    }

    int compute (int a, int b)override{
        std::cout << "computing :" << std::endl;

        return  a * b;
    }
};

int main() {
    // Polymorphism: base class pointer to different derived objects
    std::unique_ptr<Sensor> s1 = std::make_unique<Camera>();
    std::unique_ptr<Sensor> s2 = std::make_unique<IMU>();
    std::unique_ptr<Sensor> s3 = std::make_unique<Sonar>();

    s1->readData(); // "Camera capturing image..."
    s2->readData(); // "IMU measuring acceleration and orientation..."
    s3->readData(); // "Sonar detecting distance to obstacle..."
 
    s3->compute(10,20);
    
    std::unique_ptr<Sensor> sens;

    sens = std::make_unique<Camera>();
    sens->readData();

    sens = std::make_unique<IMU>();
    sens->readData();
}
