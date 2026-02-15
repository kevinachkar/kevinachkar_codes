#include <iostream>

void counter() {

for(int i=0; i<100000; i++) {

  std::cout << i << std::endl;

}


}

int main() {

  counter();

  return 0;
}