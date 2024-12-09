#include <iostream>
#include <string>
#include <algorithm>

bool isLuckyNumber(const std::string &num) {
    for(char c : num) {
        if(c != '4' && c != '7') {
            return false;
        }
    }
    return true;
}

bool isSuperLuckyNumber(const std::string &num) {
    int count4 = std::count(num.begin(), num.end(), '4');
    int count7 = std::count(num.begin(), num.end(), '7');
    return count4 == count7;
}

int main() {
    std::string n;
    std::cin >> n;

    while(true) {
        if(isLuckyNumber(n) && isSuperLuckyNumber(n)) {
            std::cout << n << std::endl;
            break;
        }
        std::next_permutation(n.begin(), n.end());
    }

    return 0;
}