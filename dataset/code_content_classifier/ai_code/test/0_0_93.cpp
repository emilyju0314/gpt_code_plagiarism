#include <iostream>

using namespace std;

long long minHours(long long n, long long k) {
    if (n <= k) {
        // It is possible to copy to all computers in one hour
        return 1;
    }

    long long time = (n + k - 1) / k; // Divide n by the number of patch cables, and round up
    return time;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        cout << minHours(n, k) << endl;
    }

    return 0;
}