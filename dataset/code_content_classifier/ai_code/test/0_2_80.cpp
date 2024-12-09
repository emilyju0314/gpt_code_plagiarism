#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());

        long long total_inversions = 0;
        for (int i = 0; i < m; i++) {
            int left = 0, right = n - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (a[mid] <= b[i]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            total_inversions += n - left;
        }

        cout << total_inversions << endl;
    }

    return 0;
}