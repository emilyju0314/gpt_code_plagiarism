#include <iostream>
#include <vector>
#include <cmath>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int count_triangles(int T) {
    int count = 0;
    for (int a = 2; a <= T/3; a++) {
        for (int b = a; b <= (T-a)/2; b++) {
            int c = T - a - b;
            if (is_prime(a) && is_prime(b) && is_prime(c)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    while (std::cin >> T && T != 0) {
        int result = count_triangles(T);
        std::cout << result << std::endl;
    }
    return 0;
}