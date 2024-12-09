#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  size_t _jyz_ = s.find("Q");
  if (_jyz_ == string::npos) return puts("Yes"), 0;
  _jyz_ /= 2;
  int jyz = count(s.begin(), s.end(), 'Q'), _jyz = sqrt(jyz),
      jyz_ = (s.size() - jyz) / (_jyz + 1);
  string a = s.substr(_jyz_, jyz_ + _jyz), t;
  for (int i = 0; i < int(a.size()); i++)
    if (a[i] == 'H')
      t += "H";
    else
      t += a;
  puts(s == t ? "Yes" : "No");
  return 0;
  ;
}
