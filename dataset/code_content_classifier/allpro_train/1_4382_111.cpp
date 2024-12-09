#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000 + 6;
struct Shop {
  int p;
  int d;
};
int n, m, k;
Shop shop[MAX];
int a[MAX];
bool cmp(Shop a, Shop b) { return a.d < b.d; }
int main() {
  scanf("%d %d %d", &n, &m, &k);
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  int prev = a[n], cnt = 1;
  for (int i = n - 1; i > 0; i--) {
    if (a[i] == prev) {
      a[i] -= (cnt / k);
      cnt++;
    } else {
      if (a[i] == a[i + 1]) {
        if (cnt % k == 0) {
          a[i] = a[i + 1] - 1;
          cnt = 1;
        } else {
          a[i] = a[i + 1];
          cnt++;
        }
      } else {
        prev = a[i];
        cnt = 1;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int d;
    scanf("%d", &d);
    shop[i].p = i;
    shop[i].d = d;
  }
  sort(shop + 1, shop + m + 1, cmp);
  int p1 = 1, p2 = 1, d = 0;
  cnt = 0;
  vector<int> ans;
  while (p1 <= n && p2 <= m) {
    if (a[p1] < d) {
      puts("-1");
      return 0;
    }
    if (a[p1] <= shop[p2].d) {
      p1++;
      cnt++;
    } else {
      if (shop[p2].d >= d) {
        ans.push_back(shop[p2].p);
        p2++;
        cnt++;
      } else {
        while (p2 <= m && shop[p2].d < d) {
          p2++;
        }
      }
    }
    if (cnt == k) {
      d++;
      cnt = 0;
    }
  }
  if (cnt == k) {
    d++;
    cnt = 0;
  }
  while (p1 <= n) {
    if (a[p1] < d) {
      puts("-1");
      return 0;
    }
    p1++;
    cnt++;
    if (cnt == k) {
      d++;
      cnt = 0;
    }
  }
  while (p2 <= m) {
    if (shop[p2].d < d) {
      p2++;
    } else {
      ans.push_back(shop[p2].p);
      p2++;
      cnt++;
      if (cnt == k) {
        d++;
        cnt = 0;
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
}
