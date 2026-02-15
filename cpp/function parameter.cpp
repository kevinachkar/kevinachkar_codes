#include <iostream>

void change(int x) {
    x = 50;
    std::cout << "Inside function, x = " << x << std::endl;
}

int main() {
    int a = 10;

    std::cout << "Before function, a = " << a << std::endl;

    change(a);

    std::cout << "After function, a = " << a << std::endl;

    return 0;
}
