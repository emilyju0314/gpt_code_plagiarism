#include <iostream>
#include <cmath>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void calculateRatio(int h, int w) {
    int total = h * w;
    int red, blue;
    
    if (total % 2 == 0) {
        red = blue = total / 2;
    } else {
        red = total / 2 + 1;
        blue = total / 2;
    }
    
    int common = gcd(red, blue);
    red /= common;
    blue /= common;
    
    std::cout << red << " " << blue << std::endl;
}

int main() {
    int T;
    std::cin >> T;
    
    for (int i = 0; i < T; i++) {
        int h, w;
        std::cin >> h >> w;
        calculateRatio(h, w);
    }
    
    return 0;
}