#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    for(int i = 0; i < t; i++) {
        long long n;
        std::cin >> n;

        long long l, r;
        
        r = sqrt(2 * n);
        l = r * (r + 1) / 2 - n;

        if (l == 0) {
            l = r - 1;
        }

        std::cout << l << " " << r << std::endl;
    }

    return 0;
}