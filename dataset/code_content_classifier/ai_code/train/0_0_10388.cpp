#include <iostream>
#include <vector>
#include <string>

// Function to rotate the dice based on the given rotation direction
void rotate_dice(std::vector<std::vector<char>>& dice, char rotation) {
    if (rotation == 'N') {
        std::swap(dice[0][1], dice[1][1]);
        std::swap(dice[1][1], dice[2][1]);
        std::swap(dice[0][0], dice[2][2]);
    } else if (rotation == 'E') {
        std::swap(dice[0][2], dice[1][2]);
        std::swap(dice[1][2], dice[2][2]);
        std::swap(dice[0][0], dice[2][2]);
    } else if (rotation == 'W') {
        std::swap(dice[0][0], dice[1][0]);
        std::swap(dice[1][0], dice[2][0]);
        std::swap(dice[0][2], dice[2][2]);
    } else if (rotation == 'S') {
        std::swap(dice[0][1], dice[1][1]);
        std::swap(dice[1][1], dice[2][1]);
        std::swap(dice[1][0], dice[2][2]);
    }
}

// Function to check if the current dice configuration has at least one hole on the lower three squares on the front and back sides
bool check_holes(std::vector<std::vector<char>>& dice) {
    int front_holes = 0, back_holes = 0;
    for (int i = 0; i < 3; i++) {
        if (dice[0][i] == '*') front_holes++;
        if (dice[2][i] == '*') back_holes++;
    }
    return front_holes > 0 || back_holes > 0;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line[0] == '#') break;

        std::vector<std::vector<char>> dice(3, std::vector<char>(3));
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                std::getline(std::cin, line);
                for (int k = 0; k < 3; k++) {
                    dice[j][k] = line[k];
                }
            }

            // Try different rotations and check if there is a solution
            int rotations = 0;
            while (!check_holes(dice)) {
                rotate_dice(dice, 'N');
                rotations++;
                if (rotations == 4) {
                    break;
                }
            }

            std::cout << rotations << std::endl;
        }
        std::cin.ignore(); // Ignore the blank line between datasets
    }

    return 0;
}