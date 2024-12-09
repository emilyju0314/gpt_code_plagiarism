#include <bits/stdc++.h>
using namespace std;
map<string, int> Query(int left, int right) {
  cout << "? " << left << " " << right << "\n";
  cout.flush();
  int len = right - left + 1;
  int to_read = 1LL * len * (len + 1) / 2;
  map<string, int> count;
  for (int i = 0; i < to_read; i += 1) {
    string str;
    getline(cin, str);
    sort(str.begin(), str.end());
    count[str] += 1;
  }
  return count;
}
char Different(const string &prev, const string &curr) {
  for (size_t i = 0; i < curr.size(); i += 1) {
    if (prev[i] != curr[i]) {
      return prev[i];
    }
  }
  return prev.back();
}
string Rebuild(vector<string> &suffixes) {
  sort(suffixes.begin(), suffixes.end(),
       [](const string &a, const string &b) { return a.size() > b.size(); });
  string res = "";
  for (size_t i = 1; i < suffixes.size(); i += 1) {
    res.push_back(Different(suffixes[i - 1], suffixes[i]));
  }
  res.push_back(suffixes.back().back());
  return res;
}
string Solve(int len) {
  if (len == 1) {
    return Query(1, 1).begin()->first;
  }
  auto full = Query(1, len);
  auto prefix = Query(1, len - 1);
  vector<string> suffixes;
  for (const auto &p : full) {
    if (prefix[p.first] < p.second) {
      suffixes.push_back(p.first);
    }
  }
  return Rebuild(suffixes);
}
void Answer(const string &str) {
  cout << "! " << str << "\n";
  cout.flush();
}
int main() {
  int len;
  cin >> len;
  cin.get();
  auto res = Solve(len);
  Answer(res);
  return 0;
}
