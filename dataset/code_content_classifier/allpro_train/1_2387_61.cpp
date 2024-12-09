#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
const int MAXK = 17;
vector<int> v;
int a[MAXN];
set<int> h;
int s[MAXK][2 * MAXN];
int left_[MAXN + 1];
int right_[MAXN + 1];
int get(int l, int r) {
  int answer = 0;
  for (int k = MAXK - 1; k >= 0; k--)
    if (l + (1 << k) <= r + 1) {
      answer = max(answer, s[k][l]);
      l += (1 << k);
    }
  return answer;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    if (i != 0) v.push_back(abs(a[i] - a[i - 1]));
  }
  for (int i = 0; i < 2 * MAXN; i++)
    for (int k = 0; k < MAXK; k++) s[k][i] = 0;
  for (int i = 0; i < n - 1; i++) s[0][i] = v[i];
  for (int k = 1; k < MAXK; k++)
    for (int i = 0; i < n - 1; i++)
      s[k][i] = max(s[k - 1][i], s[k - 1][i + (1 << (k - 1))]);
  for (int i = 0; i < n - 1; i++) {
    int l = i, r = n - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (get(i + 1, m) < v[i])
        l = m;
      else
        r = m;
    }
    right_[i] = l;
    l = -1, r = i;
    while (r - l > 1) {
      int m = (l + r + 1) / 2;
      if (get(m, i) <= v[i])
        r = m;
      else
        l = m;
    }
    left_[i] = r;
  }
  for (int test = 0; test < q; test++) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    long long answer = 0;
    for (int j = l; j < r; j++) {
      int next_ = min(right_[j], r - 1);
      int prev_ = max(left_[j], l);
      answer += (long long)v[j] * (long long)(j - prev_ + 1) *
                (long long)(next_ - j + 1);
    }
    printf("%lld\n", answer);
  }
  return 0;
}
