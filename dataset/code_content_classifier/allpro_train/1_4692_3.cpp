#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1002;
const long long INF = 1e18;
char word[MAXN];
int m_idx[MAXN], n, m;
long long k;
string pal;
void preprocess() {
  for (int i = 0; i < n; i++) {
    int j = i, k = 0;
    while (k < pal.size() && j < n && word[j] == pal[k]) {
      k++, j++;
    }
    if (k == pal.size()) {
      m_idx[i] = j - 1;
    } else if (j >= n || word[j] < pal[k]) {
      m_idx[i] = -1;
    } else {
      m_idx[i] = j;
    }
  }
}
long long dp[MAXN][MAXN];
long long solve() {
  preprocess();
  memset(dp, 0, sizeof dp);
  long long res = 0;
  dp[n][0] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= m; j++) {
      if (j && m_idx[i] != -1) dp[i][j] = dp[m_idx[i] + 1][j - 1];
      if (i) dp[i][j] += dp[i + 1][j];
      if (dp[i][j] > INF) dp[i][j] = INF;
    }
  }
  return dp[0][m];
}
int main() {
  scanf("%d%d%lld", &n, &m, &k);
  scanf("%s", word);
  vector<string> words;
  for (int i = 0; i < n; i++) {
    string w = "";
    for (int j = i; j < n; j++) {
      w += word[j];
      words.emplace_back(w);
    }
  }
  unique(words.begin(), words.end());
  sort(words.rbegin(), words.rend());
  int l = 0, r = words.size() - 1;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    pal = words[mid];
    long long res = solve();
    if (res >= k) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  cout << words[ans] << endl;
  return 0;
}
