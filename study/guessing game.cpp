#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

int random(){

    int random = rand() % 101;
    return random;

}

int main() {

    int guess;

    srand(time(0));

    std::array<int, 4> rnd = {};
    std::array<int, 4> gs = {};

    for(int i=0; i<4; i++){
        rnd[i] = random();
    }

    for(int i=0; i<4; i++) {
        std::cout << rnd[i] << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    for(int i=0; i<100; i++){
        std::cout << "..........GUESSING GAME.........." << std::endl;
        }

    for(int i=0; i<4; i++){
        std::cout << "Enter guess: ";
        std::cin >> gs[i];

        if(rnd[i] == gs[i]){
            if(rnd[3] == gs[3]){
                std::cout << "CORRECT";
            }
            else{
            continue;
            }
        }
        else{
            std::cout << "Wrong guess.";
            break;
        }

    }
    
    return 0;
}