#include <bits/stdc++.h>
using namespace std;
vector<string> split(const string &str, const string &delim = " ") {
  int start = 0;
  vector<string> result;
  for (int pos; (pos = str.find_first_of(delim, start)) != (int)string::npos;
       start = pos + 1) {
    result.push_back(str.substr(start, pos - start));
  }
  result.push_back(str.substr(start));
  result.erase(
      remove_if(result.begin(), result.end(), not1(mem_fun_ref(&string::size))),
      result.end());
  return result;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string init, remain;
  cin >> init >> remain;
  vector<string> strs = split(init, "|");
  if (init[0] == '|') strs.insert(strs.begin(), string());
  if (init.back() == '|') strs.push_back(string());
  for (auto &c : remain) {
    (strs[0].size() < strs[1].size() ? strs[0] : strs[1]) += c;
  }
  if (strs[0].size() != strs[1].size()) {
    cout << "Impossible" << endl;
  } else {
    cout << strs[0] << '|' << strs[1] << endl;
  }
  return 0;
}
