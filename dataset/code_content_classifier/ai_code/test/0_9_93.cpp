#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k >= n) {
            cout << "1" << endl;
        } else {
            long long min_hours;
            long long full_rounds = k - 1;
            long long remaining_computers = n - k;
            long long extra_hours = (remaining_computers + k - 2) / (k - 1);

            min_hours = full_rounds + extra_hours + 1;

            cout << min_hours << endl;
        }
    }

    return 0;
}