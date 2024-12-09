#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000000000000007;
const int inf = 100000000;
const double eps = 1e-9;
const long long base = 3;
map<long long, int> mmap[600005];
long long powr[600005];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int i, j, k;
  char str[600005];
  powr[0] = 1;
  for (i = 1; i <= 600004; i++) {
    powr[i] = (powr[i - 1] * 3) % mod;
  }
  for (i = 0; i < n; i++) {
    scanf("%s", str);
    int l = strlen(str);
    long long h_value = 0;
    for (j = 0; j < l; j++) {
      h_value = (h_value * base + str[j] - 'a') % mod;
    }
    mmap[l][h_value]++;
  }
  for (i = 0; i < m; i++) {
    scanf("%s", str);
    int l = strlen(str);
    long long h_value = 0;
    for (j = 0; j < l; j++) {
      h_value = (h_value * base + str[j] - 'a') % mod;
    }
    bool flag = 0;
    for (j = 0; j < l; j++) {
      for (k = 0; k < 3; k++) {
        if ((str[j] - 'a') == k) continue;
        long long newhvalue =
            (h_value - (str[j] - 'a') * powr[l - 1 - j]) % mod;
        if (newhvalue < 0) newhvalue = newhvalue + mod;
        newhvalue = (newhvalue + (k)*powr[l - 1 - j]) % mod;
        if (mmap[l].count(newhvalue) == 0) {
        } else {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
