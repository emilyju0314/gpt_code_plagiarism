#include <iostream>
#include <string>

bool isLuckyNumber(int n) {
    while (n > 0) {
        if (n % 10 != 4 && n % 10 != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::string ticket;
    std::cin >> ticket;

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; i++) {
        sum1 += ticket[i] - '0';
    }
    for (int i = n / 2; i < n; i++) {
        sum2 += ticket[i] - '0';
    }

    if (isLuckyNumber(std::stoi(ticket)) && sum1 == sum2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}