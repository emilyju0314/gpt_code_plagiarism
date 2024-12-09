#include <bits/stdc++.h>
using namespace std;
int n, ans, m, a;
vector<int> zero, first, second;
int main() {
  cin >> n;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s >> a;
    if (s == "00")
      zero.push_back(a);
    else if (s == "10")
      first.push_back(a);
    else if (s == "01")
      second.push_back(a);
    else {
      m++;
      ans += a;
    }
  }
  if (first.size() > second.size()) swap(first, second);
  sort(first.rbegin(), first.rend());
  sort(second.rbegin(), second.rend());
  for (int i = 0; i < first.size(); ++i) ans += first[i] + second[i];
  for (int i = first.size(); i < second.size(); ++i) zero.push_back(second[i]);
  sort(zero.rbegin(), zero.rend());
  a = m + first.size();
  m += 2 * first.size();
  for (int i = 0; i < zero.size(); ++i, ++m) {
    if (2 * a < m + 1) break;
    ans += zero[i];
  }
  cout << ans << endl;
  return 0;
}
