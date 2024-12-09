#include <bits/stdc++.h>
using namespace std;
char ch;
int T, n, x;
int c[100007];
int s[100007], p;
multiset<int, greater<int> > Q;
inline void read(int &x) {
  x = 0;
  do {
    ch = getchar();
  } while (ch < '0' || '9' < ch);
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
}
inline void clean() {
  for (int i = (1); i <= (n); i++) c[i] = 0;
}
inline int check(const int x) {
  int tmp;
  if (x == 0) return 1;
  p = 0;
  for (int i = (0); i <= (x); i++) s[i] = 0;
  Q.clear();
  for (int i = (1); i <= (n); i++)
    if (c[i]) Q.insert(c[i]);
  for (int i = (1); i <= (n); i++) {
    if (Q.size() == 0) return 0;
    tmp = *Q.begin();
    Q.erase(Q.begin());
    if (s[p]) Q.insert(s[p]);
    s[p] = tmp - 1;
    p = (p + 1) % x;
  }
  return 1;
}
inline int slv() {
  int l = 0, r = n - 2, mid;
  while (r - l > 1) {
    mid = (l + r) >> 1;
    if (check(mid))
      l = mid;
    else
      r = mid - 1;
  }
  if (check(l + 1))
    return l + 1;
  else
    return l;
}
int main(void) {
  read(T);
  while (T--) {
    read(n);
    for (int i = (1); i <= (n); i++) {
      read(x);
      c[x]++;
    }
    sort(c + 1, c + n + 1);
    cout << slv() << endl;
    clean();
  }
  return 0;
}
