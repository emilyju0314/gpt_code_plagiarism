#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 1e2 + 5;
int n, mask[26], fin = 0, used[N], cyc = 0;
string cur, pre, first;
bool f;
int getbit(int id) { return 1 << id; }
bool checkbit(int cur, int i) { return ((1 << i) & cur); }
bool check(int cur, int i) { return (mask[i] & cur) == mask[i]; }
bool dfs(string& s, int curr = 0) {
  if (curr == (1 << 26) - 1) {
    cur = s;
    return true;
  }
  for (int i = 0; i < 26; i++) {
    if (!checkbit(curr, i))
      if (check(curr + getbit(i), i)) {
        string next = s;
        next += static_cast<char>('a' + i);
        if (dfs(next, curr + getbit(i))) return true;
      }
  }
  return false;
}
void getdependence(string fi, string s) {
  int id = 0;
  while (fi[id] == s[id] && id < fi.size() && id < s.size()) id++;
  if (id == fi.size() || id == s.size()) {
    if (id < fi.size()) f = true;
    return;
  }
  mask[s[id] - 'a'] |= getbit(fi[id] - 'a');
}
int buildmask(int id) {
  used[id] = cyc;
  mask[id] |= getbit(id);
  if (mask[id] == getbit(id)) {
    used[id] = -1;
    return mask[id] = getbit(id);
  }
  for (int i = 0; i < 26; i++)
    if (checkbit(mask[id], i) && i != id) {
      if (!used[i])
        mask[id] |= buildmask(i);
      else if (used[i] == cyc)
        f = true;
      else
        mask[id] |= mask[i];
    }
  used[id] = -1;
  return mask[id];
}
void Solve() {
  cin >> n >> pre;
  n--;
  first = pre;
  while (n--) {
    cin >> cur;
    getdependence(pre, cur);
    pre = cur;
  }
  pre = "";
  for (int i = 0; i < 26; i++)
    if (!used[i]) {
      cyc++;
      buildmask(i);
    }
  if (f) {
    cout << "Impossible";
    return;
  }
  dfs(pre);
  cout << cur;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
