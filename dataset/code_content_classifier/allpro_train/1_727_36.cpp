#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, pnt, a[N], dp1[N], dp2[N], l[N], r[N];
vector<int> st;
void getDp(int plc) {
  for (int i = 0; i < pnt; i++) {
    int dif = a[plc] - st[i], lst = plc - dif;
    if (lst < 0) continue;
    lst = l[lst];
    if (lst == 0) {
      dp1[plc] = max(dp1[plc], pnt - i);
      continue;
    }
    dp1[plc] = max(dp2[lst - 1] + pnt - i, dp1[plc]);
  }
  return;
}
void addDp(int plc) {
  for (int i = pnt; i < m; i++) {
    int dif = st[i] - a[plc], nxt = plc + dif;
    if (nxt >= n) continue;
    nxt = r[nxt];
    dp2[nxt] = max(dp1[plc] + i - pnt + 1, dp2[nxt]);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  l[0] = 0, r[n - 1] = n - 1;
  for (int i = 1; i < n; i++)
    (a[i] == a[i - 1] + 1) ? l[i] = l[i - 1] : l[i] = i;
  for (int i = n - 2; i >= 0; i--)
    (a[i] == a[i + 1] - 1) ? r[i] = r[i + 1] : r[i] = i;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    st.push_back(x);
  }
  sort(st.begin(), st.end());
  for (int i = 0; i < n; i++) {
    while (pnt != m && st[pnt] <= a[i]) pnt++;
    getDp(i);
    dp2[i] = max(dp2[i], dp1[i]);
    dp2[i + 1] = max(dp2[i + 1], dp1[i]);
    if (i) dp2[i] = max(dp2[i], dp2[i - 1]), dp1[i] = max(dp2[i - 1], dp1[i]);
    addDp(i);
  }
  cout << dp2[n - 1];
  return 0;
}
