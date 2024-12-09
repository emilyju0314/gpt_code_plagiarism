#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    std::sort(s.begin(), s.end());

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        a[i] = i % 2 == 0 ? s[i] / 2 : (s[i] + 1) / 2;
        b[i] = s[i] - a[i];
    }

    std::cout << "YES" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}