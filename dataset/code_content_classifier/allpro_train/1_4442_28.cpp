#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rng(time(0)); uniform_int_distribution<int>uid(-1e9, 1e9);
int cnt(string s) {
    int res = 0;
    for (int i = 0; i + 3 < s.size(); ++i) res += s.substr(i, 4) == "haha";
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef _DEBUG 
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
    int t; cin >> t;
    while (t--) {
        int n; ll res = 0; cin >> n;
        unordered_map<string, pair<ll, pair<string, string>>> mp;
        while (n--) {
            string a, _, x, y; cin >> a >> _;
            if (_ == ":=") {
                cin >> x;
                mp[a] = { cnt(x), {x.size() > 2 ? x.substr(0, 3) : x, x.size() > 2 ? x.substr(x.size() - 3, 3) : x} };
            }
            else {
                cin >> x >> _ >> y;
                string h = mp[x].second.first, g = mp[y].second.second; int hh = 0;
                while (h.size() < 3 && hh < mp[y].second.first.size()) h += mp[y].second.first[hh++];
                hh = int(mp[x].second.second.size()) - 1;
                reverse(g.begin(), g.end());
                while (g.size() < 3 && hh >= 0) g += mp[x].second.second[hh--];
                reverse(g.begin(), g.end());
                mp[a] = { mp[x].first + mp[y].first + cnt(mp[x].second.second + mp[y].second.first), { h, g } };
            }
            res = mp[a].first;
        }
        cout << res << '\n';
    }
}