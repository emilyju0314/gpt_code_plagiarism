#include <bits/stdc++.h>
using namespace std;
template <class T>
void mini(T& a, T b) {
  a = min(a, b);
}
template <class T>
void maxi(T& a, T b) {
  a = max(a, b);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  return out << a.first << " " << a.second;
}
template <class T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, set<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, multiset<T> a) {
  for (auto& i : a) out << i << " ";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, map<T1, T2> a) {
  for (auto& i : a) out << i << "\n";
  return out;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, unordered_map<T1, T2> a) {
  for (auto& i : a) out << i << "\n";
  return out;
}
template <class T>
ostream& operator<<(ostream& out, queue<T> a) {
  while (!a.empty()) {
    cout << a.front() << " ";
    a.pop();
  }
  return out;
}
template <class T>
ostream& operator<<(ostream& out, deque<T> a) {
  while (!a.empty()) {
    cout << a.front() << " ";
    a.pop_front();
  }
  return out;
}
template <class T>
ostream& operator<<(ostream& out, priority_queue<T> a) {
  while (!a.empty()) {
    cout << a.top() << "\n";
    a.pop();
  }
  return out;
}
template <class T>
void out(T a) {
  cout << a << endl;
}
template <class T1, class T2>
void out(T1 a, T2 b) {
  cout << a << " " << b << endl;
}
template <class T1, class T2, class T3>
void out(T1 a, T2 b, T3 c) {
  cout << a << " " << b << " " << c << endl;
}
void out() { cout << "OK" << endl; }
template <class T>
void sort(vector<T>& a) {
  sort(a.begin(), a.end());
}
template <class T>
void uniq(vector<T>& a) {
  sort(a);
  a.erase(unique(a.begin(), a.end()), a.end());
}
template <class T>
vector<T> set_int(vector<T> a, vector<T> b) {
  sort(a);
  sort(b);
  vector<T> res;
  set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
  return res;
}
clock_t start_time;
double get_time() { return (double)(clock() - start_time) / CLOCKS_PER_SEC; }
istream& operator>>(istream& in, __int128& a) {
  int64_t b;
  cin >> b;
  a = b;
  return in;
}
ostream& operator<<(ostream& out, const __int128 a) {
  unsigned __int128 b = a < 0 ? -a : a;
  char buf[128];
  char* c = end(buf);
  do {
    --c;
    *c = "0123456789"[b % 10];
    b /= 10;
  } while (b);
  if (a < 0) {
    --c;
    *c = '-';
  }
  int len = end(buf) - c;
  out.rdbuf()->sputn(c, len);
  return out;
}
template <int m>
struct mint {
  int x;
  mint(int64_t a = 0) {
    if (a < 0) a = a % m + m;
    if (a >= m) a %= m;
    x = a;
  }
  friend istream& operator>>(istream& in, mint& a) {
    int64_t y;
    cin >> y;
    a = y;
    return in;
  }
  friend ostream& operator<<(ostream& out, mint a) { return out << a.x; }
  explicit operator int() const { return x; }
  static int mod_inv(int a, int mod = m) {
    int g = mod, r = a, z = 0, y = 1;
    while (r != 0) {
      int q = g / r;
      g %= r;
      swap(g, r);
      z -= q * y;
      swap(z, y);
    }
    return z < 0 ? z + mod : z;
  }
  mint inv() const { return mod_inv(x, m); }
  friend mint binpow(mint a, int64_t b) {
    mint res = 1;
    while (b) {
      if (b & 1) res *= a;
      b >>= 1;
      a *= a;
    }
    return res;
  }
  mint pow(int64_t b) const { return binpow(*this, b); }
  mint& operator+=(const mint& a) {
    x += a.x;
    if (x >= m) x -= m;
    return *this;
  }
  mint& operator-=(const mint& a) {
    x -= a.x;
    if (x < 0) x += m;
    return *this;
  }
  static unsigned fast_mod(uint64_t x, unsigned mod = m) {
    return x % mod;
    unsigned x_high = x >> 32, x_low = (unsigned)x;
    unsigned quot, rem;
    asm("divl %4\n"
        : "=a"(quot), "=d"(rem)
        : "d"(x_high), "a"(x_low), "r"(mod));
    return rem;
  }
  mint& operator*=(const mint& a) {
    x = fast_mod((uint64_t)x * a.x);
    return *this;
  }
  mint& operator/=(const mint& a) { return *this *= a.inv(); }
  friend mint operator+(const mint& a, const mint& b) { return mint(a) += b; }
  friend mint operator-(const mint& a, const mint& b) { return mint(a) -= b; }
  friend mint operator*(const mint& a, const mint& b) { return mint(a) *= b; }
  friend mint operator/(const mint& a, const mint& b) {
    return mint(a) /= mint(b);
  }
  mint& operator++() {
    x = x == m - 1 ? 0 : x + 1;
    return *this;
  }
  mint& operator--() {
    x = x == 0 ? m - 1 : x - 1;
    return *this;
  }
  mint operator++(int) {
    mint a = *this;
    ++*this;
    return a;
  }
  mint operator--(int) {
    mint a = *this;
    --*this;
    return a;
  }
  mint operator-() const { return x ? m - x : 0; }
  bool operator==(const mint& a) const { return x == a.x; }
  bool operator!=(const mint& a) const { return x != a.x; }
};
const int p = 1e9 + 7;
const int N = 55;
mint<p> dp[N][N][2];
mint<p> c[N][N];
mint<p> sol(int n, int k, int t) {
  if (k < 0) return 0;
  if (n == 1) {
    if (k > 0) return 0;
    if (t) return 0;
    return 1;
  }
  if (n == 2) {
    if (k != 1) return 0;
    if (t != 1) return 0;
    return 1;
  }
  mint<p>& res = dp[n][k][t];
  if (res != -1) return res;
  res = 0;
  if (t) {
    res = sol(n - 1, k - 1, 0) * (n - 1);
  } else {
    res = sol(n - 1, k, 1) * (n - 1);
  }
  for (int x = 1; x <= n - 2; x++) {
    mint<p> cur = 0;
    for (int s = 0; s <= k; s++) {
      if (t) {
        cur += sol(x, s, 1) * sol(n - 1 - x, k - s - 1, 0);
        cur += sol(x, s, 0) * sol(n - 1 - x, k - s - 1, 0);
        cur += sol(x, s, 0) * sol(n - 1 - x, k - s - 1, 1);
      } else {
        cur += sol(x, s, 1) * sol(n - 1 - x, k - s, 1);
      }
    }
    cur *= c[n - 2][x];
    cur *= x;
    cur *= n - 1 - x;
    res += cur;
  }
  return res;
}
void Solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= N - 1; i++)
    for (int j = 0; j <= N - 1; j++)
      for (int t = 0; t <= 1; t++) dp[i][j][t] = -1;
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= i - 1; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    c[i][0] = c[i][i] = 1;
  }
  mint<p> ans = sol(n, k, 0) + sol(n, k, 1);
  out(ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  start_time = clock();
  Solve();
  return 0;
}
