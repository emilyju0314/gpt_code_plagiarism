#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pi;
#define MOD 1000000007LL

int t, n;

int main() {
    //freopen("feast.in", "r", stdin);
    //freopen("feast.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    cin >> t;
    while (t--) {
        cin >> n;
        vector<pair<int, int>> edges;
        vector<int> p(n+1);
        ll ans = 0;
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = (n+2)/2; i <= n; i++) {
            edges.push_back({i, 1});
            swap(p[i], p[1]);
            ll dis = i-1;
            ans += dis*dis;
        }
        for (int i = 2; i < (n+2)/2; i++) {
            edges.push_back({i, n});
            swap(p[i], p[n]);
            ll dis = n-i;
            ans += dis*dis;
        }
        cout << ans << endl;
        for (int i = 1; i < n; i++) cout << p[i] << " ";
        cout << p[n] << endl;
        cout << n-1 << endl;
        for (int i = n-2; i >= 0; i--) cout << edges[i].first << " " << edges[i].second << endl;
        
    }
}