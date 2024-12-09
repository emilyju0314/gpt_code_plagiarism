#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
const int INF = (int)1E9 + 7;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int NMAX = 2010;
int n;
char s[NMAX][NMAX], ts[NMAX][NMAX];
int a[NMAX], r[NMAX], c[NMAX], tr[NMAX], tc[NMAX];
void rot(char s[NMAX][NMAX]) {
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(n); ++j) ts[n - 1 - j][i] = s[i][j];
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(n); ++j) s[i][j] = ts[i][j];
}
int solve(char s[NMAX][NMAX], int r[NMAX], int c[NMAX]) {
  memset(r, 0, sizeof(int) * NMAX);
  memset(c, 0, sizeof(int) * NMAX);
  vector<pair<int, int> > q;
  int ans = 0;
  for (int j = int(n) - 1; j >= 0; --j) {
    if (j == 0) break;
    int ci = 0, cj = j;
    vector<pair<int, int> > q;
    while (cj < n) {
      int col = s[ci][cj] ^ r[ci] ^ c[cj];
      if (col == 1) {
        ans++;
        q.push_back(make_pair(ci, cj));
      }
      cj++, ci++;
    }
    for (int i = 0; i < int(int((q).size())); ++i)
      r[q[i].first] ^= 1, c[q[i].second] ^= 1;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  gets(s[0]);
  for (int i = 0; i < int(n); ++i) {
    gets(s[i]);
    for (int j = 0; j < int(n); ++j) s[i][j] -= '0';
  }
  int ans = solve(s, r, c);
  rot(s), rot(s);
  ans += solve(s, tr, tc);
  rot(s), rot(s);
  for (int i = 0; i < int(n); ++i)
    ans += int((s[i][i] ^ tr[n - i - 1] ^ tc[n - i - 1] ^ r[i] ^ c[i]) == 1);
  cout << ans << endl;
  return 0;
}
