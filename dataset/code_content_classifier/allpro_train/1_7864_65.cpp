#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n;
pii s[200005];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        s[i] = pii(x, i);
    }

    sort(s, s+n);
    int ans = 0;

    for (int i = 0; i < n; ++i)
        if (i%2 != s[i].second%2)
            ans++;
    cout << ans/2 << endl;
}