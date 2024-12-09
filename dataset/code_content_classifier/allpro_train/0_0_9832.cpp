#include <iostream>
#include <vector>

int main() {
    int n, A;
    std::cin >> n >> A;

    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = A - d[i] + 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " ";
    }

    return 0;
}