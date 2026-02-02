#include<iostream>

struct robot {

int angle1;
int angle2;

};

int main() {

robot robots[3];

robots[0].angle1 = 13;
robots[0].angle2 = 27;

robots[1].angle1 = 8;
robots[1].angle2 = 21;

robots[2].angle1 = 189;
robots[2].angle2 = 83;

for(int i=0; i<3; i++){

   std::cout << "Robot angle " << i+1 << ": " << robots[i].angle1 << " ; " << robots[i].angle2 << std::endl;

}

    return 0;
}