#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n, k;
        cin >> n >> k;

        if(n == 1) {
            cout << 0 << endl;
        } else if(k >= n) {
            cout << 1 << endl;
        } else {
            long long min_hours = 1;
            long long remaining_computers = n - k;

            min_hours += (remaining_computers + k - 2) / (k - 1);

            cout << min_hours << endl;
        }
    }

    return 0;
}