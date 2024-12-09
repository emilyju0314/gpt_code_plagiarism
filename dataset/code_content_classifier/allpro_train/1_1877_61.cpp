#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 59100;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
string s, t, ans;
int n, cnt[11], vis[11];
bool work(int pos, int c) {
  vector<int> v;
  for (int i = 0; i < 10; i++)
    if (vis[i] & 1) v.push_back(i);
  if (v.size() > n - pos) return false;
  sort(v.rbegin(), v.rend());
  int up = n - pos - v.size();
  for (int i = 1; i <= up; i++) t[pos++] = '9';
  for (int i : v) t[pos++] = i + '0';
  return true;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    cin >> s;
    t = s;
    n = s.size();
    for (int i = 0; i < n; i++) {
      if (i == 0 || i == n - 1)
        t[i] = '1';
      else
        t[i] = '0';
    }
    if (s <= t) {
      for (int i = 1; i <= n - 2; i++) printf("9");
      puts("");
    } else {
      for (int i = 0; i < n; i++) cnt[s[i] - '0']++, t[i] = s[i];
      for (int i = n - 1; i >= 0; i--) {
        cnt[s[i] - '0']--;
        for (int j = 0; j < 10; j++) vis[j] = cnt[j];
        for (int c = s[i] - '0' - 1; c >= 0; c--) {
          vis[c]++;
          t[i] = c + '0';
          if (work(i + 1, c)) {
            ans = t;
            i = -1;
            break;
          }
          vis[c]--;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
