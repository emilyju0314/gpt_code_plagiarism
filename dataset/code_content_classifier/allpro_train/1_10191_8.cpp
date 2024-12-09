#include <bits/stdc++.h>
using namespace std;
set<pair<int, int> > st;
int main() {
  int n, k, x, i, rightmost, dist;
  pair<int, int> p, temp;
  bool swapped;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) {
    scanf("%d", &x);
    st.insert(make_pair(x, -i));
  }
  rightmost = n + 1;
  dist = 0;
  swapped = false;
  for (i = 1; i <= n; i++) {
    p = *st.begin();
    st.erase(st.begin());
    temp = *st.begin();
    if (-p.second > rightmost) {
      if (temp.first != p.first) dist = k;
      continue;
    }
    if (rightmost + p.second > k) {
      if (!swapped && rightmost + p.second - dist <= k) {
        swapped = true;
        rightmost -= dist;
      } else {
        printf("NO\n");
        return 0;
      }
    }
    if (temp.first != p.first) {
      if (!swapped) dist = k - (rightmost + p.second);
      rightmost = -p.second;
    }
  }
  printf("YES\n");
  return 0;
}
