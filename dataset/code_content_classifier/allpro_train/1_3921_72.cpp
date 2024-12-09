#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int miner[n], mine[n];
    for(int i=0, k1=0, k2=0;i<2*n;i++) {
        int x, y;
        cin >> x >> y;
        if(x==0) {
            miner[k1] = y;
            if(miner[k1]<0)  miner[k1] = -miner[k1];
            k1++;
        }
        if(y==0) {
            mine[k2] = x;
            if(mine[k2]<0)   mine[k2] = -mine[k2];
            k2++;
        }
    }
    sort(mine, mine+n);
    sort(miner, miner+n);
    double ans = 0.;
    for(int i=0;i<n;i++) {
        ans += sqrt((long long)mine[i]*mine[i]+(long long)miner[i]*miner[i]);
    }
    cout << fixed << setprecision(20) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}