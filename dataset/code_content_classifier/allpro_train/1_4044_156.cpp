#include <bits/stdc++.h>
using namespace std;
long long int n, k;
string str[400007];
long long int a[400007], p[400007];
long long int m1[200005], m2[200005];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> str[i];
  long long int reg = 0;
  for (int i = 0; i < n; i++) {
    stack<char> s;
    for (int j = 0; j < str[i].length(); j++) {
      if (j == 0)
        s.push(str[i][j]);
      else {
        if (!s.empty()) {
          if (str[i][j] == ')' && s.top() == '(')
            s.pop();
          else
            s.push(str[i][j]);
        } else
          s.push(str[i][j]);
      }
    }
    int fo = 0, fi = 0, po = 0;
    if (s.empty()) {
      reg++;
      continue;
    }
    string tmp;
    while (!s.empty()) {
      if (s.top() == ')') {
        fo = 1;
        tmp += '(';
      } else {
        fi = 1;
        tmp += ')';
      }
      if (fo == 1 && fi == 1) {
        po = 1;
        break;
      }
      s.pop();
    }
    if (po == 0) {
      if (fo == 1) {
        m1[tmp.length()]++;
        p[i] = 1;
      } else {
        m2[tmp.length()]++;
        p[i] = 2;
      }
      a[i] = tmp.length();
    }
  }
  long long int tt = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] == 0) continue;
    if (p[i] == 1) {
      if (m2[a[i]] > 0) {
        tt += m2[a[i]];
      }
      m1[a[i]]--;
    } else {
      if (m1[a[i]] > 0) {
        tt += m1[a[i]];
      }
      m2[a[i]]--;
    }
  }
  tt += reg * reg;
  cout << tt;
}
