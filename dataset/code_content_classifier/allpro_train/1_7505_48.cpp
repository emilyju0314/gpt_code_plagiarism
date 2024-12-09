#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
int readIn() {
  int a = 0;
  bool positive = true;
  char ch = getchar();
  while (!(ch == '-' || std::isdigit(ch))) ch = getchar();
  if (ch == '-') {
    positive = false;
    ch = getchar();
  }
  while (std::isdigit(ch)) {
    a = a * 10 - (ch - '0');
    ch = getchar();
  }
  return positive ? -a : a;
}
void printOut(int x) {
  char buffer[20];
  int length = 0;
  if (x < 0)
    putchar('-');
  else
    x = -x;
  do buffer[length++] = -(x % 10) + '0';
  while (x /= 10);
  do putchar(buffer[--length]);
  while (length);
  putchar('\n');
}
const int mod = 998244353;
inline void add(int& a, const int& b) {
  register int t;
  a = (t = a + b) >= mod ? t - mod : t;
}
inline void sub(int& a, const int& b) {
  register int t;
  a = (t = a - b) < 0 ? t + mod : t;
}
const int maxn = 4005;
const int maxk = 80;
int m;
struct Tree {
  int n;
  std::vector<std::vector<int> > G;
  void resize(int size) {
    n = size;
    G.resize(size + 1);
  }
  void read() {
    for (int i = 2; i <= n; i++) {
      int from = readIn();
      int to = readIn();
      G[from].push_back(to);
      G[to].push_back(from);
    }
  }
  int f[maxn][maxk];
  int g[maxn][maxk];
  int h[maxn][maxk];
  void DP1(int node, int parent) {
    for (int i = 0; i < G[node].size(); i++) {
      int to = G[node][i];
      if (to == parent) continue;
      DP1(to, node);
      for (int j = 0; j <= m; j++) add(f[node][j], g[to][j]);
    }
    g[node][0] = 1;
    for (int i = 1; i <= m; i++)
      for (int j = 0; j < i; j++)
        g[node][i] =
            (g[node][i] + (long long)f[node][j] * g[node][i - j - 2]) % mod;
  }
  void DP2(int node, int parent) {
    for (int i = 0; i < G[node].size(); i++) {
      int to = G[node][i];
      if (to == parent) continue;
      for (int j = 0; j <= m; j++) sub(f[node][j], g[to][j]);
      std::memset(g[node], 0, sizeof(g[node]));
      g[node][0] = 1;
      for (int j = 1; j <= m; j++)
        for (int k = 0; k < j; k++)
          g[node][j] =
              (g[node][j] + (long long)f[node][k] * g[node][j - k - 2]) % mod;
      for (int j = 0; j <= m; j++) add(f[to][j], g[node][j]);
      for (int j = 0; j <= m; j++) add(f[node][j], g[to][j]);
      h[to][0] = 1;
      for (int j = 1; j <= m; j++)
        for (int k = 0; k < j; k++)
          h[to][j] = (h[to][j] + (long long)f[to][k] * h[to][j - k - 2]) % mod;
      DP2(to, node);
    }
  }
  void run() {
    DP1(1, 0);
    std::memcpy(h[1], g[1], sizeof(h[1]));
    DP2(1, 0);
    for (int i = 0; i <= m; i++)
      for (int j = 1; j <= n; j++) add(ans[i], h[j][i]);
  }
  Tree() : f(), g(), h() {}
  int ans[maxk];
  const int& operator[](int x) const { return ans[x]; }
} tree[2];
int C[maxk * 2][maxk * 2];
void init() {
  C[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      register int t;
      C[i][j] = (t = C[i - 1][j - 1] + C[i - 1][j]) >= mod ? t - mod : t;
    }
  }
}
void run() {
  tree[0].resize(readIn());
  tree[1].resize(readIn());
  m = readIn();
  if (m & 1) {
    printOut(0);
    return;
  }
  init();
  for (int i = 0; i < 2; i++) {
    tree[i].read();
    tree[i].run();
  }
  int ans = 0;
  for (int i = 0; i <= m; i++)
    add(ans, (long long)C[m][i] * tree[0][i] % mod * tree[1][m - i] % mod);
  printOut(ans);
}
int main() {
  run();
  return 0;
}
