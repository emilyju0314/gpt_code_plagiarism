#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long N = 1e9 + 5;
const long long Hash = 31;
const double pi = 3.141592653;
const double E = 2.718281828;
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int tag = 0, f = 0;
  vector<int> v;
  int md = 0, mu = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      v.push_back(tag);
      for (int j = 0; j < a[i] - 1; j++) {
        tag--;
        v.push_back(tag);
      }
      md = min(tag, md);
      mu = max(tag, mu);
    } else {
      v.push_back(tag);
      for (int j = 0; j < a[i] - 1; j++) {
        tag++;
        v.push_back(tag);
      }
      md = min(tag, md);
      mu = max(tag, mu);
    }
  }
  md *= -1;
  vector<int> out[mu + md + 1];
  for (int i = 0; i < v.size(); i++) {
    out[v[i] + md].push_back(i);
  }
  for (int i = mu + md; i >= 0; i--) {
    int tmp = 0;
    bool u = true;
    if (i < md) u = false;
    for (int j : out[i]) {
      while (tmp < j) {
        cout << " ";
        tmp++;
      }
      if (u)
        cout << "/";
      else
        cout << "\\";
      u = !u;
      tmp++;
    }
    for (int i = tmp; i < v.size(); i++) cout << " ";
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
