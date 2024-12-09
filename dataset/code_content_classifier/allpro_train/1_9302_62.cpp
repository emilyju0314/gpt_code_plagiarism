#include <bits/stdc++.h>
using namespace std;
void read(int& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int inf = 1000000000;
int n, m, i, j, k, l, p, q, e[100010][3], x, y, z, d, c1, c2, xx, yy;
long long sum[100010];
multiset<pair<long long, int> > S;
multiset<pair<long long, int> >::iterator i1, i2;
int fa[100010];
long long ans, res, t1, t2;
int get(int i) { return fa[i] == i ? i : fa[i] = get(fa[i]); }
vector<pair<int, int> > V;
vector<pair<int, int> >::iterator pos;
int main() {
  read(n);
  read(m);
  read(p);
  read(q);
  for (i = 1; i <= n; i++) fa[i] = i;
  for (i = 1; i <= m; i++) {
    read(e[i][0]), read(e[i][1]), read(e[i][2]);
    x = e[i][0];
    y = e[i][1];
    fa[get(x)] = get(y);
    xx = x;
    yy = y;
  }
  for (i = 1; i <= m; i++) {
    x = e[i][0];
    y = e[i][1];
    z = e[i][2];
    sum[get(x)] += z;
  }
  for (i = 1; i <= n; i++)
    if (get(i) == i) d++, S.insert(make_pair(sum[i], i));
  if (d < q) {
    printf("NO\n");
    return 0;
  }
  if (q == d && q == n && (p > 0)) {
    printf("NO\n");
    return 0;
  }
  while (p > 0 && d > q) {
    t1 = (*S.begin()).first;
    c1 = (*S.begin()).second;
    S.erase(S.begin());
    t2 = (*S.begin()).first;
    c2 = (*S.begin()).second;
    S.erase(S.begin());
    res = min(t1 + t2 + 1, 1LL * inf);
    ans += res;
    S.insert(make_pair(res + t1 + t2, c1));
    V.push_back(make_pair(c1, c2));
    xx = c1;
    yy = c2;
    d--;
    p--;
  }
  if (d > q) {
    printf("NO\n");
    return 0;
  }
  while (p) p--, ans += 1000, V.push_back(make_pair(xx, yy));
  printf("YES\n");
  for (pos = V.begin(); pos != V.end(); pos++)
    printf("%d %d\n", pos->first, pos->second);
  scanf("\n");
  return 0;
}
