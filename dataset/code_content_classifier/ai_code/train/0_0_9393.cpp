#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        std::cin >> permutation[i];
    }

    bool found = false;
    for (int i = 0; i < n-1 && !found; i++) {
        for (int j = i + 2; j < n; j++) {
            if ((double)permutation[i] / permutation[j] > permutation[i+1] && (double)permutation[i] / permutation[j] < permutation[j-1]) {
                found = true;
                break;
            }
        }
    }

    if (found) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}