#include <bits/stdc++.h>
using namespace std;
int comp[300];
bool ooo = 1;
struct Word {
  int cnt[62][62];
  int res[62][62][62];
  void add(int v, int u) { cnt[v][u]++; }
  void prep() {
    for (int i = 0; i < 62; i++) {
      for (int j = 0; j < 62; j++) {
        for (int l = j; l < 62; l++) {
          for (int k = l; k < 62; k++) {
            res[j][l][k] =
                (res[j][l][k] + 1LL * cnt[i][k] * cnt[i][j] % 998244353 *
                                    cnt[i][l] % 998244353) %
                998244353;
          }
        }
      }
    }
  }
  int count(int i, int j, int l, int k) {
    if (i == k) return 1;
    if (i == l || j == k) return 4;
    if (i == j && l == k) return 6;
    if (i == j || j == l || l == k) return 12;
    return 24;
  }
  int solve() {
    int ans = 0;
    for (int i = 0; i < 62; i++)
      for (int j = i; j < 62; j++)
        for (int l = j; l < 62; l++)
          for (int k = l; k < 62; k++)
            ans = (ans + 1LL * res[i][j][k] * res[i][j][l] % 998244353 *
                             res[i][l][k] % 998244353 * res[j][l][k] %
                             998244353 * count(i, j, l, k) % 998244353) %
                  998244353;
    return ans;
  }
} a[10];
string s;
set<string> slist;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 'a'; i <= 'z'; i++) {
    comp[i] = i - 'a';
  }
  for (int i = 'A'; i <= 'Z'; i++) {
    comp[i] = i - 'A' + 26;
  }
  for (int i = '0'; i <= '9'; i++) comp[i] = i - '0' + 52;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> s;
    t = s.size() - 1;
    if (slist.count(s) == 0) {
      a[t].add(comp[s[0]], comp[s.back()]);
      slist.insert(s);
    }
    reverse(s.begin(), s.end());
    if (slist.count(s) == 0) {
      a[t].add(comp[s[0]], comp[s.back()]);
      slist.insert(s);
    }
  }
  int res = 0;
  for (int i = 2; i < 10; i++) {
    a[i].prep();
    res = (res + a[i].solve()) % 998244353;
  }
  cout << res;
}
