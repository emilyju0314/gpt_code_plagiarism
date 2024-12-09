#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int q;
int pos_a[201000];
int a[211000];
int b[201000];
int pos_b[201000];
int front[201000];
int st[200100][32];
int st2[201000][32];
int fast(int x, int y) {
  int temp = 1;
  for (int i = 1; i <= y; i++) {
    temp *= x;
  }
  return y;
}
int Log[201100];
void pre() {
  for (int i = 1; i <= n; i++) {
    st[i][0] = front[i];
  }
  for (int j = 1; j <= 27; j++) {
    for (int i = 1; i <= n; i++) {
      st[i][j] = st[st[i][j - 1]][j - 1];
    }
  }
  Log[0] = -1;
  for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
  for (int i = 1; i <= n; i++) {
    int t = m - 1, p = i;
    for (int j = 27; j >= 0; j--) {
      if (t - (1 << j) >= 0) {
        t -= (1 << j);
        p = st[p][j];
      }
    }
    st2[i][0] = p;
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      st2[i][j] = max(st2[i][j - 1], st2[i + (1 << j - 1)][j - 1]);
    }
  }
  return;
}
void make(int l, int r) {
  int len = r - l + 1;
  int t = Log[len];
  if (max(st2[l][t], st2[r - (1 << t) + 1][t]) >= l)
    cout << 1;
  else
    cout << 0;
  return;
}
int main() {
  cin >> m >> n >> q;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    pos_a[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &b[i]);
    int t = a[pos_a[b[i]] - 1];
    if (!t) t = a[m];
    front[i] = pos_b[t];
    pos_b[b[i]] = i;
  }
  pre();
  int l, r;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &l, &r);
    make(l, r);
  }
  cout << endl;
  return 0;
}
