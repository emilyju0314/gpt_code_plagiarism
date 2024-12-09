#include <iostream>

int main() {
    long long l, r;
    std::cin >> l >> r;

    int count = 0;
    for(long long i = l; i <= r; i++) {
        if(i % 10 == i / 100) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}