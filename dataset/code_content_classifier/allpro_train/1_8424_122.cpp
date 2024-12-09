#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f *= -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  x *= f;
}
template <typename T, typename... Args>
void read(T &first, Args &...args) {
  read(first);
  read(args...);
}
template <typename T>
void write(T arg) {
  T x = arg;
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) {
    write(x / 10);
  }
  putchar(x % 10 + '0');
}
template <typename T, typename... Ts>
void write(T arg, Ts... args) {
  write(arg);
  if (sizeof...(args) != 0) {
    putchar(' ');
    write(args...);
  }
}
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int N = 3e5 + 5;
int n, q, T;
int vis[N];
set<int> s;
long long a[N], ans = 0;
void solve() {
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      ans += a[i];
      vis[i] = 1;
    }
    if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
      ans -= a[i];
      vis[i] = 2;
    }
  }
}
void check(int l) {
  if (a[l] > a[l - 1] && a[l] > a[l + 1]) vis[l] = 1, ans += a[l];
  if (a[l] < a[l - 1] && a[l] < a[l + 1]) vis[l] = 2, ans -= a[l];
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  while (T--) {
    ans = 0;
    cin >> n >> q;
    for (int i = 1; i <= n + 1; i++) a[i] = 0, vis[i] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    solve();
    cout << ans << endl;
    while (q--) {
      int l, r;
      cin >> l >> r;
      s.clear();
      s.insert(l);
      s.insert(max(1, l - 1));
      s.insert(min(l + 1, n));
      s.insert(r);
      s.insert(max(1, r - 1));
      s.insert(min(r + 1, n));
      for (auto v : s) {
        if (vis[v] == 1) ans -= a[v], vis[v] = 0;
        if (vis[v] == 2) ans += a[v], vis[v] = 0;
      }
      swap(a[l], a[r]);
      for (auto v : s) check(v);
      cout << ans << endl;
    }
  }
}
