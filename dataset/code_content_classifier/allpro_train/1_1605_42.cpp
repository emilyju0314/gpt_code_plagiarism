#include <bits/stdc++.h>
using namespace std;
const int maxn = 400000 + 10;
int n, m, cnt;
int adj[30][30];
char str[maxn];
set<pair<int, int> > seg;
int main() {
  scanf("%d%d%d", &n, &m, &cnt);
  scanf("%s", str + 1);
  memset(adj, 0, sizeof adj);
  for (int i = 1; i < n; i++) adj[str[i] - 'a'][str[i + 1] - 'a']++;
  seg.clear();
  seg.insert(make_pair(0, 26));
  seg.insert(make_pair(1, str[1] - 'a'));
  seg.insert(make_pair(n + 1, 26));
  seg.insert(make_pair(n + 2, 26));
  for (int i = 2; i <= n; i++) seg.insert(make_pair(i, str[i] - 'a'));
  while (m--) {
    int k;
    scanf("%d", &k);
    if (k == 1) {
      int l, r;
      char tmp[3];
      scanf("%d%d%s", &l, &r, tmp);
      int c = tmp[0] - 'a';
      set<pair<int, int> >::iterator left = seg.lower_bound(make_pair(l, 0));
      left--;
      int leftc = left->second;
      left++;
      set<pair<int, int> >::iterator right =
          seg.lower_bound(make_pair(r + 2, 0));
      right--;
      int rightc = right->second;
      right++;
      int ls = leftc;
      for (set<pair<int, int> >::iterator it = left; it != right;) {
        adj[ls][it->second]--;
        ls = it->second;
        seg.erase(it++);
      }
      adj[leftc][c]++;
      adj[c][rightc]++;
      seg.insert(make_pair(l, c));
      seg.insert(make_pair(r + 1, rightc));
    } else {
      char tmp[20];
      scanf("%s", tmp);
      int ans = n;
      for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++)
          ans -= adj[tmp[i] - 'a'][tmp[j] - 'a'];
      printf("%d\n", ans);
    }
  }
  return 0;
}
