#include <bits/stdc++.h>
using namespace std;
int n;
pair<pair<int, int>, int> x[110];
set<pair<int, int> > st;
int res[110];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    x[i] = pair<pair<int, int>, int>(pair<int, int>(a, b), i);
  }
  sort(x, x + n);
  int last = x[0].first.first;
  int ii = 1;
  st.insert(pair<int, int>(x[0].first.second, x[0].second));
  while (ii < n && x[ii].first.first == x[ii - 1].first.first) {
    st.insert(pair<int, int>(x[ii].first.second, x[ii].second));
    ++ii;
  }
  while (ii < n) {
    int r = x[ii].first.first;
    int m = r - last;
    for (int j = 0; j < m && !st.empty(); ++j) {
      pair<int, int> curr = *(st.begin());
      st.erase(curr);
      res[curr.second] = last++;
    }
    st.insert(pair<int, int>(x[ii].first.second, x[ii].second));
    last = max(last, x[ii].first.first);
    ++ii;
  }
  while (!st.empty()) {
    pair<int, int> curr = *(st.begin());
    st.erase(curr);
    res[curr.second] = last++;
  }
  for (int i = 0; i < n; ++i) printf("%d ", res[i]);
  return 0;
}
