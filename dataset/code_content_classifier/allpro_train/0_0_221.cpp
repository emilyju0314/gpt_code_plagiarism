#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> log(n);
    for (int i = 0; i < n; i++) {
        std::cin >> log[i];
    }

    int currentWinner = 0; // 0 represents Alex, 1 represents Bob, 2 represents Carl
    for (int i = 0; i < n; i++) {
        if (log[i] == currentWinner + 1) {
            currentWinner = (currentWinner + 1) % 3;
        } else {
            break;
        }
    }

    if (currentWinner == 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}