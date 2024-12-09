#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  x = f ? -x : x;
}
const int N = 1e5 + 10;
const int INF = 0x7fffffff;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1);
inline int tr(int x) { return (x - 1) >> 1; }
bool vst[N];
vector<int> a, b;
int main() {
  int t;
  read(t);
  while (t--) {
    memset(vst, 0, sizeof(vst));
    a.clear();
    b.clear();
    int n, cur, ans = 0;
    read(n);
    for (int i = 1; i <= n; i++) {
      read(cur);
      if (cur > n || vst[cur])
        a.push_back(cur);
      else
        vst[cur] = true;
    }
    for (int i = 1; i <= n; i++)
      if (!vst[i]) b.push_back(i);
    sort(a.begin(), a.end());
    cur = a.size();
    for (int i = 0; i < cur; i++, ans++)
      if (b[i] > a[i] || b[i] > tr(a[i])) {
        ans = -1;
        break;
      }
    printf("%d\n", ans);
  }
  return 0;
}
