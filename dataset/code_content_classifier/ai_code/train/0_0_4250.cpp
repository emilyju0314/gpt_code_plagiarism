#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int k = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] == 1 && a[i + 1] == 1 && a[i] == 0) {
            a[i + 1] = 0;
            ++k;
        }
    }

    std::cout << k << std::endl;

    return 0;
}