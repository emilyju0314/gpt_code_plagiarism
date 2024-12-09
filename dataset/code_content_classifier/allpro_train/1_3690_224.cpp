#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::max;
using std::min_element;
using std::pair;
using std::string;
using std::unordered_map;
int main() {
  int n;
  cin >> n;
  string a;
  cin >> a;
  unordered_map<char, int> counts;
  for (int i = 0; i < n; ++i) ++counts[a[i]];
  int maxCount = 0;
  for (int i = 0; i < 4; ++i) {
    maxCount = max(maxCount, counts["ACGT"[i]]);
  }
  int undecided = counts['?'];
  int holes = maxCount * 4 - (n - undecided);
  if (undecided < holes || (undecided - holes) % 4 > 0) {
    cout << "===" << endl;
    return 0;
  }
  counts.erase('?');
  for (int i = 0; i < n; ++i) {
    if (a[i] == '?') {
      auto p = min_element(counts.begin(), counts.end(),
                           [](pair<char, int> p1, pair<char, int> p2) {
                             return p1.second < p2.second;
                           });
      a[i] = p->first;
      ++p->second;
    }
  }
  cout << a << endl;
}
