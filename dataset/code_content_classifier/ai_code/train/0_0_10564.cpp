#include <iostream>
#include <vector>
#include <algorithm>

bool isTankaNumber(long long n) {
    std::string num = std::to_string(n);
    std::sort(num.begin(), num.end());
    return num == "557";
}

long long findNthTankaNumber(long long N) {
    long long num = 10;
    while (N > 0) {
        if (isTankaNumber(num)) {
            N--;
        }
        num++;
    }
    return num-1;
}

int main() {
    long long N;
    while (std::cin >> N) {
        if (N == 0) {
            break;
        }
        std::cout << findNthTankaNumber(N) << std::endl;
    }
    return 0;
}