#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
const int M = 1000000007;
const double PI = atan(1) * 4;
const int oo = 1000000000;
int n, d[3], t[8], v[N];
multiset<int> st;
multiset<int>::iterator it;
bool ff;
bool get(int x) {
  it = st.upper_bound(x);
  --it;
  return *st.begin() <= x;
}
void ch(int a, int &x, int &y) {
  if (a <= t[0b100]) --x;
  if (a <= t[0b011]) --y;
  ff = 1;
}
int main() {
  cin >> n;
  for (int i = 0; i < 3; ++i) scanf("%d", &d[i]);
  sort(d, d + 3);
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 3; ++j)
      if (i & (1 << j)) t[i] += d[j];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &v[i]);
    st.insert(v[i]);
  }
  sort(v, v + n);
  int ans = 0;
  if (v[n - 1] > t[0b111]) return cout << -1, 0;
  while (!st.empty() && *st.rbegin() > t[0b110]) {
    st.erase(--st.end());
    ++ans;
  }
  while (!st.empty() && *st.rbegin() > t[0b101]) {
    st.erase(--st.end());
    ++ans;
    if (!st.empty() && get(t[0b001])) st.erase(it);
  }
  while (!st.empty() && *st.rbegin() > max(t[0b100], t[0b011])) {
    st.erase(--st.end());
    ++ans;
    if (!st.empty() && get(t[0b010])) st.erase(it);
  }
  if (st.empty()) return cout << ans << endl, 0;
  int x = 0, y = 0, bst, c = 0;
  for (it = st.begin(); it != st.end(); ++it) {
    if (*it <= t[0b100]) ++x;
    if (*it <= t[0b011]) ++y;
  }
  bst = max((max(x, y) + 1) / 2, abs(x - y));
  while (!st.empty()) {
    ++c;
    ff = 0;
    if (!st.empty() && get(t[0b001])) {
      ch(*it, x, y);
      st.erase(it);
    }
    if (!st.empty() && get(t[0b010])) {
      ch(*it, x, y);
      st.erase(it);
    }
    if (!st.empty() && get(t[0b100])) {
      ch(*it, x, y);
      st.erase(it);
    }
    if (!ff) break;
    bst = min(bst, c + max((max(x, y) + 1) / 2, abs(x - y)));
  }
  cout << ans + bst << endl;
}
