#include <iostream>
#include <array>
#include <vector>

int main(){

std::array<std::array<int,2> ,3> arr = {{

}};

for(int i=0; i<arr.size(); i++){
    for(int u=0; u<arr[i].size(); u++){
        std::cout << "enter number: ";
        std::cin >> arr[i][u];
    }
}

for(int i=0; i<arr.size(); i++){
    for(int u=0; u<arr[i].size(); u++){
        std::cout << arr[i][u] << " ";
    }
    std::cout << std::endl;
}


    return 0;
}