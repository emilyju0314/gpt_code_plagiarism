#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> activeTeeth(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> activeTeeth[i];
    }

    bool isReal = true;
    for (int i = 1; i < n; ++i) {
        if ((activeTeeth[i] + i) % 2 != activeTeeth[0] % 2) {
            isReal = false;
            break;
        }
    }

    if (isReal) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}