#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int tree[maxn], a[maxn], b[maxn], cnt;
map<int, int> mp;
int n;
int lowbit(int x) { return x & (-x); }
void update(int x) {
  for (; x <= n; x += lowbit(x)) tree[x]++;
}
int query(int x) {
  int ans = 0;
  for (; x > 0; x -= lowbit(x)) ans += tree[x];
  return ans;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    cnt = 0;
    mp.clear();
    for (int i = 1; i <= n; i++) tree[i] = 0, scanf("%d", &a[i]), b[i] = a[i];
    long long ans = 0;
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
      if (!mp[b[i]]) mp[b[i]] = ++cnt;
    for (int i = 1; i <= n; i++) {
      int j = mp[a[i]];
      update(j);
      ans += min(i - query(j), query(j - 1));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
