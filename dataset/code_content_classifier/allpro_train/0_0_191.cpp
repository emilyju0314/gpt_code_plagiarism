#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;

    std::vector<int> sumDivisors(10000001, 1);
    for (int i = 2; i < 10000001; i++) {
        for (int j = i; j < 10000001; j += i) {
            sumDivisors[j] += i;
        }
    }

    for (int i = 0; i < t; i++) {
        int c;
        std::cin >> c;
        
        int ans = -1;
        if (c < 10000001 && sumDivisors[c] == c) {
            ans = c;
        }
        
        std::cout << ans << std::endl;
    }

    return 0;
}