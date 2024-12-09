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
    
    vector<pair<int, int>> good_pairs(m);
    for (int i = 0; i < m; i++) {
        cin >> good_pairs[i].first >> good_pairs[i].second;
    }
    
    int ans = 0;
    for (auto [ik, jk] : good_pairs) {
        for (int v = 2; v <= min(a[ik-1], a[jk-1]); v++) {
            if (a[ik-1] % v == 0 && a[jk-1] % v == 0) {
                ans++;
                a[ik-1] /= v;
                a[jk-1] /= v;
                v--;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}