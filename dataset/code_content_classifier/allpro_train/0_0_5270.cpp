#include <iostream>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int a, b;

    // Read input pairs until EOF
    while (std::cin >> a >> b) {
        int result = gcd(a, b);
        std::cout << result << std::endl;
    }

    return 0;
}