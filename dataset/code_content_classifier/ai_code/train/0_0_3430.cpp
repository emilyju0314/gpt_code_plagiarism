#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int state = 0; // 0: increasing, 1: constant, 2: decreasing
    bool unimodal = true;

    // Check for increasing part
    int i = 1;
    while (i < n && a[i] > a[i-1]) {
        i++;
    }
    if (i < n && a[i] == a[i-1]) {
        state = 1;
        i++;
    }

    // Check for constant part
    while (i < n && a[i] == a[i-1]) {
        i++;
    }

    // Check for decreasing part
    while (i < n && a[i] < a[i-1]) {
        i++;
    }

    if (i < n) {
        unimodal = false;
    }

    if (unimodal) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}