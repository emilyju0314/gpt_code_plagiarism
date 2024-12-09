#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int steps = n;
        int count = 0;
        for (int i = 0; i < min(d, n); i++) {
            if (a[i] == 1) {
                steps = min(steps, count);
            }
            count++;
        }

        if (steps == n) {
            cout << "0" << endl;
        } else {
            cout << steps << endl;
        }
    }

    return 0;
}