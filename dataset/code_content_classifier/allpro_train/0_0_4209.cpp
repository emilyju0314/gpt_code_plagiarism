#include <iostream>
#include <vector>
#include <algorithm>

long long kthSmallestDivisor(long long n, long long k) {
    std::vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }
    std::sort(divisors.begin(), divisors.end());
    
    if (divisors.size() < k) {
        return -1;
    } else {
        return divisors[k-1];
    }
}

int main() {
    long long n, k;
    std::cin >> n >> k;
    
    std::cout << kthSmallestDivisor(n, k) << std::endl;
    
    return 0;
}