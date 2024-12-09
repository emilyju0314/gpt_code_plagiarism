#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int a, b, c;
        std::cin >> a >> b >> c;

        int max_visitors = 0;
        for(int i = 0; i <= a; i++) {
            for(int j = 0; j <= b; j++) {
                for(int k = 0; k <= c; k++) {
                    if (i + j + k <= a + b + c - std::max({a,b,c})) {
                        max_visitors = std::max(max_visitors, i + j + k);
                    }
                }
            }
        }

        std::cout << max_visitors << std::endl;
    }

    return 0;
}