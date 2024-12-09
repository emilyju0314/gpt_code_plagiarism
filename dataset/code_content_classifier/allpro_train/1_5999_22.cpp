#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string s;
int x = 0, cnt = 0;
bool mark = true, m = true;
void solve() {
  if (x == v.size()) {
    return;
  }
  if (x < v.size()) {
    s += v[x];
    cnt++;
    if (v[x] == "pair") {
      s += '<';
      x++;
      solve();
      s += ',';
      x++;
      solve();
      s += '>';
    }
  }
  return;
}
int main() {
  int n;
  cin >> n;
  string str;
  cin.ignore();
  getline(cin, str);
  int i = 0;
  while (i < str.size()) {
    string temp;
    while (str[i] != ' ' && i < str.size()) {
      temp += str[i];
      i++;
    }
    v.push_back(temp);
    i++;
  }
  solve();
  if ((n > 1 && s.substr(0, 3) == "int") || cnt < v.size()) {
    cout << "Error occurred" << endl;
    return 0;
  }
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == '<') {
      if (s[i + 1] == '<' || s[i + 1] == '>' || s[i + 1] == ',') {
        cout << "Error occurred" << endl;
        return 0;
      }
    }
    if (s[i] == ',') {
      if (s[i + 1] == '>' || s[i + 1] == ',') {
        cout << "Error occurred" << endl;
        return 0;
      }
    }
    if (s[i] == '>') {
      if (s[i + 1] == '<') {
        cout << "Error occurred" << endl;
        return 0;
      }
    }
  }
  cout << s << endl;
  return 0;
}
