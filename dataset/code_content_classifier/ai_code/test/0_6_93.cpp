#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n, k;
        cin >> n >> k;

        // If there are enough patch cables to connect all computers at the same time
        if(n <= k) {
            cout << 1 << endl;
        } else {
            // Time taken to copy files to one computer
            long long time_to_copy = n-1;

            // Time taken to copy files to all computers if there is only one patch cable
            long long min_time = time_to_copy + (k-1);

            // The answer would be ceil(min_time/n)
            cout << (min_time + n - 1) / n << endl;
        }
    }

    return 0;
}