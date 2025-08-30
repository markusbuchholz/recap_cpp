#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

const int NUM_ITER = 1000000;

// Shared counter (will try with mutex and atomic)
int counter_with_mutex = 0;
std::mutex mtx;

std::atomic<int> counter_atomic(0);

// Function using mutex for safety
void increment_with_mutex() {
    for (int i = 0; i < NUM_ITER; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // lock automatically released at end of scope
        ++counter_with_mutex;
    }
}

// Function using atomic for safety
void increment_with_atomic() {
    for (int i = 0; i < NUM_ITER; ++i) {
        ++counter_atomic; // atomic increment, no mutex needed
    }
}

int main() {
    // ---- Part 1: Using mutex ----
    std::thread t1(increment_with_mutex);
    std::thread t2(increment_with_mutex);

    t1.join();
    t2.join();

    std::cout << "Final counter (with mutex): " << counter_with_mutex << "\n";


    // ---- Part 2: Using atomic ----
    std::thread t3(increment_with_atomic);
    std::thread t4(increment_with_atomic);

    t3.join();
    t4.join();

    std::cout << "Final counter (with atomic): " << counter_atomic << "\n";

    return 0;
}
