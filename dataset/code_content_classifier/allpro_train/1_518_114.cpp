#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
char s[100010];
long long solve() {
  int n = strlen(s);
  vector<long long> v;
  long long pa = 0;
  s[n] = 'b';
  for (int i = 0; i <= n; ++i) {
    if (s[i] == 'a') {
      pa++;
    } else if (s[i] == 'b') {
      if (pa) v.push_back(pa);
      pa = 0;
    }
  }
  if (v.empty()) return 0;
  long long ans = v[0];
  for (int i = 1; i < v.size(); ++i)
    ans = (ans + ((ans + 1) * v[i]) % MOD) % MOD;
  return ans;
}
int main() {
  scanf("%s", s);
  printf("%I64d", solve());
  return 0;
}
