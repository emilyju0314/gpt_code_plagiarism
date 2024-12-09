#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<char> result(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int x = i + a[i];
        int y = i - a[i];

        if (x < n && (result[x] == 'B' || y >= 0 && result[y] == 'B')) {
            result[i] = 'A';
        } else {
            result[i] = 'B';
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << result[i];
    }

    return 0;
}