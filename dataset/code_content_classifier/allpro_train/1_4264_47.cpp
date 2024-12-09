#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int& i : v) cin >> i;
  vector<int> v1 = v;
  sort(v1.begin(), v1.end());
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    bool ok = false;
    int pref = 0;
    for (int i = 0; i < n; i++) {
      if (pref % 2 && v[i] <= v1[mid])
        pref++;
      else if (!(pref % 2))
        pref++;
    }
    if (pref >= k) ok = true;
    pref = 0;
    for (int i = 0; i < n; i++) {
      if (!(pref % 2) && v[i] <= v1[mid])
        pref++;
      else if (pref % 2)
        pref++;
    }
    if (pref >= k) ok = true;
    if (ok)
      r = mid;
    else
      l = mid;
  }
  bool ok = false;
  int pref = 0;
  for (int i = 0; i < n; i++) {
    if (pref % 2 && v[i] <= v1[l])
      pref++;
    else if (!(pref % 2))
      pref++;
  }
  if (pref >= k) ok = true;
  pref = 0;
  for (int i = 0; i < n; i++) {
    if (!(pref % 2) && v[i] <= v1[l])
      pref++;
    else if (pref % 2)
      pref++;
  }
  if (pref >= k) ok = true;
  if (ok)
    cout << v1[l];
  else
    cout << v1[l + 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  long long t;
  t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
