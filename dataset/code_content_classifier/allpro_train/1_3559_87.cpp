#include <bits/stdc++.h>
using namespace std;
long long dpf[110][100][60];
long long dpg[110][100][60];
int diff;
int likes_init = 0;
const long long mod = 998244353;
long long fast_exp(long long b, int e) {
  b = b % mod;
  if (e == 0) return 1;
  if (e == 1) return b;
  if (e % 2 == 1) return (b * fast_exp(b, e - 1)) % mod;
  return fast_exp((b * b) % mod, e / 2);
}
long long modinv(long long x) {
  assert(x % mod != 0);
  return fast_exp(x, mod - 2);
}
long long f(int curr, int likes, int runs) {
  if (dpf[curr][likes - likes_init][runs] == 1LL << 40) {
    int dislike = likes + runs - diff;
    if (curr == 0) return 0;
    if (runs == 0) {
      return curr;
    }
    if (dislike < 0) return 0;
    long long tmp1, tmp2, tmp3;
    tmp1 = (curr == 0 ? 0 : curr * f(curr + 1, likes + 1, runs - 1));
    tmp2 =
        (likes - curr == 0 ? 0 : (likes - curr) * f(curr, likes + 1, runs - 1));
    tmp3 = (dislike == 0 ? 0 : dislike * f(curr, likes, runs - 1));
    long long tmp = (tmp1 + tmp2 + tmp3) % mod;
    long long ans = (tmp * modinv(likes + dislike)) % mod;
    return dpf[curr][likes - likes_init][runs] = ans;
  } else {
    return dpf[curr][likes - likes_init][runs];
  }
}
long long g(int curr, int likes, int runs) {
  if (dpg[curr][likes - likes_init][runs] == 1LL << 40) {
    int dislike = likes + runs - diff;
    if (curr == 0) return 0;
    if (runs == 0) {
      return curr;
    }
    if (dislike < 0) return 0;
    long long tmp1 = (curr == 0 ? 0 : curr * g(curr - 1, likes, runs - 1));
    long long tmp2 = (likes == 0 ? 0 : likes * g(curr, likes + 1, runs - 1));
    long long tmp3 =
        (dislike - curr == 0 ? 0 : (dislike - curr) * g(curr, likes, runs - 1));
    long long tmp = (tmp1 + tmp2 + tmp3) % mod;
    long long ans = (tmp * modinv(likes + dislike)) % mod;
    return dpg[curr][likes - likes_init][runs] = ans;
  } else {
    return dpg[curr][likes - likes_init][runs];
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  diff = m;
  int a[n];
  for (int i = 0; i < 110; i++) {
    for (int j = 0; j < 100; j++) {
      for (int k = 0; k < 60; k++) {
        dpf[i][j][k] = 1LL << 40;
        dpg[i][j][k] = 1LL << 40;
      }
    }
  }
  bool good[n];
  int tl = 0;
  for (int i = 0; i < n; i++) {
    cin >> good[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (good[i]) {
      diff += a[i];
      tl += a[i];
    } else
      diff -= a[i];
  }
  likes_init = tl;
  for (int i = 0; i < n; i++) {
    if (good[i]) {
      cout << (f(a[i], tl, m) % mod + mod) % mod << "\n";
    } else {
      cout << (g(a[i], tl, m) % mod + mod) % mod << "\n";
    }
  }
  return 0;
}
