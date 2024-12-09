#include <iostream>
#include <vector>

#define MOD 1000000007

// Function to calculate GCD of two numbers
int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int prettinessValue = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prettinessValue += gcd(a[i], a[j]) * gcd(i+1, j+1);
            prettinessValue %= MOD;
        }
    }

    std::cout << prettinessValue << std::endl;

    return 0;
}