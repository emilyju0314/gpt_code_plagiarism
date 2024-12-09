#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // finding a, b, and c such that a + b + c = n and gcd(a, b) = c
        int a = 1, b = 1, c = n - 2;
        
        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}