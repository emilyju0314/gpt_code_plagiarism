#include <iostream>

int countNumbersWithSmallestDivisor(int a, int b, int k) {
    int count = 0;
    
    for (int i = a; i <= b; i++) {
        if (i % k == 0) {
            bool flag = true;
            for (int j = 2; j < k; j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int a, b, k;
    std::cin >> a >> b >> k;
    
    std::cout << countNumbersWithSmallestDivisor(a, b, k) << std::endl;
    
    return 0;
}