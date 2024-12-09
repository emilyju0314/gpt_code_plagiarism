#include <bits/stdc++.h>
using namespace std;
const int N = (1e6 + 12);
const int mod = (1e9 + 7);
const int INF = (0x3f3f3f3f);
int a[N];
long long t[N * 4];
map<int, int> cnt, cnt1;
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] += val;
    return;
  }
  int mid = (tl + tr) >> 1;
  if (pos <= mid) {
    update(v + v, tl, mid, pos, val);
  } else {
    update(v + v + 1, mid + 1, tr, pos, val);
  }
  t[v] = t[v + v] + t[v + v + 1];
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > tr || tl > r) {
    return 0;
  }
  if (l <= tl && tr <= r) {
    return t[v];
  }
  int mid = (tl + tr) >> 1;
  return get(v + v, tl, mid, l, r) + get(v + v + 1, mid + 1, tr, l, r);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
  }
  long long ans = 0;
  for (int i = n; i >= 1; i--) {
    cnt[a[i]]--;
    if (cnt[a[i]] > 0) {
      ans += get(1, 1, n, 1, cnt[a[i]]);
    }
    cnt1[a[i]]++;
    update(1, 1, n, cnt1[a[i]], 1);
  }
  cout << ans;
}
