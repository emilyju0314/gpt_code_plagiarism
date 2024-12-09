#include <bits/stdc++.h>
using namespace std;
int n, m, q;
int num[200011];
int phi[200011], lp;
int Phi(int x) {
  int ans = x;
  for (int i = 2; 1ll * i * i <= x; i++)
    if (x % i == 0) {
      ans = 1ll * ans * (i - 1) / i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) ans = 1ll * ans * (x - 1) / x;
  return ans;
}
bool check(int L, int R, int cur) {
  for (int i = L; i <= R; i++)
    if (num[i] == 1) {
      R = i;
      break;
    }
  long long last = num[R];
  for (int i = R - 1; i >= L; i--) {
    long long mi = last;
    last = 1;
    for (int j = 1; j <= mi; j++) {
      last *= num[i];
      if (last >= phi[cur]) return 1;
    }
  }
  return 0;
}
int powmod(int a, long long b, int p) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % p;
    a = 1ll * a * a % p;
    b >>= 1;
  }
  return ans;
}
long long calc(int L, int R) {
  for (int i = L; i <= R; i++)
    if (num[i] == 1) {
      R = i;
      break;
    }
  long long last = num[R];
  for (int i = R - 1; i >= L; i--) {
    long long mi = last;
    last = 1;
    for (int j = 1; j <= mi; j++) last *= num[i];
  }
  return last;
}
int play(int L, int R, int cur) {
  if (phi[cur] == 1) return 0;
  int now = num[L] % phi[cur];
  if (now == 0) return 0;
  if (now == 1) return 1;
  if (L == R) return now;
  if (check(L + 1, min(R, L + 6), cur))
    return powmod(now, play(L + 1, R, cur + 1) + phi[cur + 1], phi[cur]);
  return powmod(now, calc(L + 1, min(R, L + 6)), phi[cur]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  phi[0] = m;
  lp = 0;
  while (phi[lp] != 1) lp++, phi[lp] = Phi(phi[lp - 1]);
  scanf("%d", &q);
  int x, y;
  while (q--) {
    scanf("%d%d", &x, &y);
    printf("%d\n", play(x, y, 0) % m);
  }
  return 0;
}
