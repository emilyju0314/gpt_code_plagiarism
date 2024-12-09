#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long min_hours = 0;
        long long remaining_computers = n - 1;

        if (k >= n) {
            min_hours = 1;
        } else {
            long long max_possible_transfers = k * (k + 1) / 2;
            min_hours = max(1LL, (remaining_computers + max_possible_transfers - 1) / max_possible_transfers);
        }

        cout << min_hours << endl;
    }

    return 0;
}