#include <bits/stdc++.h>
using namespace std;
vector<long long> prime;
vector<bool> mark(1e6 + 6, true);
vector<long long> fact(1e6 + 1, 1);
vector<long long> inv(1e6 + 1, 1);
vector<long long> invf(1e6 + 1, 1);
long long Mod = 1e9 + 7;
void seive(long long n) {
  long long i, j;
  mark[1] = false;
  prime.push_back(2);
  for (i = 4; i <= n; i += 2) mark[i] = false;
  for (i = 3; i * i <= n; i++) {
    if (mark[i]) {
      for (j = i * i; j <= n; j += 2 * i) {
        mark[j] = false;
      }
    }
  }
  for (i = 3; i <= n; i += 2)
    if (mark[i]) prime.push_back(i);
}
long long ck(long long n) {
  long long l = 1, r = n, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    if ((mid * (mid + 1)) / 2 < n)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return l;
}
void ft() {
  for (long long i = 2; i <= 1e6; i++) {
    fact[i] = (i * fact[i - 1]) % Mod;
  }
}
void modinv() {
  inv[0] = inv[1] = 1;
  for (long long i = 2; i <= 1e6; i++) {
    inv[i] = inv[Mod % i] * (Mod - Mod / i) % Mod;
  }
}
void modfactinv() {
  invf[0] = invf[1] = 1;
  for (long long i = 2; i <= 1e6; i++) {
    invf[i] = (invf[i - 1] * inv[i]) % Mod;
  }
}
void solve(long long cs) {
  long long n, m, i, z, h, w, e, k = 0, j, a, p, s, b, ans = 2;
  cin >> n >> a >> b;
  if (a == b) {
    k = a * 2 + 2;
  } else if (a < b) {
    k = 2 * (a + 1) + 1;
  } else {
    k = 2 * (b + 1) + 1;
  }
  if (k > n or abs(a - b) > 1)
    cout << "-1";
  else {
    if (a < b) {
      w = (a + 1) * 2 + 1;
      h = 1;
      cout << w-- << " ";
      for (i = 0; i < a + 1; i++) {
        cout << h++ << " " << w-- << " ";
      }
      h = (a + 1) * 2 + 2;
      for (i = 0; i < b - a - 1; i++) {
        cout << h + 1 << " " << h << " " << h + 2 << " ";
        h += 3;
      }
    } else if (b < a) {
      w = n;
      h = n - (b + 1) * 2;
      cout << h++ << " ";
      for (i = 0; i < b + 1; i++) {
        cout << w-- << " " << h++ << " ";
      }
      w = n - (b + 1) * 2 - 1;
      for (i = 0; i < a - b - 1; i++) {
        cout << w - 2 << " " << w << " " << w - 1 << " ";
        w -= 3;
      }
    } else {
      w = k;
      h = 1;
      for (i = 0; i < a + 1; i++) {
        cout << h++ << " " << w-- << " ";
      }
    }
    for (i = k + 1; i <= n; i++) {
      if (a < b)
        cout << i << " ";
      else if (a > b)
        cout << n - i + 1 << " ";
      else
        cout << i << " ";
    }
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1, cs = 1;
  cin >> t;
  while (t--) {
    solve(cs++);
  }
}
