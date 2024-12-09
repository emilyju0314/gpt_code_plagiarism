#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:16000000")
#pragma warning(disable : 4996)
const int inf = 1 << 25;
const double eps = 1e-9;
int dm[] = {-1, 1};
char dir[] = {"LR"};
int main(int argc, char* argv[]) {
  const int MAXN = 1 << 8;
  const int MAXK = 11;
  int N, M, K;
  cin >> N >> M >> K;
  int dp[MAXN][MAXN][MAXK];
  int a[MAXN][MAXN];
  char p[MAXN][MAXN][MAXK];
  memset((a), (0), sizeof(a));
  string s;
  for (int i = (1); i < (N + 1); ++i) {
    cin >> s;
    for (int j = (0); j < ((int)s.size()); ++j)
      a[N - i + 1][j + 1] = s[j] - '0';
  }
  memset((dp), (-1), sizeof(dp));
  for (int m = (1); m < (M + 1); ++m) dp[0][m][0] = 0;
  for (int n = (0); n < (N); ++n)
    for (int m = (1); m < (M + 1); ++m)
      for (int k = (0); k < (K + 1); ++k)
        if (dp[n][m][k] != -1) {
          for (int t = (0); t < (2); ++t) {
            int nm = m + dm[t];
            int nk = (k + a[n + 1][nm]) % (K + 1);
            if (dp[n + 1][nm][nk] < dp[n][m][k] + a[n + 1][nm]) {
              dp[n + 1][nm][nk] = dp[n][m][k] + a[n + 1][nm];
              p[n + 1][nm][nk] = dir[t];
            }
          }
        }
  int mj = -1;
  for (int m = (1); m < (M + 1); ++m)
    if (dp[N][m][0] != -1) {
      if (mj == -1 || dp[N][m][0] > dp[N][mj][0]) mj = m;
    }
  if (mj == -1) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", dp[N][mj][0]);
  string path;
  int k = 0;
  for (int n = N; n > 1; --n) {
    path += p[n][mj][k];
    char c = p[n][mj][k];
    k = k - a[n][mj];
    k %= (K + 1);
    if (k < 0) k += K + 1;
    if (c == 'L')
      ++mj;
    else
      --mj;
  }
  printf("%d\n", mj);
  reverse(path.begin(), path.end());
  cout << path << endl;
  return 0;
}
