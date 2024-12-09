#include <bits/stdc++.h>
using namespace std;
string str[409];
map<string, int> mapp;
int ans = 0;
void check(string now) {
  string cc = "";
  int si = now.size();
  for (int i = 0; i < si; i++) {
    if (now[i] == 'u') {
      cc += "oo";
    } else {
      cc += now[i];
    }
  }
  string aa = "";
  si = cc.size();
  int fl = 0;
  for (int i = si - 1; i >= 0; i--) {
    if (cc[i] == 'h') {
      fl = 1;
    }
    if (cc[i] == 'k' && fl == 1) {
      continue;
    }
    if (cc[i] != 'h' && cc[i] != 'k') {
      fl = 0;
    }
    aa = cc[i] + aa;
  }
  if (mapp.find(aa) == mapp.end()) {
    ans++;
    mapp[aa] = 1;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
  }
  for (int i = 1; i <= n; i++) {
    check(str[i]);
  }
  cout << ans << endl;
  return 0;
}
