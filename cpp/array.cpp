#include<iostream>

int main() {

std::string array[4];

for(int i=0; i<4; i++) {

   std::cout << "Enter name " << i+1 << ": ";
   std::cin >> array[i];

}

std::cout << "The names are:" << std::endl;

for(int u=0; u<4; u++) {

   std::cout << array[u] << std::endl;

}

    return 0;
}