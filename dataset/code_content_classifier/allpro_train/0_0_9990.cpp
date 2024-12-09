#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::sort(sequence.begin(), sequence.end());

    int minVal = sequence[0];
    int secondOrder = -101;

    for (int i = 0; i < n; i++) {
        if (sequence[i] > minVal) {
            secondOrder = sequence[i];
            break;
        }
    }

    if (secondOrder == -101) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << secondOrder << std::endl;
    }

    return 0;
}