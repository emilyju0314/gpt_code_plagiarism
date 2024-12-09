#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }

    int stairs = 0;
    std::vector<int> steps;

    for (int i = 0; i < n; i++) {
        if (numbers[i] == 1) {
            stairs++;
            steps.push_back(numbers[i + 1]); // the next number will be the number of steps in the current stairway
        }
    }

    std::cout << stairs << std::endl;
    for (int i = 0; i < steps.size(); i++) {
        std::cout << steps[i] << " ";
    }

    return 0;
}