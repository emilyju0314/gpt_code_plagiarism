#include <bits/stdc++.h>
using namespace std;
const int N = int(5e5) + 5;
const int inf = (int)1e9 + 7;
const long long linf = (long long)1e18 + 7;
int n;
string str[N];
map<string, int> cnt, has;
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> str[i];
    has.clear();
    for (int l = 0; l < 9; ++l) {
      string now;
      for (int len = 1; len <= 9 - l; ++len) {
        now += str[i][l + len - 1];
        if (!has[now]) {
          has[now] = 1;
          cnt[now]++;
        }
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    int lene = 12;
    string ans;
    for (int l = 0; l < 9; ++l) {
      string now;
      for (int len = 1; len <= 9 - l; ++len) {
        now += str[i][l + len - 1];
        if (cnt[now] == 1 && (int)now.size() < lene) {
          lene = (int)now.size();
          ans = now;
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
