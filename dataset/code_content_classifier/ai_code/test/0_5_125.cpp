#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n, 0);
    
    int remaining_zero = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            remaining_zero++;
            b[i] = remaining_zero;
        } else {
            b[i] = a[i];
            remaining_zero = 0;
        }
    }

    remaining_zero = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (b[i] == 0) {
            remaining_zero++;
            b[i] = std::min(remaining_zero, a[i]);
        } else {
            remaining_zero = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}