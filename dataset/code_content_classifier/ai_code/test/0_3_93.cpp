#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate the maximum number of hours needed to copy update files to all computers
        long long max_hours = (2 * n + k - 1) / k;
        
        cout << max_hours << endl;
    }

    return 0;
}