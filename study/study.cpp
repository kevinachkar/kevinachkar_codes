#include <iostream>

struct motor {

int angle1;
int angle2;

};

int main() {

motor stepper[2];

 for(int i=0; i<2; i++){

std::cout << "Enter stepper " << i+1 << " angle 1: ";
std::cin >> stepper[i].angle1;

std::cout << "Enter stepper " << i << " angle 2: ";
std::cin >> stepper[i].angle2;

 }

 for(int i=0; i<2; i++) {

std::cout << "stepper " << i+1 << " 0angle 1: " << stepper[i].angle1 << std::endl;
std::cout << "stepper " << i+1 << " angle 1: " << stepper[i].angle2 << std::endl;

 }


}