#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        // Calculate the maximum sum of k odd numbers
        int maxSum = k * k;

        // Check if n can be represented as the sum of k distinct positive odd integers
        if(n >= maxSum && (n - maxSum) % 2 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}