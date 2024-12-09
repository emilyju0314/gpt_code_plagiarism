#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e5 + 10;
long long n, dis[27][27], ans = 0;
string s1, s2, ans_s;
int main() {
  cin >> s1 >> s2 >> n;
  for (long long i = 0; i < 26; ++i)
    for (long long j = 0; j < 26; ++j) dis[i][j] = 0x7ffffffff;
  for (long long i = 1; i <= n; ++i) {
    char a, b;
    long long v;
    cin >> a >> b >> v;
    dis[a - 'a'][b - 'a'] = min(v, dis[a - 'a'][b - 'a']);
  }
  for (long long i = 0; i < 26; ++i) dis[i][i] = 0;
  for (long long k = 0; k < 26; ++k)
    for (long long i = 0; i < 26; ++i)
      for (long long j = 0; j < 26; ++j)
        if (dis[i][j] > dis[i][k] + dis[k][j])
          dis[i][j] = dis[i][k] + dis[k][j];
  long long len1 = s1.length(), len2 = s2.length();
  if (len2 != len1) {
    cout << "-1";
    return 0;
  }
  for (long long i = 0; i < len1; ++i) {
    if (s1[i] != s2[i]) {
      long long tmp = 0x7fffffff, x = -1;
      for (long long c = 0; c < 26; ++c) {
        if (dis[s1[i] - 'a'][c] == 0x7fffffff ||
            dis[s2[i] - 'a'][c] == 0x7fffffff)
          continue;
        if (dis[s1[i] - 'a'][c] + dis[s2[i] - 'a'][c] < tmp) {
          tmp = dis[s1[i] - 'a'][c] + dis[s2[i] - 'a'][c];
          x = c;
        }
      }
      if (x == -1) {
        cout << "-1";
        return 0;
      }
      ans += tmp;
      ans_s += char(x + 'a');
    } else
      ans_s += s1[i];
  }
  cout << ans << endl << ans_s;
  return 0;
}
