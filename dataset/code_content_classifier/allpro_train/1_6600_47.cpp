#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
  if (a == 0ll) {
    return 0ll;
  }
  a %= MOD;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}
long long poww(long long a, long long b) {
  if (a == 0ll) {
    return 0ll;
  }
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a;
    }
    a = a * a;
    b >>= 1;
  }
  return ans;
}
void Pv(const vector<int> &V) {
  int Len = int(V.size());
  for (int i = 0; i < Len; ++i) {
    printf("%d", V[i]);
    if (i != Len - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}
void Pvl(const vector<long long> &V) {
  int Len = int(V.size());
  for (int i = 0; i < Len; ++i) {
    printf("%lld", V[i]);
    if (i != Len - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}
inline long long readll() {
  long long tmp = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar();
  return tmp * fh;
}
inline int readint() {
  int tmp = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar();
  return tmp * fh;
}
void pvarr_int(int *arr, int n, int strat = 1) {
  if (strat == 0) {
    n--;
  }
  for (int i = strat; i <= n; i++) {
    printf("%d%c", arr[i], i == n ? '\n' : ' ');
  }
}
void pvarr_LL(long long *arr, int n, int strat = 1) {
  if (strat == 0) {
    n--;
  }
  for (int i = strat; i <= n; i++) {
    printf("%lld%c", arr[i], i == n ? '\n' : ' ');
  }
}
const int maxn = 1010;
const int inf = 0x3f3f3f3f;
int n, m;
int x, y;
int vis[maxn][maxn];
int flag = 1;
void solve() {
  if (flag) {
    y++;
    if (y > m) {
      y = m;
      x++;
      flag ^= 1;
    }
  } else {
    y--;
    if (y < 1) {
      y = 1;
      x++;
      flag ^= 1;
    }
  }
}
int main() {
  n = readint();
  m = readint();
  x = readint();
  y = readint();
  int cnt = 0;
  printf("%d %d\n", x, y);
  printf("%d %d\n", 1, y);
  printf("%d %d\n", 1, 1);
  vis[x][y] = vis[1][y] = vis[1][1] = 1;
  cnt = 3;
  x = y = 1;
  do {
    while (vis[x][y] == 1) {
      solve();
    }
    printf("%d %d\n", x, y);
    cnt++;
    solve();
  } while (cnt < n * m);
  return 0;
}
