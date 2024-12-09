#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;

    std::vector<double> heights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> heights[i];
    }

    std::vector<int> frequency(6, 0);

    for (int i = 0; i < n; i++) {
        if (heights[i] < 165.0) {
            frequency[0]++;
        } else if (heights[i] < 170.0) {
            frequency[1]++;
        } else if (heights[i] < 175.0) {
            frequency[2]++;
        } else if (heights[i] < 180.0) {
            frequency[3]++;
        } else if (heights[i] < 185.0) {
            frequency[4]++;
        } else {
            frequency[5]++;
        }
    }

    for (int i = 0; i < 6; i++) {
        std::cout << i + 1 << ":";
        if (frequency[i] > 0) {
            std::cout << std::string(frequency[i], '*');
        }
        std::cout << std::endl;
    }

    return 0;
}