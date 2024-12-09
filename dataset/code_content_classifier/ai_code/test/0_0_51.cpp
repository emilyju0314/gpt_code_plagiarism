#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        long long n;
        cin >> n; // Input integer n

        // Calculate sum (l + (l+1) + ... + (r-1) + r = n)
        long long sum = (n * (n+1)) / 2;

        // Find two integers l and r
        for (long long l = -1e18; l <= 1e18; l++) {
            long long r = l + n;
            long long current_sum = ((r*(r+1)) - (l*(l+1))) / 2;

            if (current_sum == n) {
                cout << l << " " << r << endl;
                break;
            }
        }
    }

    return 0;
}