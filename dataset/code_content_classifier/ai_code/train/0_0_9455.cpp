#include <iostream>
#include <string>
#include <algorithm>

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    std::string sorted_s = s;
    std::sort(sorted_s.begin(), sorted_s.end());

    if (s == sorted_s) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        std::sort(s.begin(), s.end());
        std::cout << s << std::endl;
    }

    return 0;
}