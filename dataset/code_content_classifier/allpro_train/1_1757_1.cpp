#include <bits/stdc++.h>
long long int power(long long int x, unsigned long long int y,
                    long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m;
  cin >> n >> m;
  string s[n];
  for (long long int i = 0; i < n; i++) cin >> s[i];
  long long int ans = 1;
  long long int freq[26];
  for (long long int i = 0; i < m; i++) {
    long long int c = 0;
    for (long long int j = 0; j < 26; j++) freq[j] = 0;
    for (long long int j = 0; j < n; j++) freq[s[j][i] - 'A']++;
    for (long long int j = 0; j < 26; j++)
      if (freq[j] > 0) c++;
    ans = (ans * c) % 1000000007;
  }
  cout << ans << '\n';
}
