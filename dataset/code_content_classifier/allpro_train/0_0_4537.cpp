#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int next_prime(int n) {
    n++;
    while (!is_prime(n)) {
        n++;
    }
    return n;
}

int previous_prime(int n) {
    n--;
    while (!is_prime(n)) {
        n--;
    }
    return n;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        int largest_prime = previous_prime(n);
        int smallest_prime = next_prime(n);
        
        int numerator = largest_prime * smallest_prime - (largest_prime - n) * (smallest_prime - n);
        int denominator = 2 * largest_prime * smallest_prime;
        
        int gcd_val = gcd(numerator, denominator);
        
        cout << numerator / gcd_val << "/" << denominator / gcd_val << endl;
    }
    
    return 0;
}