#include <iostream>

int main() {
    long long n;
    std::cin >> n;

    int bonusCount = 0;
    for(int i = 1; i <= n; i++) {
        bool isDivisible = false;
        for(int j = 2; j <= 10; j++) {
            if(i % j == 0) {
                isDivisible = true;
                break;
            }
        }
        if(!isDivisible) {
            bonusCount++;
        }
    }

    std::cout << bonusCount << std::endl;

    return 0;
}