#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
int main() {
  int i, n;
  scanf("%d", &n);
  vector<int> v(n);
  for (i = 0; i < n; i++) scanf("%d", &v[i]);
  multiset<int> st;
  multiset<int>::iterator itr;
  long long int ans = 0;
  for (i = n - 1; i >= 0; i--) {
    if (v[i] < 0) break;
    st.insert(v[i]);
    if ((i & (i + 1)) == 0) {
      itr = st.begin();
      ans += (*itr);
      st.erase(itr);
    }
  }
  cout << ans << "\n";
}
