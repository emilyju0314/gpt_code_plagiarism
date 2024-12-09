#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1e5+10;

int n,k;
int x[MAX_N];

void solve(){
    vector<int> diff(n-1);
    for (int i=0;i<n-1;++i) diff[i]=x[i+1]-x[i];
    sort(diff.begin(),diff.end());
    int ans=0;
    for (int i=0;i<n-k;++i) ans+=diff[i];
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    for (;t--;){
        cin >> n >> k;
        for (int i=0;i<n;++i) cin >> x[i];
        solve();
    }
}
