#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int arr[300009], ans[300009], p[300009];
set<int> s;
bool cmp(int x, int y) { return (arr[x] > arr[y]); }
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i), p[i] = i;
  sort(p + 1, p + n + 1, cmp);
  for (int i = k + 1; i <= n + k; i++) s.insert(i);
  for (int i = 1; i <= n; i++) {
    __typeof((s).begin()) it = s.lower_bound(p[i]);
    ans[p[i]] = *it;
    s.erase(*it);
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) res += (ans[i] - i) * 1LL * arr[i];
  printf("%lld\n", res);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
