#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // Define a 2D vector to store lab numbers in each group
    std::vector<std::vector<int>> groups(n, std::vector<int>(n));

    // Fill the groups with lab numbers according to the required division
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            groups[i][j] = num++;
        }
    }

    // Print the groups
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << groups[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}