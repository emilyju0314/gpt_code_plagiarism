#include <iostream>
#include <cmath>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int x, n, m;
        std::cin >> x >> n >> m;

        while(x > 0 && (n > 0 || m > 0)) {
            if(x <= 20) {
                break;
            }

            if(x / 2 + 10 < x) {
                x = x / 2 + 10;
                n--;
            } else {
                x -= 10;
                m--;
            }
        }

        if(x <= 0) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}