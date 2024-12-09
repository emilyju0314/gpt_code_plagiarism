#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            long long sum = m * a[i] + m * a[j];
            long long min_val = a[i];
            for (int k = i + 1; k <= j; k++) {
                min_val = min(min_val, (long long)a[k]);
            }
                
            ans = max(ans, sum - (m - 1) * min_val);
        }
    }

    cout << ans << endl;

    return 0;
}