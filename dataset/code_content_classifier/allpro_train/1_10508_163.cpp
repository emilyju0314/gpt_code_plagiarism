#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <class T>
inline void checkmin(T &x, T y) {
  if (x > y) x = y;
}
template <class T>
inline T Min(T x, T y) {
  return (x > y ? y : x);
}
template <class T>
inline T Max(T x, T y) {
  return (x < y ? y : x);
}
template <class T>
T Abs(T a) {
  return a > 0 ? a : (-a);
}
template <class T>
inline T lowbit(T n) {
  return (n ^ (n - 1)) & n;
}
template <class T>
inline int countbit(T n) {
  return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}
int n;
int y;
vector<int> a[111111];
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 1; i <= (int)(n); ++i) a[i].clear();
    printf("%d\n", n - 1);
    for (int i = 1; i <= (int)(n - 1); ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      printf("%d %d %d\n", 2, u, v);
      a[u].push_back(i);
      a[v].push_back(i);
    }
    for (int i = 1; i <= (int)(n); ++i)
      for (int j = 0; j <= (int)(a[i].size() - 2); ++j)
        printf("%d %d\n", a[i][j], a[i][j + 1]);
  }
  return 0;
}
