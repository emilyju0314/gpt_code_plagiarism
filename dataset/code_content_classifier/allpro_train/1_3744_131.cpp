#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd64(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long power(long long a, long long m, long long mod) {
  long long ans = 1;
  while (m) {
    if (m % 2) ans *= a, ans %= (mod);
    a = (a * a) % (mod);
    m >>= 1;
  }
  return ans;
}
void init(long long* a, long long n, long long val) {
  for (long long i = 0; i < n; i++) a[i] = val;
}
multiset<pair<long long, long long> > st, st2;
long long ans, tot, tot2;
long long func() {
  while (st2.size() > tot) {
    auto it = st2.begin();
    st.insert(*it);
    ans -= (*it).first;
    tot2 -= (*it).second;
    st2.erase(it);
  }
  while (st.size() && st2.size() < tot) {
    auto it = st.end();
    --it;
    ans += (*it).first;
    tot2 += (*it).second;
    st2.insert(*it);
    st.erase(it);
  }
  while (st.size() && st2.size()) {
    auto it = st.end();
    --it;
    auto it2 = st2.begin();
    if ((*it2).first > (*it).first) break;
    ans -= (*it2).first;
    ans += (*it).first;
    tot2 -= (*it2).second;
    tot2 += (*it).second;
    st2.insert(*it);
    st.erase(it);
    st.insert(*it2);
    st2.erase(it2);
  }
  long long ans2 = ans;
  if (tot && tot == tot2) {
    if (st2.size()) ans2 -= (*st2.begin()).first;
    if (st.size()) {
      auto it = st.end();
      --it;
      ans2 += (*it).first;
    }
  }
  return ans2;
}
void solve() {
  long long i, j, _, t, k;
  cin >> t >> k;
  if (t) {
    if (k > 0) {
      st.insert({k, 1});
      tot++;
      ans += k;
    } else {
      tot--;
      k = -k;
      if (st.find({k, 1}) != st.end())
        st.erase({k, 1}), ans -= k;
      else
        st2.erase({k, 1}), tot2--, ans -= 2 * k;
    }
  } else {
    if (k > 0) {
      st.insert({k, 0});
      ans += k;
    } else {
      k = -k;
      if (st.find({k, 0}) != st.end())
        st.erase({k, 0}), ans -= k;
      else
        st2.erase({k, 0}), ans -= 2 * k;
    }
  }
  cout << func() << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
