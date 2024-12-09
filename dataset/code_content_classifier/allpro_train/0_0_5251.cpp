#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> bombs;
    bombs.push_back(2); // First bomb at cell 2

    for (int i = 1; i <= n; i++) {
        bombs.push_back(i);
    }

    bombs.push_back(2); // Last bomb at cell 2

    std::cout << bombs.size() << std::endl;
    for (int bomb : bombs) {
        std::cout << bomb << " ";
    }
    std::cout << std::endl;

    return 0;
}