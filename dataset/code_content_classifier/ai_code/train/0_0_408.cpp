#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s;
    std::cin >> s;

    int count_a = std::count(s.begin(), s.end(), 'a');
    int count_b = std::count(s.begin(), s.end(), 'b');
    int count_c = std::count(s.begin(), s.end(), 'c');

    if ((count_a == 0 && count_b == 0 && count_c > 1) ||
        (count_a == 0 && count_c == 0 && count_b > 1) ||
        (count_b == 0 && count_c == 0 && count_a > 1) ||
        (std::abs(count_a - count_b) <= 1 && std::abs(count_b - count_c) <= 1 && std::abs(count_c - count_a) <= 1))
    {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}