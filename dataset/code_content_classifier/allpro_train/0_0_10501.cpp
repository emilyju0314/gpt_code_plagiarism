#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> k(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i];
    }

    vector<int> prefix_sum(n);
    prefix_sum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }

    int max_spoilage = 0;
    int idx = 0;
    for (int i = 0; i < m; i++) {
        while (idx < n && prefix_sum[idx] <= k[i]) {
            idx++;
        }

        if (idx == 0) {
            max_spoilage = k[i] * n - prefix_sum[n-1];
        } else {
            max_spoilage = max(max_spoilage, k[i] * (n-idx) + prefix_sum[idx-1] - k[i]);
        }

        cout << max_spoilage << " ";
    }

    cout << endl;

    return 0;
}