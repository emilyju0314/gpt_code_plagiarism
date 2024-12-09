#include <bits/stdc++.h>
using namespace std;
struct Hash {
  vector<long long> h, step;
  long long p = 31;
  long long mod = 1e9 + 7;
  void init(const string& s) {
    int n = s.length();
    h.resize(n);
    step.resize(n + 1);
    h[0] = s[0];
    step[0] = 1;
    for (int i = 1; i < n; i++) {
      h[i] = h[i - 1] * p + s[i];
      step[i] = step[i - 1] * p;
      if (step[i] >= mod) step[i] %= mod;
      if (h[i] >= mod) h[i] %= mod;
    }
    step[n] = step[n - 1] * p;
  }
  long long get(int l, int r) {
    long long ret = h[r] - (l ? (h[l - 1] * step[r - l + 1]) % mod : 0);
    if (ret < 0) ret += mod;
    return ret;
  }
};
map<int, string> name;
map<int, int> score;
vector<pair<int, int> > event;
map<int, bool> toevent;
map<int, int> toscore;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int a;
    cin >> a;
    Hash kek;
    kek.init(s);
    name[kek.get(0, s.length() - 1)] = s;
    int lil = kek.get(0, s.length() - 1);
    score[lil] += a;
    event.push_back(make_pair(lil, a));
  }
  int maxx = -1488228;
  for (auto t = score.begin(); t != score.end(); t++) {
    if (t->second > maxx) {
      maxx = t->second;
    }
  }
  for (auto t = score.begin(); t != score.end(); t++) {
    if (t->second == maxx) {
      toevent[t->first] = true;
    }
  }
  for (int i = 0; i < event.size(); i++) {
    int id = event[i].first;
    int sc = event[i].second;
    if (toevent[id]) {
      toscore[id] += sc;
      if (toscore[id] >= maxx) {
        cout << name[id];
        return 0;
      }
    }
  }
}
