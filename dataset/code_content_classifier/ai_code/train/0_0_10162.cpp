#include <iostream>
#include <string>

int countIntegersWithEqualFirstAndLastDigit(long long l, long long r) {
    int count = 0;
    for (long long i = l; i <= r; i++) {
        std::string numStr = std::to_string(i);
        if (numStr[0] == numStr[numStr.length() - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    long long l, r;
    std::cin >> l >> r;
    
    int result = countIntegersWithEqualFirstAndLastDigit(l, r);
    std::cout << result << std::endl;
    
    return 0;
}