#include <bits/stdc++.h>
using namespace std;
const int maxn = 150005;
int a[maxn];
vector<int> v;
set<pair<int, int> > s;
bool chect() {
  for (int i = 0; i < (int)v.size(); i++) {
    int pos = v[i];
    if (pos & 1) {
      if (a[pos] >= a[pos + 1]) return false;
      if (a[pos] >= a[pos - 1]) return false;
    } else {
      if (a[pos] <= a[pos + 1]) return false;
      if (a[pos] <= a[pos - 1]) return false;
    }
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  a[0] = 1e9;
  if (n % 2 == 1)
    a[n + 1] = 1e9;
  else
    a[n + 1] = -1;
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      bool ok = true;
      if (i + 1 <= n && a[i] >= a[i + 1]) ok = false;
      if (i - 1 >= 1 && a[i] >= a[i - 1]) ok = false;
      if (ok == false) v.push_back(i);
    } else {
      bool ok = true;
      if (i + 1 <= n && a[i] <= a[i + 1]) ok = false;
      if (i - 1 >= 1 && a[i] <= a[i - 1]) ok = false;
      if (ok == false) v.push_back(i);
    }
  }
  int ans = 0;
  if (v.size() > 10) {
    puts("0");
    return 0;
  }
  for (int i = 0; i < (int)(v.size()); i++) {
    for (int j = 1; j <= n; j++) {
      if (v[i] == j) continue;
      swap(a[v[i]], a[j]);
      bool ok = chect();
      if (j & 1) {
        if (a[j] >= a[j + 1] | a[j] >= a[j - 1]) ok = false;
      } else if (a[j] <= a[j + 1] || a[j] <= a[j - 1])
        ok = false;
      if (ok) {
        pair<int, int> p = make_pair(min(v[i], j), max(v[i], j));
        if (!s.count(p)) {
          s.insert(p);
          ans++;
        }
      }
      swap(a[v[i]], a[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
