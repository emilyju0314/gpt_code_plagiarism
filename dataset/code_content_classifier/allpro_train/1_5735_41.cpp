#include <bits/stdc++.h>
using namespace std;
const signed long long Infinity = 1000000001;
const long double Pi = 2.0L * asinl(1.0L);
const long double Epsilon = 0.000000001;
template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& V) {
  for (typeof(V.begin()) i = V.begin(); i != V.end(); ++i) os << *i << endl;
  return os;
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& S) {
  for (typeof(S.begin()) i = S.begin(); i != S.end(); ++i) os << *i << endl;
  return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& M) {
  for (typeof(M.begin()) i = M.begin(); i != M.end(); ++i) os << *i << endl;
  return os;
}
char P = '$';
string cutDigits(string s) {
  int k = s.find_first_of('.');
  int l = s.size() - k + 1;
  if (k == s.npos)
    return s + ".00";
  else if (k == s.size() - 2)
    return s + "0";
  else
    return s.substr(0, k + 3);
  cout << l;
}
string addComas(string s) {
  string r;
  int k = s.find_first_of('.');
  r = s.substr(k, s.npos);
  int t = 0;
  for (int(i) = (k - 1); (i) >= (1); (i)--) {
    if ((i - k) % 3 == 0) {
      t = 0;
      r = "," + s.substr(i, 3) + r;
    } else
      t++;
  }
  r = s.substr(0, t + 1) + r;
  return r;
}
string result(string s) {
  s = cutDigits(s);
  s = addComas(s);
  return P + s;
}
void solve(string s) {
  if (s[0] == '-')
    cout << "(" << result(s.substr(1)) << ")";
  else
    cout << result(s);
}
int main() {
  string s;
  cin >> s;
  solve(s);
  return 0;
}
