#include <bits/stdc++.h>
using namespace std;
int mns[200010];
int a[200010];
int cmp(int a, int b) { return a < b; }
int main() {
  int n, k;
  int tol = 0, cnt = 0;
  bool f = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      mns[tol++] = cnt;
      cnt = 0;
      f = 1;
    } else {
      if (f) cnt++;
    }
  }
  sort(mns, mns + tol, cmp);
  int ans = tol * 2;
  if (tol > k) {
    cout << "-1" << endl;
    return 0;
  }
  k -= tol;
  for (int i = 1; i < tol; i++) {
    if (k >= mns[i]) {
      ans--;
      ans--;
      k -= mns[i];
    }
  }
  if (k >= cnt && f) ans--;
  cout << ans << endl;
  return 0;
}
