#include <iostream>
#include <string>

int main() {
    int a, b;
    std::cin >> a >> b;

    int c = a + b;

    std::string a_str = std::to_string(a);
    std::string b_str = std::to_string(b);
    std::string c_str = std::to_string(c);

    std::string a_no_zeros = "", b_no_zeros = "", c_no_zeros = "";

    for (char digit : a_str) {
        if (digit != '0') {
            a_no_zeros += digit;
        }
    }

    for (char digit : b_str) {
        if (digit != '0') {
            b_no_zeros += digit;
        }
    }

    for (char digit : c_str) {
        if (digit != '0') {
            c_no_zeros += digit;
        }
    }

    int a_no_zeros_int = std::stoi(a_no_zeros);
    int b_no_zeros_int = std::stoi(b_no_zeros);
    int c_no_zeros_int = std::stoi(c_no_zeros);

    if (a_no_zeros_int + b_no_zeros_int == c_no_zeros_int) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}