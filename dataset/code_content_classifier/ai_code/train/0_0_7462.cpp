#include <iostream>

int countSetBits(long long n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        long long n;
        std::cin >> n;
        
        long long unfairness = countSetBits(n);
        std::cout << unfairness << std::endl;
    }

    return 0;
}