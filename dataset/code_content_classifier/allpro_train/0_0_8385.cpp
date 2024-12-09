#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b;
    for (int i = 0; i < n; i++) {
        b.push_back(a[i]);
        std::reverse(b.begin(), b.end());
    }

    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}