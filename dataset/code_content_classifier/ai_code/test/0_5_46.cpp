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

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int ans = -1;
        for (int i = 1; i <= n; i++) {
            vector<int> left, right;
            int x = a[n-1];

            bool sorted = true;

            for (int j = 0; j < n-1; j++) {
                if (a[j] <= x) {
                    left.push_back(a[j]);
                    if (j > 0 && a[j] < a[j-1]) sorted = false;
                } else {
                    right.push_back(a[j]);
                    if (j > 0 && a[j] < a[j-1]) sorted = false;
                }
            }

            reverse(right.begin(), right.end());
            left.push_back(x);

            a.clear();
            a.insert(a.end(), left.begin(), left.end());
            a.insert(a.end(), right.begin(), right.end());

            if (sorted) {
                ans = i;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}