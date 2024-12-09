#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long isPowerof2(long long x) { return (x && !(x & x - 1)); }
const long long p = 131;
const long long mod1 = 485144;
const long long mod2 = 596741;
long long pre1[1000005];
long long pre2[1000005];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre1[0] = 1;
  pre2[0] = 1;
  for (long long(i) = (1); i < (1000005); i++) {
    pre1[i] = pre1[i - 1] * p;
    pre1[i] %= mod1;
    pre2[i] = pre2[i - 1] * p;
    pre2[i] %= mod2;
  }
  long long n;
  cin >> n;
  string second[n];
  for (long long(i) = (0); i < (n); i++) cin >> second[i];
  if (n == 1) {
    cout << second[0];
    return 0;
  }
  string ans = second[0];
  for (long long(i) = (1); i < (n); i++) {
    long long cut = 0;
    string cur = second[i];
    long long hash1 = ((long long)ans[ans.size() - 1] + 1);
    long long shash1 = ((long long)ans[ans.size() - 1] + 1);
    long long hash2 = ((long long)cur[0] + 1);
    long long shash2 = ((long long)cur[0] + 1);
    if (hash1 == hash2) {
      cut = 1;
    }
    for (long long(j) = (1); j < (min(cur.size(), ans.size())); j++) {
      hash2 = ((hash2 * p) % mod1 + ((long long)cur[j] + 1)) % mod1;
      shash2 = ((shash2 * p) % mod2 + ((long long)cur[j] + 1)) % mod2;
      hash1 = (hash1 % mod1 +
               (((long long)ans[ans.size() - 1 - j] + 1) * pre1[j]) % mod1) %
              mod1;
      shash1 = (shash1 % mod2 +
                (((long long)ans[ans.size() - 1 - j] + 1) * pre2[j]) % mod2) %
               mod2;
      if (hash1 == hash2 && shash1 == shash2) {
        cut = j + 1;
      }
    }
    cur.erase(0, cut);
    ans += cur;
  }
  cout << ans;
  return 0;
}
