#include <iostream>
#include <random>
#include <ctime>

int main() {

    std::default_random_engine engine(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<unsigned int> getrandom(1, 6);

    std::cout << getrandom(engine);

    return 0;
}