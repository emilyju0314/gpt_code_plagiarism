#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            a[i] = b[i];
        } else {
            a[i] = b[i - 1] + a[i - 1];
        }
    }

    if (a[n - 1] == b[n - 1]) {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO\n";
    }

    return 0;
}