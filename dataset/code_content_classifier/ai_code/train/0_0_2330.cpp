#include <iostream>

int main() {
    int n, a, b;

    while (true) {
        std::cin >> n >> a >> b;
        
        if (n == 0 && a == 0 && b == 0) {
            break;
        }

        int count = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (i * a + j * b == n) {
                    count++;
                    break;
                }
            }
        }

        std::cout << n - count << std::endl;
    }

    return 0;
}