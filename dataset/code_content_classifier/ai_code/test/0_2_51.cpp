#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while(t--) {
        long long n;
        cin >> n; // Read the value of n for each test case

        // Find the sum from l to r using the formula: sum = (r*(r+1))/2 - (l*(l-1))/2
        // This sum equals to n
        // Solve this quadratic equation: r^2 + r - 2n = 0 to find the value of r
        // Calculate l using l = r - n
        
        long long r = (sqrt(1 + 8 * n) - 1) / 2;
        long long l = r - n;

        cout << l << " " << r << endl; // Output the values of l and r
    }

    return 0;
}