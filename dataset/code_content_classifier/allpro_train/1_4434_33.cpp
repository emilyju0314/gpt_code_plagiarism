#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long cnt = 0, ansa = 0, ansb = 0, last = 0;
  int l = 0, r = n - 1;
  while (l <= r) {
    if (cnt % 2 == 0) {
      cnt++;
      long long add = 0;
      while (add <= last && l <= r) {
        add += a[l];
        l++;
      }
      ansa += add;
      if (add <= last) break;
      last = add;
    } else {
      cnt++;
      long long add = 0;
      while (add <= last && l <= r) {
        add += a[r];
        r--;
      }
      ansb += add;
      if (add <= last) break;
      last = add;
    }
  }
  cout << cnt << " " << ansa << " " << ansb << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) solve();
}
