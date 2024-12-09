#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        // Find x and y such that gcd(x, y) has c digits
        vector<int> gcd_digits(c, 1);
        for (int i = 1; i < c; i++) {
            gcd_digits[i] = 0;
        }
        int gcd_num = 1;
        for (int digit : gcd_digits) {
            gcd_num = gcd_num * 10 + digit;
        }

        // Find x and y such that x has a digits, y has b digits
        int x = 1, y = 1;
        for (int i = 1; i < a; i++) {
            x = x * 10 + 1;
        }
        for (int i = 1; i < b; i++) {
            y = y * 10 + 2;
        }

        cout << x << " " << y << endl;
    }

    return 0;
}