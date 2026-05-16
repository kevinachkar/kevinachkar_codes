#include <iostream>

//prototypes
double division(double a, double b);
void print(double value);

//first func(divide)
double division(double a, double b){

    return a/b;
}

//sec func(print)
void print(double value){

    std::cout << value;
}

int main(){

 double x;
 double y;

 double result;

 std::cout << "Enter first number(x): ";
 std::cin >> x;
 std::cout << "Enter second number(y): ";
 std::cin >> y;

 // positve only and division by 0 error
 if(x<0 || y<=0){

    std::cout << "1st or 2nd number must be positive and 2nd number cant be zero.";
    return 0;
 }

 std::cout << "x divided by y is: ";
 print(division(x, y));

 return 0;
}