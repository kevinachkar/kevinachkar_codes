#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>


int main(){

std::vector<int> vec = {10, 90, 60};

std::sort(vec.begin(), vec.end());

for(int i=0; i<vec.size(); i++){

    std::cout << vec[i] << std::endl;
}

bool found = std::binary_search(vec.begin(), vec.end(), 80);

if(found)
     std::cout << "number found" << std::endl;
else
     std::cout << "number not found";

    return 0;
}