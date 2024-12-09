#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char G[N][N];
long long S[N][N];
long long F[N][N];
long long area(int x1, int y1, int x2, int y2) {
  return S[x2][y2] - S[x2][y1 - 1] - S[x1 - 1][y2] + S[x1 - 1][y1 - 1];
}
vector<pair<pair<int, int>, int> > ANS;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> G[i][j];
      if (G[i][j] == '*') S[i][j] = 1;
      S[i][j] += S[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      S[i][j] += S[i - 1][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (G[i][j] == '.') continue;
      int la = 1, ra = min(min(i, n + 1 - i), min(j, m + 1 - j));
      while (la < ra) {
        int mid = (la + ra) >> 1;
        if (area(i - mid, j, i + mid, j) + area(i, j - mid, i, j + mid) - 1 ==
            mid * 4 + 1) {
          la = mid + 1;
        } else
          ra = mid;
      }
      if (la == 1) continue;
      la--;
      F[i - la][j]++, F[i - la][j + 1]--;
      F[i + la + 1][j]--, F[i + la + 1][j + 1]++;
      F[i][j - la]++, F[i][j + la + 1]--;
      F[i + 1][j - la]--, F[i + 1][j + la + 1]++;
      ANS.push_back(make_pair(make_pair(i, j), la));
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      F[i][j] += F[i][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      F[i][j] += F[i - 1][j];
      if ((F[i][j] == 0 and G[i][j] == '*') or
          (F[i][j] != 0 and G[i][j] == '.')) {
        cout << "-1\n";
        exit(0);
      }
    }
  }
  cout << ANS.size() << "\n";
  for (auto it : ANS) {
    cout << it.first.first << " " << it.first.second << " " << it.second
         << "\n";
  }
  return 0;
}
