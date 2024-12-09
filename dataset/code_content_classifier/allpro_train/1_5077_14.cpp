#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int maxn = 200;
double dp[2][15][205];
char a[2][500] = {
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?",
    "What are you doing while sending \"What are you doing at the end of the "
    "world? Are you busy? Will you save us?\"? Are you busy? Will you send "
    "\"What are you doing at the end of the world? Are you busy? Will you save "
    "us?\"?"};
char ans[3][100] = {"What are you doing while sending \"",
                    "\"? Are you busy? Will you send \"", "\"?"};
unsigned long long part1 = strlen(ans[0]);
unsigned long long part2 = strlen(ans[1]);
unsigned long long part3 = strlen(ans[2]);
unsigned long long st0 = strlen(a[0]);
unsigned long long st1 = strlen(a[1]);
unsigned long long f[60];
char dfs(int cur, unsigned long long pos) {
  if (cur == 1) {
    int p = pos;
    if (p <= st1)
      return a[1][p - 1];
    else
      return '.';
  } else {
    if (pos <= part1) {
      return ans[0][pos - 1];
    }
    if (cur > 53)
      return dfs(cur - 1, pos - part1);
    else {
      if (pos > part1 && pos <= part1 + f[cur - 1]) {
        pos = pos - part1;
        return dfs(cur - 1, pos);
      } else if (pos > f[cur - 1] + part1 &&
                 pos <= f[cur - 1] + part1 + part2) {
        pos = pos - (f[cur - 1] + part1);
        return ans[1][pos - 1];
      } else if (pos > f[cur - 1] + part1 + part2 && pos <= f[cur] - part3) {
        pos = pos - (f[cur - 1] + part1 + part2);
        return dfs(cur - 1, pos);
      } else if (pos > 2 * f[cur - 1] + part1 + part2 && pos <= f[cur]) {
        pos = pos - (f[cur] - part3);
        return ans[2][pos - 1];
      } else if (pos > f[cur])
        return '.';
    }
  }
}
int main() {
  int t;
  int n;
  unsigned long long k;
  string s = "";
  scanf("%d", &t);
  f[0] = st0;
  for (int i = 1; i <= 53; i++) {
    f[i] = f[i - 1] * 2ULL + part1 + part2 + part3;
  }
  while (t--) {
    cin >> n >> k;
    if (n == 0) {
      if (k <= st0) {
        int p = k;
        s += a[0][p - 1];
      } else
        s += '.';
    } else
      s += dfs(n, k);
  }
  cout << s << endl;
  return 0;
}
