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

        int cnt = 1;
        int prev_max = a[n - 1];
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < prev_max) {
                prev_max = a[i];
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}