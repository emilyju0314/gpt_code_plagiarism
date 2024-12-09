#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, b, c;
    cin >> n >> k >> b >> c;

    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    sort(t.begin(), t.end());
    
    long long ans = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        long long tgt = t[i];
        long long res = 0;
        for(int j = 0; j < n; j++) {
            long long inc = 0;
            if(t[j] < tgt) {
                inc = (tgt - t[j]) * c;
            } else {
                inc = (t[j] - tgt) / 5 * b + (t[j] - tgt) % 5 * c;
            }
            res += inc;
        }

        for(int j = 0; j <= n - k; j++) {
            long long subres = 0;
            for(int u = 0; u < k; u++) {
                long long diff = t[j + u] - tgt;
                if(diff < 0) {
                    subres -= diff * c;
                } else {
                    subres += (diff / 5) * b + (diff % 5) * c;
                }
            }

            ans = min(ans, res - subres);
        }
    }

    cout << ans << endl;

    return 0;
}