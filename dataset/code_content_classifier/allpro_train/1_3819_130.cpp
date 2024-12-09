#include <bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int n, q, a[100000], res[100000];
char s[100000];
int x[100000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < (n); i++) cin >> a[i];
  vector<pair<int, int> > v;
  for (int i = 0; i < (n); i++) v.push_back(make_pair(abs(a[i]), i));
  sort((v).begin(), (v).end());
  for (int i = 0; i < (q); i++) cin >> s[i] >> x[i];
  bool flipped = 0;
  for (int i = (q)-1; i >= 0; i--) {
    if (s[i] == '<') {
      flipped = !flipped;
      x[i] = x[i] - 1;
    }
    if (x[i] > 0) {
      while (!v.empty() && v.back().first > abs(x[i])) {
        int j = v.back().second;
        v.pop_back();
        if (flipped)
          res[j] = abs(a[j]);
        else
          res[j] = -abs(a[j]);
      }
    } else {
      while (!v.empty() && v.back().first >= abs(x[i])) {
        int j = v.back().second;
        v.pop_back();
        if (flipped)
          res[j] = abs(a[j]);
        else
          res[j] = -abs(a[j]);
      }
      flipped = !flipped;
    }
  }
  for (const pair<int, int> p : v) {
    if (flipped)
      res[p.second] = -a[p.second];
    else
      res[p.second] = a[p.second];
  }
  for (int i = 0; i < (n); i++) cout << res[i] << " ";
  cout << endl;
}
