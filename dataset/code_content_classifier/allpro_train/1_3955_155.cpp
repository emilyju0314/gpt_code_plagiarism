#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, ans, cnt;
int b[1000006];
multiset<int> s;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a), b[a]++;
  for (int i = 1; i < m; i++) {
    for (int j = 0; j < b[i]; j++) s.insert(i);
    cnt += b[i];
  }
  for (int i = 1, j = m; j <= 1000000; i++, j++) {
    cnt += b[j];
    for (int q = 0; q < b[j]; q++) {
      s.insert(j);
    }
    while (cnt >= k) {
      cnt--;
      b[*s.rbegin()]--;
      s.erase(--s.end());
      ans++;
    }
    for (int q = 0; q < b[i]; q++) {
      cnt--;
      s.erase(s.begin());
    }
  }
  printf("%d", ans);
  return 0;
}
