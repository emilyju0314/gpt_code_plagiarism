#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        long long x, y;
        cin >> x >> y; // Read values of x and y for current test case

        long long ans = 0;
        for (long long b = 2; b <= y; b++) {
            long long lower_bound = max((x + b - 1) / b, b); // Calculate lower bound for a
            long long upper_bound = min(x, y*b-1); // Calculate upper bound for a
            
            if (lower_bound <= upper_bound) {
                ans += upper_bound - lower_bound + 1;
            }
        }

        cout << ans << endl; // Output the number of special pairs for current test case
    }

    return 0;
}