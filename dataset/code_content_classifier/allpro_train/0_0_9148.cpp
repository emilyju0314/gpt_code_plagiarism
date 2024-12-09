#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int count = 0;
    for(int i = 1; i <= n / 2; i++) {
        if ((i + n - i) % 10 == 9) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}