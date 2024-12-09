#include <bits/stdc++.h>
using namespace std;
int s, k, a[55], x = 1;
set<int> st;
int main() {
  scanf("%d%d", &s, &k);
  a[0] = 0, a[1] = 1;
  int i;
  for (i = 2; i <= k; ++i) {
    if (x > s || x > 1e9) break;
    a[i] += x;
    x += a[i];
  }
  for (;; ++i) {
    if (x > s || x > 1e9) break;
    x = 0;
    for (int j = i - k; j < i; ++j) x += a[j];
    a[i] = x;
  }
  for (int j = i; j >= 0; --j) {
    if (a[j] <= s && st.count(a[j]) == 0) s -= a[j], st.insert(a[j]);
  }
  printf("%d\n", (int)st.size());
  for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
    printf("%d ", *it);
  return 0;
}
