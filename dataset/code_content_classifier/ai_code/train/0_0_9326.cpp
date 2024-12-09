#include <iostream>
#include <set>

int main() {
    long long n, k;
    std::cin >> n >> k;

    std::set<long long> remainders;
    for (long long i = 1; i <= k; ++i) {
        remainders.insert(n % i);
    }

    if (remainders.size() == k) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}