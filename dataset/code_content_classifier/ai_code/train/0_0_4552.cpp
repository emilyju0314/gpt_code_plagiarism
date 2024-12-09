#include <iostream>
#include <algorithm>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long findSmallestSubmissions(long long x, long long y, long long p, long long q) {
    if (p == 0) {
        if (x == 0) {
            return 0;
        } else {
            return -1;
        }
    }

    long long submissions = (p - x + (p * q - 1)) / p;
    long long totalSubmissions = y + submissions;
    long long lcm = (y * q) / gcd(y, q);
    long long target = (lcm / q) * p;

    if (totalSubmissions * p == x * lcm + p * submissions) {
        return submissions;
    } else {
        return -1;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long x, y, p, q;
        std::cin >> x >> y >> p >> q;

        long long result = findSmallestSubmissions(x, y, p, q);
        std::cout << result << std::endl;
    }

    return 0;
}