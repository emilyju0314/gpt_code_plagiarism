#include <iostream>
#include <vector>

int calculateKeyNumber(int n) {
    int keyNumber = 0;
    int factor = 2;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            keyNumber++;
            while (n % factor == 0) {
                n /= factor;
            }
            factor = i + 1;
        }
    }
    return keyNumber - 1;
}

int main() {
    int a, b;
    
    while (std::cin >> a >> b && (a != 0 && b != 0)) {
        int keyA = calculateKeyNumber(a);
        int keyB = calculateKeyNumber(b);
        
        if (keyA > keyB) {
            std::cout << "a" << std::endl;
        } else {
            std::cout << "b" << std::endl;
        }
    }
    
    return 0;
}