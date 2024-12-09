#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXLOG = log2(MAXN);
const int oo = 1000000005;
const unsigned long long OO = 1000000000000000005;
const double pi = acos(-1.0);
const double EPS = 1e-4;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const int dr8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int drknight[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dcknight[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int MOD = 360;
const int ALPHABET_SIZE = 52;
const int MAX = 1000005;
int t, n;
int32_t main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> g[n];
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    cout << "? " << n << " ";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    cout << endl;
    fflush(stdout);
    queue<int> q;
    vector<vector<int> > dist(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
      q.push(i);
      dist[i][i] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
          if (dist[i][v] == -1) {
            dist[i][v] = dist[i][u] + 1;
            q.push(v);
          }
        }
      }
    }
    int first, d;
    cin >> first >> d;
    first--;
    vector<vector<int> > v;
    for (int i = 0; i < n; i++) {
      vector<int> tmp = {};
      v.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
      v[dist[first][i]].push_back(i);
    }
    int l = d / 2, r = d;
    int res1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (!v[m].empty()) {
        cout << "? " << v[m].size() << " ";
        for (auto u : v[m]) {
          cout << u + 1 << " ";
        }
        int a, b;
        cout << endl;
        fflush(stdout);
        cin >> a >> b;
        if (b == d) {
          res1 = a - 1;
          l = m + 1;
        } else {
          r = m - 1;
        }
      } else {
        r = m - 1;
      }
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (dist[res1][i] == d) {
        c++;
      }
    }
    cout << "? " << c << " ";
    for (int i = 0; i < n; i++) {
      if (dist[res1][i] == d) {
        cout << i + 1 << " ";
      }
    }
    cout << endl;
    fflush(stdout);
    cin >> first >> d;
    cout << "! " << res1 + 1 << " " << first << endl;
    string s;
    cin >> s;
    if (s == "Incorrect") break;
  }
  return 0;
}
