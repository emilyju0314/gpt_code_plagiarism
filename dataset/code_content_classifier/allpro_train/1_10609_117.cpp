#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int counter = 0;
string GetName(const string &str, int &pos) {
  int start = pos;
  while (str[pos] != '.' && str[pos] != ':') pos++;
  return str.substr(start, pos - start);
}
void parse(const string &str, int &pos, vector<string> &parents) {
  string cur = GetName(str, pos);
  for (auto &s : parents)
    if (cur == s) counter++;
  parents.push_back(cur);
  char c = str[pos++];
  if (c == ':') {
    do {
      parse(str, pos, parents);
    } while ((c = str[pos++]) == ',');
  }
  assert(c == '.');
  parents.pop_back();
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  string str;
  cin >> str;
  int pos = 0;
  vector<string> parents;
  parse(str, pos, parents);
  cout << counter << '\n';
  return 0;
}
