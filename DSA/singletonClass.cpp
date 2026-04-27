#include <iostream>
initialization of static local variables is guaranteed thread-safe
class Singleton {
private:
    // 1️⃣ Private constructor
    Singleton() {
        std::cout << "Singleton constructor called\n";
    }

    // 2️⃣ Delete copy operations
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // 3️⃣ Global access point
    static Singleton& getInstance() {
        static Singleton instance;  // thread-safe since C++11
        return instance;
    }

    void doSomething() {
        std::cout << "Doing something...\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.doSomething();

    std::cout << (&s1 == &s2) << std::endl; // prints 1 (true)
}