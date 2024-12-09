#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10, MOD = (int)1e9 + 7;
int n, k, a[MAXN], b[MAXN], c[MAXN], Tohka, Mashiro = 1, v[MAXN];
vector<int> f[MAXN], Invf[MAXN];
bool vis[MAXN], del[MAXN];
int Pow(int a, int b) {
  int d = 1;
  for (; b; d = (b & 1) ? (long long)d * a % MOD : d,
            a = (long long)a * a % MOD, b /= 2)
    ;
  return d;
}
int top, l[MAXN], s[MAXN];
void Calc(int num) {
  int tmp = Mashiro;
  for (int i = 1; i <= top; ++i) {
    ++c[min(l[i], 3)];
    tmp =
        (long long)tmp * Invf[l[i]][b[l[i]]] % MOD * f[l[i]][b[l[i]] + 1] % MOD;
    ++b[l[i]];
  }
  if (c[3]) num = (long long)num * tmp % MOD;
  for (int i = 1; i <= top; ++i) --c[min(l[i], 3)], --b[l[i]];
  Tohka = (Tohka + num) % MOD;
}
void DFS(int first, int num) {
  if (first > k) {
    Calc(num);
    return;
  }
  l[++top] = v[first];
  s[top] = 1;
  DFS(first + 1, num);
  --top;
  for (int i = 1; i <= top; ++i) {
    l[i] += v[first], ++s[i];
    DFS(first + 1, (long long)num * (s[i] - 1) % MOD);
    l[i] -= v[first], --s[i];
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    f[i].resize(n / i + 2);
    Invf[i].resize(n / i + 2);
    f[i][0] = Invf[i][0] = 1;
    for (int j = 1; j * i <= n; ++j) {
      f[i][j] = (long long)f[i][j - 1] * i % MOD;
      if (j >= 2)
        f[i][j] =
            ((long long)f[i][j] + (long long)f[i][j - 2] * (j - 1) % MOD * i) %
            MOD;
      Invf[i][j] = Pow(f[i][j], MOD - 2);
    }
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    vis[a[i]] = true;
  }
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) {
      int cnt = 0;
      for (int first = i; first; first = a[first]) del[first] = true, ++cnt;
      v[++v[0]] = cnt;
    }
  for (int i = 1; i <= n; ++i)
    if (!del[i]) {
      int cnt = 1;
      for (int first = i; a[first] != i; first = a[first])
        del[first] = del[a[first]] = true, ++cnt;
      ++b[cnt], ++c[min(3, cnt)];
    }
  for (int i = 1; i <= n; ++i)
    Mashiro = ((long long)Mashiro * f[i][b[i]]) % MOD;
  DFS(1, 1);
  cout << Tohka << endl;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
