#include <bits/stdc++.h>
std::ostream& out = std::cout;
std::istream& in = std::cin;
int main() {
  std::string s, a, b;
  in >> s;
  a.reserve(s.size() + 2u);
  b.reserve(s.size() + 2u);
  for (size_t i = 0; i < s.size() + 1u;) {
    bool isNum = i < s.size() && s[i] != ';' && s[i] != ',' &&
                 ('1' <= s[i] && s[i] <= '9' ||
                  s[i] == '0' && (i + 1 == s.size() || s[i + 1] == ',' ||
                                  s[i + 1] == ';'));
    size_t j = i;
    for (; j < s.size() && s[j] != ';' && s[j] != ','; ++j)
      if (isNum) isNum = '0' <= s[j] && s[j] <= '9';
    if (isNum) {
      if (a.empty())
        a += '\"';
      else
        a += ',';
      a.append(s.data() + i, j - i);
    } else {
      if (b.empty())
        b += '\"';
      else
        b += ',';
      b.append(s.data() + i, j - i);
    }
    i = j + 1;
  }
  if (a.empty())
    out << "-\n";
  else
    out << a << "\"\n";
  if (b.empty())
    out << "-\n";
  else
    out << b << "\"\n";
}
