#include <bits/stdc++.h>
using namespace std;
set<pair<long long, int> > computed;
map<pair<long long, int>, vector<long long> > soln;
long long N;
void input() { cin >> N; }
vector<long long> f(long long cur, int carry) {
  if (computed.find(make_pair(cur, carry)) != computed.end())
    return soln[make_pair(cur, carry)];
  computed.insert(make_pair(cur, carry));
  vector<long long> ret;
  if (cur < carry) {
    soln[make_pair(cur, carry)] = ret;
    return ret;
  }
  if (cur == carry) {
    vector<long long> base;
    for (int i = 0; i < 6; i++) base.push_back(0);
    return soln[make_pair(cur, carry)] = base;
  }
  for (int num7 = 0; num7 <= 6; num7++) {
    for (int num4 = 0; num4 + num7 <= 6; num4++) {
      int addval = num7 * 7 + num4 * 4 + carry;
      if (addval % 10 == cur % 10) {
        vector<long long> rec = f(cur / 10, addval / 10);
        if (rec.size() > 0) {
          for (int i = 0; i < num7; i++) ret.push_back(rec[i] * 10 + 7);
          for (int i = num7; i < num7 + num4; i++)
            ret.push_back(rec[i] * 10 + 4);
          for (int i = num7 + num4; i < 6; i++) ret.push_back(rec[i] * 10);
          return soln[make_pair(cur, carry)] = ret;
        }
      }
    }
  }
  return soln[make_pair(cur, carry)] = ret;
}
void solve() {
  vector<long long> ans = f(N, 0);
  if (ans.size() == 0)
    cout << "-1";
  else
    for (int i = 0; i < 6; i++) cout << ans[i] << " ";
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    input();
    solve();
  }
}
