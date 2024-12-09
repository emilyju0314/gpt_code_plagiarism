#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long cnt[1000001];
long long ans[1000001];
long long pw2[1000001];
const long long Mod = 1e9 + 7;
int main() {
  pw2[0] = 1;
  for (int i = 1; i <= 1000000; i++) {
    pw2[i] = (pw2[i - 1] * 2) % Mod;
  }
  long long n, a, aa, s = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    cnt[a]++;
  }
  for (int i = 1; i <= 1000000; i++)
    for (int j = i + i; j <= 1000000; j += i) cnt[i] += cnt[j];
  for (long long i = 1000000; i > 1; i--) {
    aa = (cnt[i] * pw2[cnt[i] - 1]) % Mod;
    for (int j = 2 * i; j <= 1000000; j += i) {
      aa = (aa - ans[j] + 5 * Mod) % Mod;
    }
    ans[i] = aa % Mod;
    s = (s + i * aa) % Mod;
  }
  cout << s;
}
