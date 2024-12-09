#include <iostream>
#include <vector>
#include <sstream>

int main() {
    std::vector<std::vector<int>> diamond;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::vector<int> row;
        std::istringstream ss(line);
        std::string token;
        while (std::getline(ss, token, ',')) {
            row.push_back(std::stoi(token));
        }
        diamond.push_back(row);
    }

    int n = diamond.size();

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < diamond[i].size(); j++) {
            diamond[i][j] += std::max(diamond[i + 1][j], diamond[i + 1][j + 1]);
        }
    }

    std::cout << diamond[0][0] << std::endl;

    return 0;
}