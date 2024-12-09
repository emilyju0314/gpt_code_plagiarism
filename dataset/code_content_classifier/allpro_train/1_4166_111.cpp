#include <bits/stdc++.h>
using namespace std;
const int N = 2010000;
const int mod = 998244353;
int pos[N], pre[N], nt[N], v[N];
string s;
string sol(char x) {
  memset(v, 0, sizeof(v));
  int pos1 = 0, pos2 = s.size() - 1;
  while (pos1 + 1 < pos2) {
    if (s[pos1] == x) {
      pos1++;
      continue;
    }
    if (s[pos2] == x) {
      pos2--;
      continue;
    }
    if (s[pos1] == s[pos2]) {
      v[pos1] = 1;
      v[pos2] = 1;
      pos1++;
      pos2--;
    } else {
      int pp1 = nt[pos1];
      int pp2 = pre[pos2];
      if (pp1 > pos2) {
        pos1++;
      } else if (pp2 < pos1) {
        pos2--;
      } else {
        if (pp1 - pos1 > pos2 - pp2) {
          pos2--;
        } else {
          pos1++;
        }
      }
    }
  }
  if (pos1 <= pos2) {
    v[pos1] = 1;
  }
  string ans;
  for (int i = 0; i < s.size(); ++i) {
    if (v[i]) ans += s[i];
  }
  return ans;
}
int num[10];
int main() {
  cin >> s;
  memset(pos, -1, sizeof(pos));
  memset(num, 0, sizeof(num));
  for (int i = 0; i < s.size(); ++i) {
    int t = s[i] - 'a';
    pre[i] = pos[t];
    pos[t] = i;
    num[t]++;
  }
  string ans;
  for (int i = 0; i < 3; ++i) {
    if ((num[i] / 2 * 2) + 1 >= s.size() / 2) {
      int t = num[i];
      if (t % 2) t--;
      for (int j = 0; j < s.size(); ++j) {
        if (ans.size() == t / 2) {
          ans += s[j];
        } else {
          if (s[j] == i + 'a') ans += s[j];
        }
        if (ans.size() == t + 1) break;
      }
      break;
    }
  }
  if (ans.size() == 0) {
    memset(pos, -1, sizeof(pos));
    for (int i = s.size() - 1; i >= 0; --i) {
      int t = s[i] - 'a';
      nt[i] = pos[t];
      pos[t] = i;
    }
    for (int i = 0; i < 4; ++i) {
      string ret = sol(i + 'a');
      if (ret.size() >= s.size() / 2) {
        ans = ret;
        break;
      }
    }
  }
  if (ans.size() >= s.size() / 2) {
    cout << ans << endl;
  } else {
    printf("IMPOSSIBLE\n");
  }
}
