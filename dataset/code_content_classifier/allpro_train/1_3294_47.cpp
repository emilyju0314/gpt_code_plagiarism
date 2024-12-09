#include <bits/stdc++.h>
using namespace std;
int T, N, K;
vector<string> arr;
int usechk[100];
bool cmp(string a, string b) {
  if (a.length() < b.length()) return true;
  return false;
}
vector<char> ans;
bool prepostchk(string ori) {
  ans.clear();
  memset(usechk, 0, sizeof(usechk));
  for (int i = 0; i < arr.size(); i++) {
    int len = arr[i].length();
    if (usechk[len] == 0) {
      if (arr[i].compare(ori.substr(0, len)) == 0) {
        usechk[len] = 1;
        ans.push_back('P');
      } else if (arr[i].compare(ori.substr(N - len, len)) == 0) {
        usechk[len] = 2;
        ans.push_back('S');
      } else
        return false;
    } else if (usechk[len] == 1) {
      if (arr[i].compare(ori.substr(N - len, len)) == 0) {
        usechk[len] = 2;
        ans.push_back('S');
      } else
        return false;
    } else {
      if (arr[i].compare(ori.substr(0, len)) == 0) {
        usechk[len] = 1;
        ans.push_back('P');
      } else
        return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> N;
  string s;
  string longest[2];
  int lcnt = 0;
  for (int i = 0; i < 2 * N - 2; i++) {
    cin >> s;
    arr.push_back(s);
    if (s.length() == N - 1) longest[lcnt++] = s;
  }
  string ori;
  ori = longest[0][0] + longest[1];
  if (prepostchk(ori)) {
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << "\n";
    return 0;
  }
  ori = longest[1] + longest[0][N - 2];
  if (prepostchk(ori)) {
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << "\n";
    return 0;
  }
  ori = longest[1][0] + longest[0];
  if (prepostchk(ori)) {
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << "\n";
    return 0;
  }
  ori = longest[0] + longest[1][N - 2];
  if (prepostchk(ori)) {
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << "\n";
    return 0;
  }
}
