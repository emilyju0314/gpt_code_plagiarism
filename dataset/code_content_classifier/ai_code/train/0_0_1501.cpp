#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long int count = 0;
        for (int i = 0; i < n; i++) {
            int left = lower_bound(a.begin() + i + 1, a.end(), l - a[i]) - a.begin();
            int right = upper_bound(a.begin() + i + 1, a.end(), r - a[i]) - a.begin();
            count += right - left;
        }

        cout << count << endl;
    }

    return 0;
}