#include <iostream>

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int a, b, k;
    std::cin >> a >> b >> k;

    int minL = -1;
    for (int l = 1; l <= b - a + 1; l++) {
        int count = 0;
        for (int x = a; x <= b - l + 1; x++) {
            for (int i = x; i < x + l; i++) {
                if (isPrime(i)) {
                    count++;
                    break;
                }
            }
        }
        if (count >= k) {
            minL = l;
            break;
        }
    }

    std::cout << minL << std::endl;

    return 0;
}