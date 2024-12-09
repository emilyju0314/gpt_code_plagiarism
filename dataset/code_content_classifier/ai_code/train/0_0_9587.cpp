#include <iostream>
#include <vector>

bool checkIfSolvable(std::vector<int> cube) {
    int colors[6] = {0};

    for(int i = 0; i < 24; i++) {
        colors[cube[i] - 1]++;
    }

    for(int i = 0; i < 6; i++) {
        if(colors[i] == 4) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<int> cube(24);

    for(int i = 0; i < 24; i++) {
        std::cin >> cube[i];
    }

    if(checkIfSolvable(cube)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}