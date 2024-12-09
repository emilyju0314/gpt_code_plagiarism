#include <iostream>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;
    
    int a = (n-1) / 2;
    int b = (n+1) / 2;
    
    while (gcd(a, b) != 1) {
        a--;
        b++;
    }
    
    std::cout << a << " " << b << std::endl;
    
    return 0;
}