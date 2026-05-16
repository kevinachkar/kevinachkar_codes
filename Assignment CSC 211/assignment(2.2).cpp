#include <iostream>
#include <iomanip>

//golbal
double DAILY_FINE = 0.5;

//recursion func
double sumFines(int days){
     if(days == 0)
     return 0;

 return DAILY_FINE * days + sumFines(days - 1);
}


int main(){

 std::cout << std::fixed << std::setprecision(2);
 
 double total;
 int x;
 std::cout << "Enter number of days overdue: ";
 std::cin >> x;
 if(x<0){
    std::cout << "days cant be negative";
    return 0;
 }

 total = sumFines(x);

 std::cout << "Total escalating fine for " << x << " days: $" << total;


 return 0;
}