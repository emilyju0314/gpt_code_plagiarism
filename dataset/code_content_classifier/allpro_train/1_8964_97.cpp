#include <bits/stdc++.h>
using namespace std;
const int MOD1 = (int)1e9 + 7;
const int MOD2 = (int)1e9 + 9;
const int P = 257;
char buf[100500];
string scan_token() {
  scanf("%s", buf);
  return string(buf);
}
pair<int, int> get_hash(const string &s) {
  pair<int, int> h;
  for (char c : s) {
    h.first = ((long long)h.first * P + (int)c) % MOD1;
    h.second = ((long long)h.second * P + (int)c) % MOD2;
  }
  return h;
}
map<string, vector<string>> paths;
map<pair<int, int>, vector<string>> groups;
void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    string addr = scan_token();
    int pos = addr.find('/', 7);
    if (pos == -1) pos = (int)addr.length();
    string host = addr.substr(0, pos);
    string path = addr.substr(pos);
    paths[host].push_back(path);
  }
  for (auto e : paths) {
    string host = e.first;
    auto &vec = e.second;
    sort(vec.begin(), vec.end());
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    string id = "";
    for (string s : vec) id += s + ";";
    groups[get_hash(id)].push_back(host);
  }
  int cnt = 0;
  for (auto e : groups)
    if ((int)e.second.size() > 1) cnt++;
  printf("%d\n", cnt);
  for (auto e : groups) {
    if ((int)e.second.size() == 1) continue;
    for (string s : e.second) printf("%s ", s.c_str());
    printf("\n");
  }
}
int main() {
  solve();
  0;
  return 0;
}
