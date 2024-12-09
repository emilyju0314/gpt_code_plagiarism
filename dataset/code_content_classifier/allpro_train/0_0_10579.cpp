#include <iostream>
#include <cmath>

int main() {
    int q;
    std::cin >> q;

    while (q--) {
        int n;
        std::cin >> n;

        int ans = 1;

        while (true) {
            int sum = 0;
            int temp = ans;

            while (temp > 0) {
                int power = pow(3, floor(log(temp) / log(3)));
                sum += power;
                temp -= power;
            }

            if (sum >= n) {
                std::cout << sum << std::endl;
                break;
            }

            ans++;
        }
    }

    return 0;
}