#include <iostream>


int main() {

 //variables
 double grade = 0;
 double total = 0;
 int gradecounter = 0;
 double final;

 //setting while loop to run infinitly until a condition breaks it 
 while(true) {

 std::cout << "Enter grade, or enter -1 to exit and calulate final grade: ";
 std::cin >> grade;

 //conditions
 if(grade == -1){

     final = total / gradecounter;
     std::cout << "final grade: " << final << "/100";
     break;
 }

 if(grade < 0 || grade > 100) {
     std::cout << "Number is invalid" << std::endl;
     continue;
 }

 if(grade >= 90) {
    std::cout << "Grade: A" << std::endl;
 }

 else if(grade >= 80 && grade <= 89) {
    std::cout << "Grade: B" << std::endl;
 }
 
 else if(grade >= 70 && grade <= 79) {
    std::cout << "Grade: C" << std::endl;
 }

 else if(grade >= 60 && grade <= 69) {
    std::cout << "Grade: D" << std::endl;
 }

 else if(grade <= 59) {
 std::cout << "Grade: F" << std::endl;
 }

 //grade adder and counter
 gradecounter ++;
 total += grade;

 }


 return 0;
}
