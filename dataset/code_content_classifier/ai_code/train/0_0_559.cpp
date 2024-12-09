#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::vector<int> p(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == n - 1) {
                p[i] = j + 1;
                found = true;
                break;
            }
        }
        if (!found) {
            p[i] = n;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }

    return 0;
}