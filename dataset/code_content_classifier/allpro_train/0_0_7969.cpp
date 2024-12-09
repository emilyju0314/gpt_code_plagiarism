#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> denominations(n);
    for(int i = 0; i < n; i++) {
        std::cin >> denominations[i];
    }

    std::set<int> validDigits;
    for(int d = 0; d < k; d++) {
        bool possible = true;
        for(int i = 0; i < n; i++) {
            if (denominations[i] % k != d && denominations[i] % k != 0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            validDigits.insert(d);
        }
    }

    std::cout << validDigits.size() << std::endl;
    for(int digit : validDigits) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;

    return 0;
}