#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Pick any two numbers, m and n, such that m < n and n - m is a multiple of 3
        // Let a = m, b = m + n, c = n
        // This way, a + b + c = 2m + n = n
        // Also, gcd(a, b) = m = c

        int m = 2; // pick any value for m here
        cout << m << " " << m + n << " " << n << endl;
    }

    return 0;
}