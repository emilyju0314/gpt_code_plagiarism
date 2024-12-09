#include <iostream>
#include <string>

std::string baseNeg2(int N) {
    if (N == 0) {
        return "0";
    }
    
    std::string result = "";
    while (N != 0) {
        int remainder = N % 2;
        // If remainder is negative, add 2 to N and set the remainder to (remainder + 2).
        if (remainder < 0) {
            N = (N + 2) / -2;
            remainder = remainder + 2;
        } else {
            N = N / -2;
        }
        result = std::to_string(remainder) + result;
    }
    
    return result;
}

int main() {
    int N;
    std::cin >> N;
    
    std::string baseNeg2Rep = baseNeg2(N);
    std::cout << baseNeg2Rep << std::endl;
    
    return 0;
}