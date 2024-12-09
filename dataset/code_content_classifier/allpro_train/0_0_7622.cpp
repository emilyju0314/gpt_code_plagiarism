#include <iostream>
#include <cmath>

int main() {
    int n, q;
    std::cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        
        long long result;
        if ((x + y) % 2 == 0) {
            result = 1LL * ((x - 1) / 2) * n + (y + 1) / 2;
        } else {
            result = 1LL * (n * n + 1) / 2 + (x / 2) * n + (y + 1) / 2;
        }
        
        std::cout << result << std::endl;
    }

    return 0;
}