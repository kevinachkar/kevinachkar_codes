#include <iostream>

int main() {

 //variables
 int calories;
 int totalcalories = 0;

 //setting while loop to run infinitly until a condition breaks it 
 while(true) {

 std::cout << "Enter calories of the meal or -1 to calculate total calories: ";
 std::cin >> calories;

 //conditions
 if(calories == -1){
    break;
 }

 else if(calories < 0) {
     std::cout << "invalid value" << std::endl; 
 }

 else if(calories >= 0){
     totalcalories += calories;
 }
}

 std::cout << "Total calories: " << totalcalories;


 return 0;
}