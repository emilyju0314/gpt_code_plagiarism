#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int test = 0; test < t; ++test) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        long long max_pos = 0, max_neg = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > 0) {
                max_pos = max(max_pos, max_neg + a[i]);
            } else {
                max_neg = max(max_neg, max_pos + a[i]);
            }
        }

        cout << max(max_pos, max_neg) << endl;
    }

    return 0;
}