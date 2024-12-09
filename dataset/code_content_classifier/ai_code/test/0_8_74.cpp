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
    for (int i = 1; i < n; i++) {
        a[i] = b[i-1];
    }
    
    a[0] = (b[0] + b[1] - a[1]) / 2;

    for (int i = 1; i < n; i++) {
        if (a[i-1] + a[i] == b[i]) {
            continue;
        } else {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}