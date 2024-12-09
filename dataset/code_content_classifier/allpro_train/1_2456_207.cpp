#include <bits/stdc++.h>
using namespace std;
vector<int> ans;
struct node {
  int w, v, no;
} m[100002];
bool cmp(node x, node y) {
  if (x.w != y.w) {
    return x.w < y.w;
  }
  return x.v < y.v;
}
int main(void) {
  long long n, k, h, i, j, temp;
  double mid, l, r, t;
  scanf("%I64d %I64d %I64d", &n, &k, &h);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &m[i].w);
  }
  for (i = 0; i < n; i++) {
    scanf("%I64d", &m[i].v);
    m[i].no = i + 1;
  }
  sort(m, m + n, cmp);
  l = 0;
  r = 1e9;
  for (j = 0; j < 100; j++) {
    mid = (l + r) / 2.0;
    temp = k;
    for (i = n - 1; i >= 0; i--) {
      if ((mid * m[i].v) / h >= 1.0 * temp) {
        temp--;
      }
    }
    if (temp <= 0) {
      r = mid;
    } else {
      l = mid;
    }
  }
  temp = k;
  for (i = n - 1; i >= 0; i--) {
    if ((r * m[i].v) / h >= 1.0 * temp) {
      temp--;
      ans.push_back(i);
    }
  }
  for (i = k - 1; i >= 0; i--) {
    if (i != k - 1) {
      printf(" ");
    }
    printf("%d", m[ans[i]].no);
  }
  return 0;
}
