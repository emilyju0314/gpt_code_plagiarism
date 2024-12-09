#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:10240000,10240000")
using namespace std;
const int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
const int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
const int maxn = 3e4 + 7;
const int md = 10007;
const int inf = 1e9 + 7;
const long long inf_L = 1e18 + 7;
const double pi = acos(-1.0);
const double eps = 1e-6;
template <class T>
T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}
template <class T>
bool max_update(T &a, const T &b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool min_update(T &a, const T &b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
T condition(bool f, T a, T b) {
  return f ? a : b;
}
template <class T>
void copy_arr(T a[], T b[], int n) {
  for (int i = 0; i < (n); i++) a[i] = b[i];
}
int make_id(int x, int y, int n) { return x * n + y; }
int f[207];
int minv;
int find(int x) {
  int used[207], c = 0;
  memset(used, 0, sizeof(used));
  while (!used[f[x]]) {
    c++;
    used[x = f[x]] = c;
  }
  max_update(minv, used[f[x]]);
  return c - used[f[x]] + 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= (n); i++) {
    scanf("%d", &f[i]);
  }
  long long ans = 1;
  for (int i = 1; i <= (n); i++) {
    long long tmp = find(i);
    ans = ans / gcd(ans, tmp) * tmp;
  }
  long long tmp = ans;
  while (ans < minv) ans += tmp;
  cout << ans << endl;
  return 0;
}
