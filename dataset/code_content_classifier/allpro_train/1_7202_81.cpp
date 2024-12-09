#include <bits/stdc++.h>
using namespace std;
int static fast = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();
int main() {
  string s;
  cin >> s;
  unordered_map<char, vector<int>> cnt;
  long long ans = 0;
  for (int i = 0; i < s.size(); i++) {
    cnt[s[i]].push_back(i);
  }
  for (int i = 0; i < 26; i++) {
    long long sz = cnt['a' + i].size();
    ans = max(ans, sz);
  }
  for (int i = 0; i < 26; i++) {
    char pre = 'a' + i;
    for (int j = 0; j < 26; j++) {
      char post = 'a' + j;
      long long tmp = 0;
      if (pre == post) {
        long long sz = cnt['a' + i].size();
        ans = max(ans, sz * (sz - 1) / 2);
        continue;
      }
      for (int pre_pos : cnt[pre]) {
        auto& vec = cnt[post];
        auto it = upper_bound(vec.begin(), vec.end(), pre_pos);
        tmp += vec.end() - it;
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}
