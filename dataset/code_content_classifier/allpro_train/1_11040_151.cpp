#include <bits/stdc++.h>
using namespace std;
const int LEN = 200200;
int n, k, a, m, ar[LEN], use[LEN], lef, rig, mid;
bool check(int mid);
int main() {
  cin >> n >> k >> a;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> ar[i];
  lef = 0;
  rig = m + 1;
  while (lef + 1 < rig) {
    mid = (lef + rig) / 2;
    if (check(mid))
      lef = mid;
    else
      rig = mid;
  }
  if (lef == m)
    cout << -1;
  else
    cout << lef + 1;
  return 0;
}
bool check(int mid) {
  int cnt = 0, cnt1 = 0, j;
  for (int i = 0; i < LEN; i++) use[i] = 0;
  for (int i = 1; i <= mid; i++) use[ar[i]] = 1;
  for (int i = 1; i <= n; i++)
    if (!use[i])
      cnt1++;
    else {
      for (j = 1; j < LEN; j++)
        if (j * (a + 1) - 1 > cnt1) break;
      cnt += (j - 1);
      cnt1 = 0;
    }
  for (j = 1; j < LEN; j++)
    if (j * (a + 1) - 1 > cnt1) break;
  cnt += (j - 1);
  if (cnt >= k)
    return 1;
  else
    return 0;
}
