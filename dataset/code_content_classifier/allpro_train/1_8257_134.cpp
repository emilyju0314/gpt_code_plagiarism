#include <bits/stdc++.h>
using namespace std;
template <typename T, typename TT>
ostream& operator<<(ostream& os, const pair<T, TT>& t) {
  return os << t.first << " " << t.second;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& t) {
  for (auto& i : t) os << i << " ";
  return os;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
long long com(long long n, long long m) {
  long long ans = 1;
  m = max(m, n - m);
  for (int i = (1); i <= (n - m); i++) {
    ans = (ans * (m + i)) / i;
  }
  return ans;
}
set<long long> v;
void rec(long long n, long long i, long long j, long long a) {
  if (n == 0) {
    v.insert(a);
    return;
  }
  rec(n - 1, i, j, a * 10 + i);
  rec(n - 1, i, j, a * 10 + j);
  return;
}
int main() {
  for (int n = (1); n <= (9); n++) {
    for (int i = (0); i <= (9); i++) {
      for (int j = (i + 1); j <= (9); j++) {
        if (i == 0) {
          rec(n - 1, i, j, j);
        } else
          rec(n, i, j, 0);
      }
    }
  }
  v.insert(1000000000);
  long long m;
  scanf("%lld", &m);
  long long i = 0;
  for (auto it : v) {
    if (it > m) {
      break;
    }
    i++;
  }
  cout << i;
  return 0;
}
