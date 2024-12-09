#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(1 << n);
    std::vector<int> b(1 << n);
    
    for (int i = 0; i < (1 << n); ++i) {
        char c;
        std::cin >> c;
        a[i] = c - '0';
    }

    for (int i = 0; i < (1 << n); ++i) {
        char c;
        std::cin >> c;
        b[i] = c - '0';
    }

    std::vector<int> c(1 << n);

    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            if ((i | j) == i && (i & j) == 0) {
                c[i] += a[j] * b[j];
            }
        }
        std::cout << c[i] % 4;
    }

    return 0;
}