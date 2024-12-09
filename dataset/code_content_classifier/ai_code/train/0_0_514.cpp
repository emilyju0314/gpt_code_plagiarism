#include <iostream>

int countDivisors(int num) {
    int count = 0;
    for(int i = 1; i <= num; i++) {
        if(num % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    int divisors = 0;
    for(int i = a; i <= b; i++) {
        if(c % i == 0) {
            divisors++;
        }
    }

    std::cout << divisors << std::endl;

    return 0;
}