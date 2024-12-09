#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> c(n);
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        long long curr_max = 0;
        long long prev_max = 0;
        long long total_sum = 0;

        for (int i = 1; i < n; i++) {
            if (a[i] == b[i]) {
                curr_max = c[i] + 2;
            } else {
                curr_max = max(prev_max - a[i] + b[i] + c[i] + 2, (long long) c[i] + 2);
            }
            total_sum = max(total_sum, curr_max);
            prev_max = curr_max;
        }

        cout << total_sum << endl;
    }

    return 0;
}