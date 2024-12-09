#include <bits/stdc++.h>
using namespace std;
long long int val(int s, int e, string str) {
  long long int retVal = 0, mul = str[s] - '0';
  for (int i = s; i <= e; ++i) {
    if (str[i] == '*') {
      mul *= str[i + 1] - '0';
    } else if (str[i] == '+') {
      retVal += mul;
      mul = str[i + 1] - '0';
    }
  }
  return retVal + mul;
}
long long int val(string str, int s, int e) {
  long long int retVal = 0, mul = str[0] - '0';
  for (int i = 0; i < str.length(); ++i) {
    if (i + 1 >= s && i <= e) {
      mul *= val(s, e, str);
      i = e + 1;
    }
    if (str[i] == '*') {
      mul *= str[i + 1] - '0';
    } else if (str[i] == '+') {
      retVal += mul;
      mul = str[i + 1] - '0';
    }
  }
  return retVal + mul;
}
int main() {
  if (0) freopen("in.txt", "r", stdin);
  string exp;
  cin >> exp;
  exp = "1*" + exp + "*1";
  vector<int> pos;
  int ls = exp.length();
  for (int i = 0; i < ls; ++i)
    if (exp[i] == '*') pos.push_back(i);
  int len = pos.size();
  long long int res = 0;
  for (int i = 0; i < len; ++i)
    for (int j = i + 1; j < len; ++j)
      res = max(res, val(exp, pos[i] + 1, pos[j] - 1));
  cout << res << endl;
  return 0;
}
