#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int minRemoved = n - 1;
    for (int i = 0; i < n; i++) {
        int currentGcd = arr[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                currentGcd = gcd(currentGcd, arr[j]);
            }
        }
        if (currentGcd > 1) {
            minRemoved = std::min(minRemoved, 1);
        }
    }

    if (minRemoved == n - 1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << minRemoved << std::endl;
    }

    return 0;
}