#include <bits/stdc++.h>
using namespace std;
int b[10], c[555000];
long long a[555000];
long long original0[555000];
long long nttA[555000];
long long nttB[555000];
long long nttC[555000];
long long result[5][555000];
long long d[555000];
long long mod = 998244353, primitive = 3;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}
namespace ntt {
int butterfly(int a, int length) {
  int result = 0;
  while (length > 1) {
    length /= 2;
    result += (a % 2) * length;
    a /= 2;
  }
  return result;
}
void qntt(int length, int sign, long long* ntt, long long* original) {
  int a = 1;
  while (a < length) a *= 2;
  if (a > length) puts("invalid");
  if (a > length) return;
  for (int i = 0; i < length; i++) {
    ntt[i] = original[butterfly(i, length)];
  }
  for (int l = 2; l <= length; l *= 2) {
    long long b;
    if (sign == 1) {
      b = qpow(primitive, (mod - 1) / l);
    } else if (sign == -1) {
      b = qpow(primitive, mod - 1 - (mod - 1) / l);
    } else
      puts("invalid"), b = 0;
    for (int j = 0; j < length; j += l) {
      long long c = 1;
      for (int i = j; i < j + l / 2; i++) {
        long long c2 = ntt[i];
        long long c3a = ntt[i + l / 2];
        long long c3 = (c3a * c) % mod;
        ntt[i] = (c2 + c3) % mod;
        ntt[i + l / 2] = (mod + c2 - c3) % mod;
        c *= b;
        c %= mod;
      }
    }
  }
}
};  // namespace ntt
int main() {
  original0[0] = 1;
  original0[1] = 2;
  ntt::qntt(524288, 1, nttA, original0);
  original0[2] = 1;
  ntt::qntt(524288, 1, nttB, original0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    a[t]++;
    if (a[t] > 2) a[t] = 2;
  }
  for (int i = 0; i < k; i++) {
    cin >> b[i];
    int A = 0, B = 0;
    for (int j = 1; j < b[i]; j++) {
      if (a[j] == 1) A++;
      if (a[j] == 2) B++;
    }
    for (int j = 0; j < 524288; j++) {
      nttC[j] = qpow(nttA[j], A) * qpow(nttB[j], B) % mod;
    }
    ntt::qntt(524288, -1, *(result + i), nttC);
    for (int j = 0; j < 524288; j++) {
      result[i][j] *= 998242449;
      result[i][j] %= mod;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int op;
    cin >> op;
    if (op % 2 == 1) {
      cout << 0 << endl;
      continue;
    }
    op = (op - 2) / 2;
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      if (op - b[i] < 0 || op - b[i] > 524288) continue;
      ans += result[i][op - b[i]];
    }
    cout << ans % mod << endl;
  }
}
