#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1000010;
vector<int> find_primes(const int n) {
  vector<int> rez(n, 0);
  vector<bool> buf(n + 1, true);
  for (int i = 2; i < n; ++i) {
    if (buf[i]) {
      rez[i] = i;
      rez.push_back(i);
      for (int j = 2 * i; j < n; j += i) {
        rez[j] = i;
        buf[j] = false;
      }
    }
  }
  return rez;
}
int main() {
  ios_base ::sync_with_stdio(false);
  int n = 0, k = 0;
  cin >> n >> k;
  map<int, int> mp;
  vector<int> pr = find_primes(1000 * 1000 + 10);
  for (int i = 0, val; i < n; ++i) {
    int x;
    cin >> x;
    while (x > 1) {
      const int tmp = pr[x];
      int cur = 0;
      do {
        ++cur, x /= tmp;
      } while (x % tmp == 0);
      mp[tmp] = max(mp[tmp], cur);
    }
  }
  bool rez = true;
  int x = k;
  while (x > 1) {
    const int tmp = pr[x];
    int cur = 0;
    do {
      ++cur, x /= tmp;
    } while (x % tmp == 0);
    rez = (rez && cur <= mp[tmp]);
  }
  cout << (rez ? "Yes" : "No") << endl;
  return 0;
}
