#include <iostream>
#include <vector>
#include <algorithm>

bool isValid(const std::vector<int>& puzzle) {
    int moduic = puzzle[9];
    if ((puzzle[0] + puzzle[1] + puzzle[2]) % moduic != 0) return false;
    if ((puzzle[3] + puzzle[4] + puzzle[5]) % moduic != 0) return false;
    if ((puzzle[6] + puzzle[7] + puzzle[8]) % moduic != 0) return false;
    if ((puzzle[0] + puzzle[3] + puzzle[6]) % moduic != 0) return false;
    if ((puzzle[1] + puzzle[4] + puzzle[7]) % moduic != 0) return false;
    if ((puzzle[2] + puzzle[5] + puzzle[8]) % moduic != 0) return false;
    if ((puzzle[0] + puzzle[4] + puzzle[8]) % moduic != 0) return false;
    if ((puzzle[2] + puzzle[4] + puzzle[6]) % moduic != 0) return false;
    return true;
}

int countSolutions(std::vector<int>& puzzle) {
    int count = 0;
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    do {
        std::vector<int> current = puzzle;
        for (int i = 0; i < 10; i++) {
            if (current[i] == 0) {
                current[i] = nums[i];
            }
        }
        if (isValid(current)) {
            count++;
        }
    } while(std::next_permutation(nums.begin(), nums.end()));
    return count;
}

int main() {
    std::vector<int> puzzle(10);
    while (true) {
        for (int i = 0; i < 10; i++) {
            std::cin >> puzzle[i];
        }
        if (puzzle[0] == -1) {
            break;
        }
        int solutions = countSolutions(puzzle);
        std::cout << solutions << std::endl;
    }
    return 0;
}