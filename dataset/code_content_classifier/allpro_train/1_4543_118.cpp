#include <bits/stdc++.h>
using namespace std;
long long n, c, ans, t[400005];
map<long long, long long> mp, cnt;
long long lowbit(long long x) { return x & (-x); }
void add(long long x) {
  for (; x <= 2 * n; x += lowbit(x)) t[x] += 1;
}
long long query(long long x) {
  long long ans = 0;
  for (; x; x -= lowbit(x)) ans += t[x];
  return ans;
}
int main() {
  long long i, x, y;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> x >> y;
    if (!mp[x]) mp[x] = x;
    if (!mp[y]) mp[y] = y;
    swap(mp[x], mp[y]);
  }
  for (auto t : mp) {
    x = t.first;
    cnt[x] = ++c;
  }
  for (auto t : mp) {
    x = t.first;
    y = t.second;
    ans += abs(x - y - cnt[x] + cnt[y]);
    ans += cnt[x] - query(cnt[y]) - 1;
    add(cnt[y]);
  }
  cout << ans << endl;
  return 0;
}
