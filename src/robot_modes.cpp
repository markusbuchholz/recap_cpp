#include <iostream>
#include <memory>

// Abstract base class for robot modes
class RobotMode {
protected:
    double speed;
    double sensitivity;
public:
    RobotMode(double spd, double sens) : speed(spd), sensitivity(sens) {}
    virtual ~RobotMode() = default;

    virtual void runTask() = 0;   // pure virtual → must be overridden
    virtual void status() {       // common function
        std::cout << "Speed = " << speed
                  << ", Sensitivity = " << sensitivity << "\n";
    }
};

// Mode A: exploration mode
class ModeA : public RobotMode {
public:
    ModeA(double spd, double sens) : RobotMode(spd, sens) {}
    void runTask() override {
        std::cout << "[Mode A] Exploring environment with LIDAR...\n";
    }
};

// Mode B: manipulation mode
class ModeB : public RobotMode {
public:
    ModeB(double spd, double sens) : RobotMode(spd, sens) {}
    void runTask() override {
        std::cout << "[Mode B] Performing object manipulation with arm...\n";
    }
};

// Robot class that can switch modes at runtime
class Robot {
private:
    std::unique_ptr<RobotMode> mode;  // polymorphic base pointer
public:
    // Set initial mode
    Robot(std::unique_ptr<RobotMode> m) : mode(std::move(m)) {}

    // Run current mode
    void operate() {
        mode->status();
        mode->runTask();
    }

    // Switch mode at runtime
    void switchMode(std::unique_ptr<RobotMode> newMode) {
        mode = std::move(newMode); // old mode automatically destroyed
        std::cout << ">>> Switched robot mode!\n";
    }
};

// MAIN
int main() {
    // Robot starts in Mode A with speed=1.0, sensitivity=0.5
    Robot r(std::make_unique<ModeA>(1.0, 0.5));
    r.operate();

    // Switch to Mode B with speed=2.5, sensitivity=0.8
    r.switchMode(std::make_unique<ModeB>(2.5, 0.8));
    r.operate();

    // Switch back to Mode A with different parameters
    r.switchMode(std::make_unique<ModeA>(3.0, 1.0));
    r.operate();
}
