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

        int max_val = a[0];
        int min_val = a[n-1];
        int sharp_idx = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] >= i) {
                max_val = min(max_val, a[i] - i);
            }
            if (a[n-1-i] >= i) {
                min_val = min(min_val, a[n-1-i] - i);
            }
        }

        if (max_val >= min_val) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}