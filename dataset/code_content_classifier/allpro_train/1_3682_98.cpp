#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
typename T::value_type arr_sum(const T& v, int n) {
  typename T::value_type sum = 0;
  for (int i = (0); i < (n); ++i) sum += v[i];
  return sum;
}
struct Sync_stdio {
  Sync_stdio() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
  }
} _sync_stdio;
struct Z {
  int a;
  int b;
  int c;
};
int main() {
  int n;
  cin >> n;
  vector<Z> v(4 * n);
  for (int i = (0); i < (4 * n); ++i) {
    cin >> v[i].a >> v[i].b >> v[i].c;
    --v[i].a;
    --v[i].b;
    --v[i].c;
  }
  vector<vector<int>> rules(n);
  for (int i = (0); i < (4 * n); ++i) {
    rules[v[i].b].push_back(i);
    rules[v[i].c].push_back(i);
  }
  vector<int> cnt(n, 8);
  vector<int> ans;
  vector<int> used(4 * n);
  int j = 0;
  for (int i = (0); i < (4 * n); ++i) {
    while (j < rules.size() && rules[j].empty()) {
      ++j;
    }
    while (j < rules.size() && used[rules[j].back()]) {
      rules[j].pop_back();
      while (j < rules.size() && rules[j].empty()) {
        ++j;
      }
    }
    int j2 = j;
    while (i < 4 * n) {
      while (j2 < rules.size() && used[rules[j2].back()]) {
        rules[j2].pop_back();
        while (j2 < rules.size() && rules[j2].empty()) {
          ++j2;
        }
      }
      ++cnt[v[rules[j2].back()].a];
      --cnt[v[rules[j2].back()].b];
      --cnt[v[rules[j2].back()].c];
      int idx = rules[j2].back();
      rules[j2].pop_back();
      int t = cnt[v[idx].a];
      used[idx] = 1;
      ans.push_back(idx + 1);
      j2 = v[idx].a;
      if (t != 9) {
        break;
      }
      ++i;
    }
  }
  reverse(ans.begin(), ans.end());
  cout << "YES"
       << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
}
