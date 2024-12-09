#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int res[2005], uu[2005][2005], dd[2005][2005], x[2005], y[2005];
char s[2005][2005];
int init(int bas, int son) {
  int res = 0;
  for (int i = 1; i <= m; i++) {
    uu[((bas + son) >> 1)][i] =
        min(uu[((bas + son) >> 1)][i], ((bas + son) >> 1) - bas + 1);
    dd[((bas + son) >> 1)][i] =
        min(dd[((bas + son) >> 1)][i], son - ((bas + son) >> 1) + 1);
  }
  deque<int> u, d;
  int last = 0;
  for (int i = 1; i <= m; i++) {
    while (last <= m) {
      last++;
      while (((int)u.size()) &&
             uu[((bas + son) >> 1)][last] <= uu[((bas + son) >> 1)][u.back()])
        u.pop_back();
      u.push_back(last);
      while (((int)d.size()) &&
             dd[((bas + son) >> 1)][last] <= dd[((bas + son) >> 1)][d.back()])
        d.pop_back();
      d.push_back(last);
      if (last - i + 1 > (uu[((bas + son) >> 1)][u.front()] +
                          dd[((bas + son) >> 1)][d.front()] - 1) *
                             (uu[((bas + son) >> 1)][u.front()] > 0 &&
                              dd[((bas + son) >> 1)][d.front()] > 0))
        break;
    }
    res = max(res, last - i);
    if (u.front() == i) u.pop_front();
    if (d.front() == i) d.pop_front();
  }
  return res;
}
void upans(int bas, int son, int val) {
  for (int i = bas; i <= son; i++) res[i] = max(res[i], val);
}
void solve(int bas, int son, vector<int> q) {
  if (bas > son) return;
  vector<int> u, d;
  int up = ((bas + son) >> 1) - 1;
  int down = ((bas + son) >> 1) + 1;
  for (int i : q) {
    if (x[i] <= up)
      u.push_back(i);
    else
      d.push_back(i);
  }
  upans(1, (((int)q.size()) ? q[0] - 1 : k), init(bas, son));
  for (int now = 0; now < ((int)q.size()); now++) {
    int i = q[now];
    if (x[i] <= ((bas + son) >> 1))
      uu[((bas + son) >> 1)][y[i]] =
          min(uu[((bas + son) >> 1)][y[i]], ((bas + son) >> 1) - x[i]);
    if (x[i] >= ((bas + son) >> 1))
      dd[((bas + son) >> 1)][y[i]] =
          min(dd[((bas + son) >> 1)][y[i]], x[i] - ((bas + son) >> 1));
    upans(i, (now == ((int)q.size()) - 1 ? k : q[now + 1] - 1), init(bas, son));
  }
  solve(bas, up, u);
  solve(down, son, d);
}
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      uu[j][i] = (uu[j - 1][i] + 1) * (s[j][i] == '.');
    }
    for (int j = n; j >= 1; j--) {
      dd[j][i] = (dd[j + 1][i] + 1) * (s[j][i] == '.');
    }
  }
  vector<int> q;
  for (int i = 1; i <= k; i++) {
    q.push_back(i);
    scanf("%d %d", &x[i], &y[i]);
  }
  solve(1, n, q);
  for (int i = 1; i <= k; i++) {
    printf("%d\n", res[i]);
  }
}
