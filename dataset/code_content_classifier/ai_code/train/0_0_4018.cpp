#include <iostream>
#include <vector>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }

    int max_beauty = 0;
    for (int i = 0; i < n; i++) {
        int diff = a[i] - g;
        if (diff % k == 0) {
            max_beauty = std::max(max_beauty, a[i] - diff);
        } else {
            max_beauty = std::max(max_beauty, a[i] - (diff - diff % k));
        }
    }

    std::cout << max_beauty << std::endl;

    return 0;
}