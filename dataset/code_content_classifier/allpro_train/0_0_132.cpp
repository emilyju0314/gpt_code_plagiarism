#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int count = 0;
    while (n > 0) {
        if (n % 10 == 0 || n % 10 == 4 || n % 10 == 6 || n % 10 == 9) {
            count++;
        } else if (n % 10 == 8) {
            count += 2;
        }
        n /= 10;
    }

    std::cout << count << std::endl;

    return 0;
}