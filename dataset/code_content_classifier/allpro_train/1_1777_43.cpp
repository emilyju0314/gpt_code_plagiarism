#include <bits/stdc++.h>
using namespace std;
ifstream in("task.in");
ofstream out("task.out");
vector<int> kmp(const string& s) {
  vector<int> ans(s.size(), 0);
  for (int i = 1; i < s.size(); ++i) {
    int cur = ans[i - 1];
    while (cur > 0 && s[cur] != s[i]) cur = ans[cur - 1];
    if (s[cur] == s[i]) ++cur;
    ans[i] = cur;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  --n;
  string s, t;
  cin >> s >> t;
  string x = "";
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] == 'N')
      x.push_back('S');
    else if (s[i] == 'S')
      x.push_back('N');
    else if (s[i] == 'W')
      x.push_back('E');
    else
      x.push_back('W');
  }
  x.push_back('#');
  x += t;
  if (kmp(x).back())
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
