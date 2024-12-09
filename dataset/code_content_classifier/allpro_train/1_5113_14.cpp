#include <bits/stdc++.h>
using namespace std;
bool visited[400005];
vector<long long> v[400005];
long long ans[400005];
long long mod = 998244353;
int main() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long front_same = 0, back_same = 0;
  long long i;
  for (i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1]) {
      front_same = (front_same % mod + 1) % mod;
    } else {
      front_same = (front_same % mod + 1) % mod;
      break;
    }
  }
  for (long long j = s.size() - 1; j > i; j--) {
    if (s[j] == s[j - 1]) {
      back_same = (back_same % mod + 1) % mod;
    } else {
      back_same = (back_same % mod + 1) % mod;
      break;
    }
  }
  if (s[0] != s[s.size() - 1]) {
    long long ans = (front_same % mod + back_same % mod + 1) % mod;
    cout << ans;
    return 0;
  }
  long long a = (front_same % mod + 1) % mod;
  long long b = (back_same % mod + 1) % mod;
  long long ans = (a % mod * b % mod) % mod;
  cout << ans;
  return 0;
}
