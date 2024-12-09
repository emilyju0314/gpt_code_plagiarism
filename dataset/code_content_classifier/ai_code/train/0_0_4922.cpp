#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n) {
        if (n == 0) {
            break;
        }

        std::vector<int> b(n*(n+1)/2);
        for (int i = 0; i < n*(n+1)/2; ++i) {
            std::cin >> b[i];
        }

        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                a.push_back(b[i*n + j] / 2);
            }
        }

        std::sort(a.begin(), a.end());

        int a0 = a[0];
        std::cout << a0 << std::endl;

        for (int i = 1; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}