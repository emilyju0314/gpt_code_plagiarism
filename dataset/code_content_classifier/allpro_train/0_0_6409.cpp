#include <iostream>
#include <string>

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    std::string n;
    std::cin >> n;

    if (n.length() == 1) {
        std::cout << 0 << std::endl;
    } else {
        int count = 1;
        int num = std::stoi(n);

        while (num >= 10) {
            num = sumOfDigits(num);
            count++;
        }
        std::cout << count << std::endl;
    }

    return 0;
}