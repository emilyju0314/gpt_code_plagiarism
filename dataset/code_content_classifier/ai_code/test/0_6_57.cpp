#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        long long s, n, k;
        std::cin >> s >> n >> k;

        long long totalPens = s / n; // calculate total number of pens based on s and n

        // check if totalPens is divisible by k or if k is larger than s
        if(totalPens % k == 0 || k > s) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }

    return 0;
}