#include <iostream>
#include <vector>

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

        int ans = 1;
        int prev_sum = a[0];
        int max_k = 1;

        for (int i = 1; i < n; i++) {
            if (prev_sum < a[i]) {
                ans++;
            } else {
                ans = 1;
            }
            max_k = max(max_k, ans);
            prev_sum = a[i];
        }

        cout << max_k << endl;
    }

    return 0;
}