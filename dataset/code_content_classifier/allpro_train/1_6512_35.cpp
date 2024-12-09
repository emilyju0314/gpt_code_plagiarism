#include <bits/stdc++.h>
using namespace std;
int n, q;
int ans[(int)(3e5 + 10)];
int a[(int)(3e5 + 10)];
int c[(int)(3e5 + 10)];
int lowbit(int x) { return x & -x; }
int sum(int x) {
  int ret = 0;
  while (x > 0) {
    ret += c[x];
    x -= lowbit(x);
  }
  return ret;
}
void add(int x, int d) {
  while (x <= n) {
    c[x] += d;
    x += lowbit(x);
  }
}
vector<int> L[(int)(3e5 + 10)];
vector<int> id[(int)(3e5 + 10)];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = i - a[i];
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    int l = 1 + x, r = n - y;
    L[r].push_back(l);
    id[r].push_back(i);
  }
  for (int r = 1; r <= n; r++) {
    if (a[r] >= 0) {
      int left = 0, right = r;
      while (left < right) {
        int mid = left + right + 1 >> 1;
        if (sum(mid) >= a[r])
          left = mid;
        else
          right = mid - 1;
      }
      if (left != 0) {
        add(1, 1);
        add(left + 1, -1);
      }
    }
    for (int j = 0; j < L[r].size(); j++) {
      int l = L[r][j];
      int ID = id[r][j];
      ans[ID] = sum(l);
    }
  }
  for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}
