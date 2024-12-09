#include <iostream>
#include <vector>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> possibleValues;

    for (int x = 1; x <= n; x++) {
        if (x + sumOfDigits(x) == n) {
            possibleValues.push_back(x);
        }
    }

    std::cout << possibleValues.size() << std::endl;
    for (int value : possibleValues) {
        std::cout << value << std::endl;
    }

    return 0;
}