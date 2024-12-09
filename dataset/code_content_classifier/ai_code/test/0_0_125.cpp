#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int max_val = 1;
    for (int i = 0; i < n-1; i++) {
        if (a[i] == 0) {
            a[i] = max_val;
        }
        if (a[i] == a[i+1]) {
            max_val++;
            if (max_val > n) {
                max_val = 1;
            }
        }
    }

    if (a[n-1] == 0) {
        a[n-1] = max_val;
    }

    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}