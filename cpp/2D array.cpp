#include <iostream>
#include <array>

int main(){

std::array<std::array<int, 2>, 2>arr{{    //outer is row inner is colomn

   {1,2},
   {3,4}

}};

std::cout << arr[0][1] << std::endl; //arr[row][colomn]

return 0;
}