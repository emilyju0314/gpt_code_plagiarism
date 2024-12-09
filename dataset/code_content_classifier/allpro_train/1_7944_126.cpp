#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
typedef long long LL;
LL a[N];
LL sum[N];
int main() {
    LL n, x, d;
    cin>>n>>x>>d;

    a[1] = x;
    for (int i=2; i<=n; i++) a[i] = a[i-1] + d;

    if ( d < 0) {
        reverse(a+1, a+n+1);
        x = a[1];
        d = -d;
    }

    if (d == 0) {
        if (x == 0) cout<<1<<endl;
        else        cout<<n+1<<endl;
        return 0;
    }

    for (int i=1; i<=n; i++)    sum[i] = sum[i-1] + a[i];
    LL m = 2*d;

    map<LL, vector<pair<LL, LL>>> mp;

    for (int i=0; i<=n; i++) {
        LL mn = 2*sum[i] - sum[n];
        LL mx = sum[n] - 2*sum[n-i];

        LL dd = (mn%m+m)%m;
        LL a = (mn-dd)/m;
        LL b = (mx-dd)/m;

        if (a > b)  swap(a, b);
        mp[dd].push_back({a,b});
    }

    LL ans = 0;
    for (auto pr: mp) {
        auto v = pr.second;
        sort(v.begin(), v.end());

        LL st = -1e18, cur = 0;
        for (auto pr: v) {
            if (pr.second < st) continue;
            cur += pr.second - max(pr.first, st)+1;
            st = pr.second+1;
        }
        ans += cur;
    }
    cout<<ans<<endl;
}
