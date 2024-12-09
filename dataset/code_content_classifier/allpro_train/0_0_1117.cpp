#include <iostream>
#include <vector>
#include <string>

void displaySignal(int d) {
    std::vector<std::string> signals = {
        "0111111", // 0
        "0000110", // 1
        "1011011", // 2
        "1001111", // 3
        "1100110", // 4
        "1101101", // 5
        "1111101", // 6
        "0000111", // 7
        "1111111", // 8
        "1101111"  // 9
    };

    std::cout << signals[d] << std::endl;
}

int main() {
    int n;
    while (true) {
        std::cin >> n;

        if (n == -1) {
            break;
        }

        for (int i = 0; i < n; i++) {
            int d;
            std::cin >> d;
            displaySignal(d);
        }
    }

    return 0;
}