#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n * n);
    for (int i = 0; i < n * n; i++) {
        std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());

    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }

    s /= n;

    std::cout << s << std::endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i * n + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}