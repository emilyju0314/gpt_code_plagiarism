#include <bits/stdc++.h>
using namespace std;
signed main() {
  array<long long, 6> A;
  for (long long &a : A) cin >> a;
  sort(A.begin(), A.end());
  long long N;
  cin >> N;
  vector<long long> B(N);
  for (long long &b : B) cin >> b;
  set<pair<long long, long long>> st;
  for (long long i = 0; i < N; i++) {
    st.insert({B[i] - A[5], i});
  }
  auto get_length = [&]() -> long long {
    return st.rbegin()->first - st.begin()->first;
  };
  long long ans = get_length();
  vector<long long> which(N, 5);
  while (true) {
    pair<long long, long long> p = *st.begin();
    st.erase(st.begin());
    if (which[p.second] == 0) {
      break;
    }
    which[p.second]--;
    st.insert({B[p.second] - A[which[p.second]], p.second});
    ans = min(ans, get_length());
  }
  cout << ans << '\n';
}
