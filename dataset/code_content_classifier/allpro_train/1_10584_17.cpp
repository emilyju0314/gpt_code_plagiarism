#include <bits/stdc++.h>
using namespace std;
pair<int, int> query(int l, int r) {
  cout << "? " << l << " " << r << '\n';
  cout << flush << '\n';
  int x, y;
  cin >> x >> y;
  return {x, y};
}
int val[200005];
void rec(int l, int r) {
  if (l > r) return;
  auto x = query(l, r);
  int len = r - l + 1;
  if (x.second > len / 2) {
    int a = r + 1 - x.second;
    int b = l - 1 + x.second;
    for (int i = a; i <= b; ++i) {
      val[i] = x.first;
    }
    rec(l, a - 1);
    rec(b + 1, r);
  } else {
    int mid = (l + r) / 2;
    rec(l, mid);
    rec(mid + 1, r);
  }
}
void solve() {
  int n;
  cin >> n;
  rec(1, n);
  cout << "! ";
  for (int i = 1; i < n + 1; i++) {
    cout << val[i] << " ";
  }
  cout << flush << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) solve();
}
