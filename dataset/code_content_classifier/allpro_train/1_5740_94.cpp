#include <bits/stdc++.h>
using namespace std;
const int MX = 2e6 + 10;
const int mod = 1e9 + 7;
const long long int inf = 1LL << 62;
int dx4[] = {0, 0, -1, 1};
int dy4[] = {1, -1, 0, 0};
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
  };
  long long int n, a, b, cnt = 0, mx = 0, mn = inf;
  string str;
  vector<string> vec;
  while (getline(cin, str)) {
    vec.push_back(str);
  }
  int has = 0;
  for (int i = 0; i < vec.size(); i++) {
    int flg = 0, isAmp = 0;
    for (auto ch : vec[i]) {
      if (ch == '#' && flg == 0) isAmp = 1;
      if (ch != ' ') flg = 1;
    }
    if (isAmp) {
      if (has) cout << endl;
      cout << (vec[i]) << endl;
      has = 0;
      continue;
    }
    has = 1;
    for (auto ch : vec[i]) {
      if (ch == ' ') continue;
      cout << (ch);
    }
  }
  if (has) cout << endl;
  return 0;
}
