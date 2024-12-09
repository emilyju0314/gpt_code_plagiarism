#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += a[i];
    }

    long long prefixSum = 0;
    long long suffixSum = 0;
    bool answer = false;

    for (int i = 0; i < n - 1; i++) {
        prefixSum += a[i];
        suffixSum = totalSum - prefixSum;
        if (prefixSum == suffixSum) {
            answer = true;
            break;
        }
    }

    if (answer) {
        std::cout << "YES" << std::endl;
    } else {
        for (int i = 0; i < n - 1; i++) {
            if (prefixSum - a[i] == suffixSum) {
                answer = true;
                break;
            }
        }

        if (answer) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}