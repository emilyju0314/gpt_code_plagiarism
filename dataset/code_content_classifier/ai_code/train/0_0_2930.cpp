#include <iostream>
#include <vector>

// Function to check if a given 5x5 mesh represents a proper net of a die
bool checkProperNet(std::vector<std::vector<int>>& mesh) {
    int countZeros = 0;
    int counts[7] = {0};

    // Count the occurrences of each number and number of zeros
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            counts[mesh[i][j]]++;
            if (mesh[i][j] == 0) {
                countZeros++;
            }
        }
    }

    // Check for the conditions of a proper net
    if (countZeros == 9) {
        return true;
    }
    if (counts[0] != 9) {
        return false;
    }
    if (counts[1] != 1 || counts[2] != 1 || counts[3] != 1 ||
        counts[4] != 1 || counts[5] != 1 || counts[6] != 1) {
        return false;
    }
    if (mesh[0][0] + mesh[4][4] != 7 || mesh[0][4] + mesh[4][0] != 7 ||
        mesh[1][1] + mesh[3][3] != 7 || mesh[1][3] + mesh[3][1] != 7 || 
        mesh[2][2] != 1) {
        return false;
    }

    return true;
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::vector<std::vector<int>> mesh(5, std::vector<int>(5));
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                std::cin >> mesh[j][k];
            }
        }

        if (checkProperNet(mesh)) {
            std::cout << "true" << std::endl;
        } else {
            std::cout << "false" << std::endl;
        }
    }

    return 0;
}