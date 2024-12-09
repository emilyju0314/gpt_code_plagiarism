#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int A;
    std::cin >> A;

    int sum = 0;
    for (int base = 2; base < A; base++) {
        int num = A;
        int digitSum = 0;
        while (num > 0) {
            digitSum += num % base;
            num /= base;
        }
        sum += digitSum;
    }

    int numBases = A - 2;
    int gcdValue = gcd(sum, numBases);
    
    std::cout << sum / gcdValue << "/" << numBases / gcdValue << std::endl;

    return 0;
}