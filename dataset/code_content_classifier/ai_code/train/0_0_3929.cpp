#include <iostream>

int main() {
    int n, k;
    std::cin >> n >> k;

    if (n < k || (k == 1 && n > 1)) {
        std::cout << -1 << std::endl;
    } else {
        for (int i = 0; i < n - k + 2; i++) {
            std::cout << char('a' + i % k);
        }
        std::cout << std::endl;
    }

    return 0;
} 

//Input: 7 4
//Output: ababacd