#include <bits/stdc++.h>
using namespace std;
int n, k;
int q;
int a[5555];
set<pair<int, int> > st;
set<int> yes;
int main() {
  clock_t start = clock();
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    yes.insert(a[i]);
    for (int j = 1; j <= 20; j++) {
      st.insert(make_pair(a[i] * j, j));
    }
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int num;
    scanf("%d", &num);
    int ans = 100;
    for (set<pair<int, int> >::iterator it = st.begin(); it != st.end(); it++) {
      int nn = num - (*it).first;
      if (nn < 0) continue;
      for (int kk = 0; kk <= k - (*it).second; kk++) {
        if (!st.count(make_pair(nn, kk)) && nn != 0) continue;
        ans = min(ans, (*it).second + kk);
        break;
      }
    }
    if (ans > k)
      printf("-1\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
