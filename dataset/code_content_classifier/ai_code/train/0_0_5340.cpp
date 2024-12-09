#include <iostream>
#include <string>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int k;
    std::cin >> k;

    int count = 0;
    int num = 0;

    while (count < k) {
        num++;
        if (sumOfDigits(num) == 10) {
            count++;
        }
    }

    std::cout << num << std::endl;

    return 0;
}