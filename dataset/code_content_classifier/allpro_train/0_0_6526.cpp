#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> destinations(n);
    for (int i = 0; i < n; i++) {
        std::cin >> destinations[i];
    }

    std::sort(destinations.begin(), destinations.end());

    long long total_distance = 0;
    for (int i = 0; i < n; i++) {
        total_distance += (long long)destinations[i] * i - (long long)destinations[i] * (n - i - 1);
    }

    long long gcd = std::__gcd(total_distance, (long long)n);
    
    std::cout << total_distance/gcd << " " << n/gcd << std::endl;

    return 0;
}