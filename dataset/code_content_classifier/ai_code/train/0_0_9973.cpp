#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::string letters;
    std::cin >> n >> letters;

    int count_zero = std::count(letters.begin(), letters.end(), 'z');
    int count_one = (n - count_zero) / 3;

    for (int i = 0; i < count_one; i++) {
        std::cout << "1 ";
    }
    for (int i = 0; i < count_zero; i++) {
        std::cout << "0 ";
    }

    return 0;
}