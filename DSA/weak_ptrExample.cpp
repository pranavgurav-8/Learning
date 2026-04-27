#include <iostream>
#include <memory>

struct Engine {
    ~Engine() {
        std::cout << "Engine destroyed\n";
    }
};

struct Car {
    std::shared_ptr<Engine> engine; // owns Engine
};

struct Mechanic {
    std::weak_ptr<Engine> engine; // ✔ observes only
};
int main() {
    auto car = std::make_shared<Car>();
    car->engine = std::make_shared<Engine>();

    Mechanic m;
    m.engine = car->engine;

    car.reset();   // ✔ Engine destroyed
}
