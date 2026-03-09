#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

srand(time(0));

int random = rand() % 10;

std::cout << random << std::endl;

    return 0;
}