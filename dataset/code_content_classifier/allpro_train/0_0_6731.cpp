#include <iostream>
#include <cmath>

int countOddDigits(int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        int numDigits = floor(log10(i)) + 1;
        if (numDigits % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int N;
    std::cin >> N;
    
    int result = countOddDigits(N);
    
    std::cout << result << std::endl;
    
    return 0;
}