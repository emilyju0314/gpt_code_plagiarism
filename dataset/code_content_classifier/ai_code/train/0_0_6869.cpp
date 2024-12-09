#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> calls(n);
    std::unordered_map<int, int> callCount;

    for (int i = 0; i < n; i++) {
        std::cin >> calls[i];
        if (calls[i] != 0) {
            callCount[calls[i]]++;
        }
    }

    int pairs = 0;
    for (int i = 0; i < n; i++) {
        if (calls[i] != 0 && callCount[calls[i]] >= 2) {
            pairs++;
        }
    }

    if (pairs % 2 == 0) {
        std::cout << pairs / 2 << std::endl;
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}