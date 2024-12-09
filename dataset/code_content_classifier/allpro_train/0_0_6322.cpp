#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<int> remainingKeyboards;
    for (int i = 0; i < n; ++i) {
        int idx;
        std::cin >> idx;
        remainingKeyboards.insert(idx);
    }

    int minStolenKeyboards = 0;
    for (int idx : remainingKeyboards) {
        if (remainingKeyboards.count(idx - 1) == 0) {
            ++minStolenKeyboards;
        }
    }

    std::cout << minStolenKeyboards << std::endl;

    return 0;
}