#include <iostream>
#include <string>
#include <set>

bool hasDistinctDigits(int x) {
    std::set<int> digits;
    while(x > 0) {
        int digit = x % 10;
        if(digits.count(digit) > 0) {
            return false;
        }
        digits.insert(digit);
        x /= 10;
    }
    return true;
}

int main() {
    int l, r;
    std::cin >> l >> r;

    for(int x = l; x <= r; x++) {
        if(hasDistinctDigits(x)) {
            std::cout << x << std::endl;
            return 0;
        }
    }

    std::cout << -1 << std::endl;

    return 0;
}