#include <iostream>
#include <algorithm>

int main() {
    int sticks[6];

    for(int i = 0; i < 6; i++) {
        std::cin >> sticks[i];
    }

    std::sort(sticks, sticks+6);

    if(sticks[0] == sticks[3] || sticks[1] == sticks[4] || sticks[2] == sticks[5]) {
        if(sticks[0] == sticks[3] && sticks[1] == sticks[4] && sticks[2] == sticks[5]) {
            std::cout << "Elephant" << std::endl;
        } else if((sticks[0] == sticks[3] && sticks[1] == sticks[4]) || (sticks[1] == sticks[4] && sticks[2] == sticks[5])) {
            std::cout << "Bear" << std::endl;
        } else {
            std::cout << "Alien" << std::endl;
        }
    } else {
        std::cout << "Alien" << std::endl;
    }

    return 0;
}