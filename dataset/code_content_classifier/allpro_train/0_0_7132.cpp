#include <iostream>
#include <string>

int main() {
    std::string balance;
    std::cin >> balance;

    if (balance[0] != '-') {
        std::cout << balance;
    } else {
        if (balance[balance.size() - 1] >= balance[balance.size() - 2]) {
            balance = balance.substr(0, balance.size() - 1);
        } else {
            balance = balance.substr(0, balance.size() - 2) + balance[balance.size() - 1];
        }
        // if after removing the digit the resulting balance is 0, output 0
        if (balance == "-0") {
            std::cout << 0;
        } else {
            std::cout << balance;
        }
    }

    return 0;
}