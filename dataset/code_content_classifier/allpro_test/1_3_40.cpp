#include <bits/stdc++.h>
using namespace std;
string s;
int ans;
void dfs(int now, int flag, int num) {
  if (now == s.size()) {
    if (num % 25 == 0) {
      ans++;
    }
    return;
  }
  if (s[now] != 'X' && s[now] != '_') {
    dfs(now + 1, flag, num * 10 + s[now] - '0');
  } else if (s[now] == 'X') {
    if (flag != -1)
      dfs(now + 1, flag, num * 10 + flag);
    else {
      int down = 0;
      if (now == 0 && s.size() > 1) down = 1;
      for (int i = down; i <= 9; i++) {
        dfs(now + 1, i, num * 10 + i);
      }
    }
  } else if (s[now] == '_') {
    int down = 0;
    if (now == 0 && s.size() > 1) {
      down = 1;
    }
    for (int i = down; i <= 9; i++) {
      dfs(now + 1, flag, num * 10 + i);
    }
  }
}
int main() {
  cin >> s;
  if (s[0] == '0' && s.size() > 1) {
    cout << 0 << endl;
    return 0;
  } else {
    dfs(0, -1, 0);
    cout << ans << endl;
    return 0;
  }
}
