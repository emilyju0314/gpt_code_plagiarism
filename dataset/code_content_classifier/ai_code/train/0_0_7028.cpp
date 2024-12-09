#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        // Find the largest power of 2 less than n
        long long x = 1;
        while (x * 2 - 1 < n) {
            x *= 2;
        }

        // Calculate the value of x based on n
        cout << x << endl;
    }

    return 0;
}