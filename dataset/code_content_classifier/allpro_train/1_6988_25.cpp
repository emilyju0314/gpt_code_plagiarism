#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int n, a[N];
ll check(int x) {
    vector<int> v;
    ll s = 0;
    for(int i = 0; i < n; i++) {
        v.push_back(a[i] % x);
        s += v.back();
    }
    sort(v.begin(), v.end());
    int c = s/x;
    ll ret = 0;
    for(int i = int(v.size())-1; i >= 0 && c; i--) {
        ret += x-v[i];
        c--;
    }
    return ret;
}
int main() {
    ll k;
    cin >> n >> k;
    ll s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    ll ans = 1;
    for(ll i = 1; i*i <= s; i++) {
        if(s % i == 0 && check(i) <= k) ans = max(ans, i);
        if(s % i == 0 && check(s/i) <= k) ans = max(ans, s/i);
    }
    cout << ans << endl;
    return 0;
}