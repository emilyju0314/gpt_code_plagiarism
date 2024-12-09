#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool canMakeCube(std::vector<std::string>& dice) {
    // Check all possible combinations of dice to form a cube
    do {
        if(dice[0][0] == dice[1][1] && dice[0][3] == dice[1][4] &&
           dice[1][0] == dice[2][1] && dice[1][3] == dice[2][4] &&
           dice[2][0] == dice[3][1] && dice[2][3] == dice[3][4] &&
           dice[3][0] == dice[0][1] && dice[3][3] == dice[0][4] &&
           dice[4][0] == dice[5][1] && dice[4][3] == dice[5][4] &&
           dice[5][0] == dice[6][1] && dice[5][3] == dice[6][4] &&
           dice[6][0] == dice[7][1] && dice[6][3] == dice[7][4] &&
           dice[7][0] == dice[4][1] && dice[7][3] == dice[4][4]) {
            return true; // Cube can be formed
        }
    } while(std::next_permutation(dice.begin(), dice.end()));
    
    return false; // Cube cannot be formed
}

int main() {
    std::vector<std::string> dice(8);

    while(true) {
        for(int i = 0; i < 8; i++) {
            std::cin >> dice[i];
        }

        // Check if input is 0, exit if it is
        if(dice[0] == "0") {
            break;
        }

        // Check if cube can be formed and output result
        if(canMakeCube(dice)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}