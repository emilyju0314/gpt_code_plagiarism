#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> possibleValues;

    for (int x = 1; x <= n; x++) {
        int sumOfDigits = 0;
        int temp = x;
        while (temp) {
            sumOfDigits += temp % 10;
            temp /= 10;
        }

        if (x + sumOfDigits == n) {
            possibleValues.push_back(x);
        }
    }

    std::cout << possibleValues.size() << std::endl;
    for (int value : possibleValues) {
        std::cout << value << std::endl;
    }

    return 0;
}