#include <bits/stdc++.h>
using namespace std;
int a[100010], b[100010], Max[100010], ind[100010], vis[100010];
multiset<int> s;
inline int read() {
  char c = getchar();
  int x = 0, flag = 1;
  while (!isdigit(c)) {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  return x * flag;
}
int main() {
  int n = read(), k = read(), nn = 0;
  long long tot = 0;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read(), vis[a[i]] = 1;
  for (int i = 1; i <= k; i++)
    if (!vis[i]) nn++;
  for (int i = 1; i <= n; i++) {
    if (b[i] > Max[a[i]]) Max[a[i]] = b[i], ind[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (ind[a[i]] != i) s.insert(b[i]);
  }
  for (int i = 1; i <= nn; i++) tot += *s.begin(), s.erase(s.begin());
  cout << tot;
  return 0;
}
