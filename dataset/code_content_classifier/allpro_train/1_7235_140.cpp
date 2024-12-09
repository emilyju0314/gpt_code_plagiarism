#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const double Pi = acos(-1.0);
const int maxn = 2e6 + 5;
const int seed = 1007;
const int mod[2] = {1000000007, 1000000009};
char s[maxn];
int Hash[2][maxn], ans[maxn];
int f[2][maxn], vis[maxn], tim;
map<pair<int, int>, int> arr;
void init() {
  for (int i = 0; i < 2; ++i) {
    f[i][0] = 1;
    for (int j = 1; j < maxn; ++j) {
      f[i][j] = (long long)f[i][j - 1] * seed % mod[i];
    }
  }
}
pair<int, int> getHash(char *s) {
  int res[2] = {0, 0};
  int n = strlen(s);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      res[i] = ((long long)res[i] * seed + s[j]) % mod[i];
    }
  }
  return pair<int, int>(res[0], res[1]);
}
pair<int, int> getHash(int l, int r) {
  int res[2];
  for (int i = 0; i < 2; ++i) {
    res[i] = (Hash[i][r] -
              (long long)Hash[i][l - 1] * f[i][r - l + 1] % mod[i] + mod[i]) %
             mod[i];
  }
  return pair<int, int>(res[0], res[1]);
}
void getPre(char *s, int k) {
  int n = strlen(s + 1);
  for (int i = 0; i < 2; ++i) {
    Hash[i][0] = 0;
    for (int j = 1; j <= n; ++j) {
      Hash[i][j] = ((long long)Hash[i][j - 1] * seed + s[j]) % mod[i];
    }
    for (int j = n + 1, t = 1; t < k; ++t, ++j)
      Hash[i][j] = ((long long)Hash[i][j - 1] * seed + s[t]) % mod[i];
  }
}
bool check(int st, int n, int k) {
  tim++;
  int l = st, r = st + k - 1;
  for (int i = 1; i <= n; i++, l += k, r += k) {
    pair<int, int> p = getHash(l, r);
    if (!arr.count(p)) return 0;
    int val = arr[p];
    if (vis[val] == tim) return 0;
    vis[val] = tim;
    ans[i] = val;
  }
  printf("YES\n");
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", ans[i], i == n ? '\n' : ' ');
  }
  return 1;
}
int main() {
  init();
  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    tim = 1;
    arr.clear();
    scanf("%s", s + 1);
    getPre(s, k);
    int g;
    scanf("%d", &g);
    for (int i = 1; i <= g; ++i) {
      scanf("%s", s);
      pair<int, int> p = getHash(s);
      arr[p] = i;
    }
    bool ok = 0;
    for (int i = 1; i <= k; ++i) {
      if (check(i, n, k)) {
        ok = 1;
        break;
      }
    }
    if (!ok) printf("NO\n");
  }
  return 0;
}
