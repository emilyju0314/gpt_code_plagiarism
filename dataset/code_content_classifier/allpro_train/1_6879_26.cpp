#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, x1, x2, sum[5000005];
string s;
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  cin >> n >> k;
  cin >> s;
  vector<int> Z = z_function(s);
  for (i = 1; i <= n / k; i++) {
    for (j = 0; j <= (k - 1) * i; j += i)
      if (j != 0 && Z[j] < i) break;
    if (j <= (k - 1) * i) continue;
    x1 = i * k - 1;
    x2 = x1 + min(Z[x1 + 1], i);
    x2 = min(x2, n) + 1;
    sum[x1]++;
    sum[x2]--;
  }
  for (i = 0; i < n; i++) {
    if (i != 0) sum[i] += sum[i - 1];
    cout << (bool)(sum[i]);
  }
}
