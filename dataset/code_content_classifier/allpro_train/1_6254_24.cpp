#include <bits/stdc++.h>
#define fi first
#define se second
#define ins insert
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;	 //
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            if (i > 1) cout << ' ';
            if (i >= m - (n - m)) {
                cout << m + m - (n - m) - i;
            }
            else cout << i;
        }
        cout << '\n';
    }
    // string sss;
    // while (cin >> sss);
	return 0;
}
