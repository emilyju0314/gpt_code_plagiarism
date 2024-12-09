#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, t, r;
    cin >> m >> t >> r;

    vector<int> w(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
    }

    vector<int> candlesLit(301, 0);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int cnt = 0;
        for (int j = w[i]; cnt < r; j--) {
            if (candlesLit[j] < r) {
                for (int k = min(j + t, 301); k > j; k--) {
                    candlesLit[k]++;
                }
                cnt++;
                ans++;
            }
        }
        if (cnt < r) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}