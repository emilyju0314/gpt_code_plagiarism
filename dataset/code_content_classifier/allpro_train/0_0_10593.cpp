#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> oats(n);
    for (int i = 0; i < n; i++) {
        std::cin >> oats[i];
    }

    std::vector<std::vector<int>> weightCapacity(n);
    for (int i = 0; i < n; i++) {
        weightCapacity[i].resize(n - i);
        for (int j = 0; j < n - i; j++) {
            std::cin >> weightCapacity[i][j];
        }
    }

    bool oatsFall = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (oats[i] >= weightCapacity[i][j]) {
                oats[i + 1] += oats[i] - weightCapacity[i][j];
                oatsFall = true;
            }
        }
    }

    if (oatsFall) {
        std::cout << "Cerealguy" << std::endl;
    } else {
        std::cout << "Fat Rat" << std::endl;
    }

    return 0;
}