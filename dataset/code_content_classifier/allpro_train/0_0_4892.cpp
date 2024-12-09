#include <iostream>

int countYears(int a, int b) {
    int count = 0;
    for (int i = a; i <= b; i++) {
        int num_zeros = 0;
        int n = i;
        while (n > 0) {
            if (n % 2 == 0) {
                num_zeros++;
            }
            n /= 2;
        }
        if (num_zeros == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << countYears(a, b) << std::endl;
    return 0;
}