#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int count = 0;
    bool found = false;

    int prev1, prev2, current1, current2;
    std::cin >> prev1 >> prev2;

    for (int i = 1; i < N; i++) {
        std::cin >> current1 >> current2;
        if (prev1 == prev2 && current1 == current2 && prev2 == current1) {
            count++;
            if (count >= 2) {
                found = true;
                break;
            }
        } else {
            count = 0;
        }
        prev1 = current1;
        prev2 = current2;
    }

    if (found) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}