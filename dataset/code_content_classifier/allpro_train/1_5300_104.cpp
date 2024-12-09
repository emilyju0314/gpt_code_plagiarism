#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1000 * 100 + 100;
int n, m, k, z, x, y, minn[maxn], a[maxn], sum[maxn], b[maxn], ans, mid;
string s;
int bs(int x, int y, int k) {
  mid = (x + y) / 2;
  if (y == x) return x;
  if (minn[mid] > sum[k]) return bs(mid + 1, y, k);
  return bs(x, mid, k);
}
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a')
      a[i] = int(s[i]);
    else
      a[i] = s[i] - 'A' + 'a';
    if (a[i] == int('a') || a[i] == int('e') || a[i] == int('o') ||
        a[i] == int('u') || a[i] == int('i'))
      a[i] = -1;
    else
      a[i] = 2;
    minn[0] = sum[0] = a[0];
    sum[i] = sum[i - 1] + a[i];
    minn[i] = min(minn[i - 1], sum[i]);
  }
  for (int i = 0; i < s.size(); i++) {
    if (sum[i] >= 0) {
      ans = max(ans, i + 1);
      continue;
    }
    k = bs(0, i - 1, i);
    if (sum[k] > sum[i]) continue;
    ans = max(ans, i - k);
  }
  if (sum[ans - 1] >= 0) m++;
  for (int i = 1; i < s.size() - ans + 1; i++) {
    x = sum[i + ans - 1] - sum[i - 1];
    if (x >= 0) m++;
  }
  if (!ans) {
    cout << "No solution" << endl;
    return 0;
  }
  cout << ans << " " << m << endl;
  return 0;
}
