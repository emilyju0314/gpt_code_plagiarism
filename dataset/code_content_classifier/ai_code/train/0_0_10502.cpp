#include <iostream>
#include <algorithm>

long long wait_time(long long p, long long a, long long b, long long c) {
    long long first_arrival = a - p % a;
    long long second_arrival = b - p % b;
    long long third_arrival = c - p % c;
    return std::min({first_arrival, second_arrival, third_arrival});
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long p, a, b, c;
        std::cin >> p >> a >> b >> c;

        std::cout << wait_time(p, a, b, c) << std::endl;
    }

    return 0;
}