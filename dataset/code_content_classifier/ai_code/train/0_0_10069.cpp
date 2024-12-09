#include <iostream>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int x;
        std::cin >> x;

        int sum = 0, jump = 1;
        while(sum < x || (sum - x) % 2 != 0) {
            sum += jump;
            jump++;
        }

        std::cout << jump - 1 << std::endl;
    }

    return 0;
}