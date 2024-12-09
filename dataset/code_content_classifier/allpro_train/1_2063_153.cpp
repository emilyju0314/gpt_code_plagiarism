#include <bits/stdc++.h>

#ifdef AZN

#include "Azn.cpp"

#else
#define pln(...)
#endif

using namespace std;

typedef long long ll;
typedef double dd;

void solve(ll test_num) {
  (void) test_num;
  int N;
  cin >> N;
  vector<int> arr(N);
  for (int& a : arr) cin >> a;
  int xsum = 0;
  set<int> have;
  for (int a : arr) {
    xsum ^= a;
    have.insert(__builtin_ctz(a));
  }
  int res = 0;
  for (int bit = 30; bit >= 0; --bit) {
    if (xsum >> bit & 1) {
      if (!have.count(bit)) {
        cout << "-1\n";
        return;
      }
      ++res;
      xsum ^= (1 << bit) - 1;
    }
  }
  cout << res << endl;
}

void init() {

}

int main() {
#ifdef AZN
  const auto start_time = chrono::system_clock::now();
  freopen("/home/azneye/Documents/Stuff/input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  ll tests = 1;
  //cin >> tests;
  for (ll test = 1; test <= tests; ++test) {
    solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}