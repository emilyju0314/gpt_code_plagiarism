#include <bits/stdc++.h>
using namespace std;
int r[26];
const int N = 200005;
int vis[N];
int main() {
  memset(vis, 0, sizeof vis);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int M = -1000000;
  for (int i = 0; i < n; ++i) {
    int d = 0;
    for (int j = s[i] - 'a' + 1; j < 26; j++) {
      d = max(d, r[j]);
    }
    r[s[i] - 'a'] = d + 1;
    vis[i] = d + 1;
    M = max(M, d + 1);
  }
  cout << M << endl;
  for (int i = 0; i < n; ++i) cout << vis[i] << ' ';
}
