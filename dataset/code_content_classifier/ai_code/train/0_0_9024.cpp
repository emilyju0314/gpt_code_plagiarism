#include <iostream>
#include <cmath>

using namespace std;

bool isPowerOfTwo(int n) {
    return (n & (n - 1)) == 0;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

string winner(int n) {
    if (n == 1) return "FastestFinger";
    if (n == 2) return "Ashishgup";
    
    if (n % 2 == 1) return "Ashishgup";
    if (n % 2 == 0 && n != 2) {
        if ((n & (n - 1)) == 0) return "FastestFinger";
        if (n % 4 == 0) return "Ashishgup";
        if (isPrime(n / 2)) return "FastestFinger";
        return "Ashishgup";
    }
    return "FastestFinger";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        cout << winner(n) << endl;
    }
    
    return 0;
}