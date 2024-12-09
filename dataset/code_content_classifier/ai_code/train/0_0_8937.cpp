#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefix_sum(n+1, 0);
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;

        vector<int> query_a = a;
        for (int j = 0; j < x; j++) {
            query_a[j] = n+1;
        }
        for (int j = n-1; j >= n-y; j--) {
            query_a[j] = n+1;
        }

        vector<int> cnt(n+2, 0);
        for (int j = 0; j < n; j++) {
            cnt[min(query_a[j], n+1)]++;
        }
        for (int j = 1; j <= n+1; j++) {
            cnt[j] += cnt[j-1];
        }

        int res = 0;
        for (int j = n; j >= 1; j--) {
            int cnt_j = cnt[j] - cnt[j-1];
            res = max(res, min(j, cnt_j));
        }

        cout << res << endl;
    }

    return 0;
}