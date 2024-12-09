#include <bits/stdc++.h>
using namespace std;
template <typename A1>
void prn(A1&& arg) {
  cout << arg << '\n';
}
template <typename A1, typename... A>
void prn(A1&& arg, A&&... args) {
  cout << arg << ' ';
  prn(args...);
}
long long dp[][6] = {
    {0, 1, 2, 3, 4, 5}, {0, 2, 3, 4, 1, 5}, {0, 3, 4, 1, 2, 5},
    {0, 4, 1, 2, 3, 5}, {5, 3, 2, 1, 4, 0}, {5, 2, 1, 4, 3, 0},
    {5, 1, 4, 3, 2, 0}, {5, 4, 3, 2, 1, 0}, {1, 2, 0, 4, 5, 3},
    {1, 0, 4, 5, 2, 3}, {1, 4, 5, 2, 0, 3}, {1, 5, 2, 0, 4, 3},
    {3, 4, 0, 2, 5, 1}, {3, 0, 2, 5, 4, 1}, {3, 2, 5, 4, 0, 1},
    {3, 5, 4, 0, 2, 1}, {2, 0, 1, 5, 3, 4}, {2, 1, 5, 3, 0, 4},
    {2, 5, 3, 0, 1, 4}, {2, 3, 0, 1, 5, 4}, {4, 5, 1, 0, 3, 2},
    {4, 1, 0, 3, 5, 2}, {4, 0, 3, 5, 1, 2}, {4, 3, 5, 1, 0, 2},
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, tmp, tmp2;
  cin >> s;
  sort(s.begin(), s.end());
  set<string> q, q2;
  do {
    tmp = s;
    if (!q2.count(tmp)) {
      long long cnt = 0;
      for (long long i = 0; i < 24; i++) {
        for (long long j = 0; j < 6; j++) tmp[j] = s[dp[i][j]];
        if (!q2.count(tmp)) cnt++;
      }
      if (cnt == 24) q.insert(s);
      for (long long i = 0; i < 8; i++) {
        for (long long j = 0; j < 6; j++) tmp[j] = s[dp[i][j]];
        q2.insert(tmp);
      }
    }
  } while (next_permutation(s.begin(), s.end()));
  prn(q.size());
}
