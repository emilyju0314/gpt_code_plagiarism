#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const long long INF = 1LL << 62;
const int inf = 1 << 30;
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& V) {
  int N = V.size();
  for (int i = 0; i < (N); i++) {
    os << V[i];
    if (i != N - 1) os << " ";
  }
  os << "\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, pair<T, S> const& P) {
  os << "(";
  os << P.first;
  os << " , ";
  os << P.second;
  os << ")";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, set<T>& S) {
  auto it = S.begin();
  while (it != S.end()) {
    os << *it;
    os << " ";
    it++;
  }
  os << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, deque<T>& q) {
  for (auto it = q.begin(); it < q.end(); it++) {
    os << *it;
    os << " ";
  }
  os << endl;
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, map<T, S> const& M) {
  for (auto e : M) {
    os << e;
  }
  os << endl;
  return os;
}
vector<pair<int, int>> dxdy = {make_pair(0, 1), make_pair(1, 0),
                               make_pair(-1, 0), make_pair(0, -1)};
long long pow(int a, int b, int mod) {
  vector<bool> bit;
  for (b = b; b > 0; b >>= 1) {
    bit.push_back(b & 1);
  }
  vector<long long> fac(bit.size());
  fac[0] = a;
  long long res = 1;
  for (int i = 1; i < bit.size(); i++) {
    fac[i] = (fac[i - 1] * fac[i - 1]) % mod;
  }
  for (int i = 0; i < bit.size(); i++) {
    if (bit[i]) res *= fac[i];
    res %= mod;
  }
  return res;
}
struct mint {
  long long x;
  mint(long long x = 0) : x((x + 2 * MOD) % MOD) {}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res *= a;
  }
  mint pow(long long t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(MOD - 2); }
  mint& operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const {
    mint res(*this);
    return res /= a;
  }
};
ostream& operator<<(ostream& os, mint a) {
  os << a.x;
  return os;
}
int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  string S, T;
  cin >> S >> T;
  int N = S.size(), M = T.size();
  vector<vector<mint>> DP(N + 1, vector<mint>(N + 2, 0));
  for (int i = 0; i < (N + 1); i++) DP[i][0] = 1;
  for (int j = 0; j < (N + 1); j++) {
    for (int i = 0; i < (N + 1); i++) {
      if (i + j >= M) {
        DP[i][j + 1] += DP[i][j];
      } else if (S[j] == T[i + j]) {
        DP[i][j + 1] += DP[i][j];
      }
      if (i > M) {
        DP[i - 1][j + 1] += DP[i][j];
      } else if (i > 0 and S[j] == T[i - 1]) {
        DP[i - 1][j + 1] += DP[i][j];
      }
    }
  }
  mint ans = 0;
  for (int i = M; i <= N; i++) {
    ans += DP[0][i];
  }
  cout << ans << '\n';
}
