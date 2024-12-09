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

        int ans = n; // Initialize answer to be the length of the array a

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        // Find the longest non-decreasing suffix of the array a
        int idx = n - 1;
        while (idx > 0 && a[idx-1] >= a[idx]) {
            idx--;
        }

        // Find the length of the shortest prefix to erase
        ans = idx;

        cout << ans << endl;
    }

    return 0;
}