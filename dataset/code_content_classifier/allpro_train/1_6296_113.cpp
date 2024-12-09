#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
int INF = 2e18;
 
signed main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 1;
    for (int i = 1; i <= N; i++) ans = (ans * i) % mod;
    bool check = false;
    int temp = 0;
    for (int i = 0; i < 2 * N; i++) {
        if ((S[i] == 'B') == check) {
            if (temp == 0) {
                cout << 0 << endl;
                return 0;
            }
            ans = (ans * temp) % mod;
            --temp;
            check ^= 1;
        } else {
            ++temp;
            check ^= 1;
        }
    }
    if (temp) ans = 0;
    cout << ans << endl;
}
