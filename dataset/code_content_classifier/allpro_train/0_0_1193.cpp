#include <iostream>
#include <cmath>

long long leapOverTrees(int n, int h) {
    if (h == 1) {
        return pow(2, n) - 1;
    } else if (h == n) {
        return 1;
    } else {
        return leapOverTrees(n - 1, h - 1) * leapOverTrees(n - 1, h - 1) + leapOverTrees(n - 1, h) * leapOverTrees(n - 2, h - 1);
    }
}

int main() {
    int n, h;
    std::cin >> n >> h;
    
    std::cout << leapOverTrees(n, h) << std::endl;
    
    return 0;
}