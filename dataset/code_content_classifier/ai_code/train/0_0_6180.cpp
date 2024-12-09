#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    long long joy = 0;
    for (int i = 0; i < n; i++) {
        int xi = std::min(a[i], b[i] / 2);
        int yi = std::min(b[i] - xi, a[i]);

        joy += xi * yi;
    }

    std::cout << joy << std::endl;

    return 0;
}