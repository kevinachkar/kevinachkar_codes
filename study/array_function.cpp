#include <iostream>
#include<array>

void printArray(std::array<int,3> myarray){ // i create a new array in function parameters, just like creating an int a

  for(int i=0; i<myarray.size(); i++){

     std::cout << myarray[i] << std::endl;

  }

}


int main(){

    std::array<int, 3> arr = {1,4,7};

    printArray(arr);//i assign my original arr to be a copy of my array in function parameters


    return 0;
}