#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline T parse(const string &s) {
  T x;
  stringstream ss(s);
  ss >> x;
  return x;
}
const double EPS = 1e-12;
const int INF = 1000 * 1000 * 1000;
const long long LINF = INF * 1ll * INF;
const double DINF = 1e200;
const double PI = 3.1415926535897932384626433832795l;
int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long gcdex(long long a, long long b, long long &x, long long &y) {
  if (!a) {
    x = 0, y = 1;
    return b;
  }
  long long k = b / a;
  long long g = gcdex(b - k * a, a, y, x);
  x -= k * y;
  return g;
}
long long inv(long long a, long long m) {
  assert(m > 1);
  long long x, y, g;
  g = gcdex(a, m, x, y);
  return (x % (m / g) + m / g) % m / g;
}
long long crt(long long a1, long long m1, long long a2, long long m2) {
  long long a = (a2 - a1 % m2 + m2) % m2;
  long long x, y, g;
  g = gcdex(m1, m2, x, y);
  if (a % g) return -1;
  long long m = m1 / g * m2;
  assert(x + m2 >= 0);
  x = a / g * (x + m2) % m2;
  long long r = (a1 + x * m1) % m;
  assert(r % m1 == a1 && r % m2 == a2);
  return r;
}
long long powmod(long long a, long long p, long long m) {
  assert(p >= 0);
  long long r = 1;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
bool isprime(long long a) {
  if (a <= 1) return false;
  for (long long i = 2; i * i <= a; ++i) {
    if (a % i == 0) return false;
  }
  return true;
}
long long sqrtup(long long a) {
  if (!a) return 0;
  long long x = max(0ll, (long long)sqrt((double)a));
  while (x * x >= a) --x;
  while ((x + 1) * (x + 1) < a) ++x;
  return x + 1;
}
long long isqrt(long long a) {
  if (a <= 0) {
    assert(!a);
    return 0;
  }
  long long x = (long long)sqrt((double)a);
  while (sqr(x + 1) <= a) ++x;
  while (x * x > a) --x;
  return x;
}
long long sgn(long long x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
template <class T>
ostream &operator<<(ostream &s, const vector<T> &v);
template <class A, class B>
ostream &operator<<(ostream &s, const pair<A, B> &p);
template <class K, class V>
ostream &operator<<(ostream &s, const map<K, V> &m);
template <class T>
ostream &operator<<(ostream &s, const set<T> &m);
template <class T, size_t N>
ostream &operator<<(ostream &s, const array<T, N> &a);
template <class... T>
ostream &operator<<(ostream &s, const tuple<T...> &t);
template <class T>
ostream &operator<<(ostream &s, const vector<T> &v) {
  s << '[';
  for (int i = 0; i < (((int)(v).size())); ++i) {
    if (i) s << ',';
    s << v[i];
  }
  s << ']';
  return s;
}
template <class A, class B>
ostream &operator<<(ostream &s, const pair<A, B> &p) {
  s << "(" << p.first << "," << p.second << ")";
  return s;
}
template <class K, class V>
ostream &operator<<(ostream &s, const map<K, V> &m) {
  s << "{";
  bool f = false;
  for (const auto &it : m) {
    if (f) s << ",";
    f = true;
    s << it.first << ": " << it.second;
  }
  s << "}";
  return s;
}
template <class T>
ostream &operator<<(ostream &s, const set<T> &m) {
  s << "{";
  bool f = false;
  for (const auto &it : m) {
    if (f) s << ",";
    f = true;
    s << it;
  }
  s << "}";
  return s;
}
template <class T>
ostream &operator<<(ostream &s, const multiset<T> &m) {
  s << "{";
  bool f = false;
  for (const auto &it : m) {
    if (f) s << ",";
    f = true;
    s << it;
  }
  s << "}";
  return s;
}
template <class T, class V, class C>
ostream &operator<<(ostream &s, const priority_queue<T, V, C> &q) {
  auto a = q;
  s << "{";
  bool f = false;
  while (!a.empty()) {
    if (f) s << ",";
    f = true;
    s << a.top();
    a.pop();
  }
  return s << "}";
}
template <class T, size_t N>
ostream &operator<<(ostream &s, const array<T, N> &a) {
  s << '[';
  for (int i = 0; i < (((int)(a).size())); ++i) {
    if (i) s << ',';
    s << a[i];
  }
  s << ']';
  return s;
}
template <class T>
ostream &operator<<(ostream &s, const deque<T> &a) {
  s << '[';
  for (int i = 0; i < (((int)(a).size())); ++i) {
    if (i) s << ',';
    s << a[i];
  }
  s << ']';
  return s;
}
template <size_t n, class... T>
struct put1 {
  static ostream &put(ostream &s, const tuple<T...> &t) {
    s << get<sizeof...(T) - n>(t);
    if (n > 1) s << ',';
    return put1<n - 1, T...>::put(s, t);
  }
};
template <class... T>
struct put1<0, T...> {
  static ostream &put(ostream &s, const tuple<T...> &t) { return s; }
};
template <class... T>
ostream &operator<<(ostream &s, const tuple<T...> &t) {
  s << "(";
  put1<sizeof...(T), T...>::put(s, t);
  s << ")";
  return s;
}
ostream &put3(ostream &s, const char *, bool) { return s; }
template <class U, class... T>
ostream &put3(ostream &s, const char *f, bool fs, U &&u, T &&...t) {
  while (*f == ' ') ++f;
  if (!fs) s << ", ";
  auto nf = f;
  int d = 0;
  while (*nf && (*nf != ',' || d)) {
    if (*nf == '(')
      ++d;
    else if (*nf == ')')
      --d;
    ++nf;
  }
  auto nf2 = nf;
  while (nf2 > f && *(nf2 - 1) == ' ') --nf;
  fs = *f == '"';
  if (!fs) {
    s.write(f, nf2 - f);
    s << "=";
  };
  s << u;
  if (fs) s << ' ';
  if (*nf) ++nf;
  return put3(s, nf, fs, forward<T>(t)...);
}
struct bigraph {
  vector<vector<int>> G;
  vector<int> mt;
  vector<char> W;
  bigraph(int n, int m) : G(n), mt(m, -1) {}
  void add(int a, int b) { G[a].push_back(b); }
  bool dfs(int v) {
    if (W[v]) return false;
    W[v] = true;
    for (int p : G[v]) {
      if (mt[p] == -1 || dfs(mt[p])) {
        mt[p] = v;
        return true;
      }
    }
    return false;
  }
  void match() {
    for (int i = 0; i < (((int)(G).size())); ++i) {
      W.assign(((int)(G).size()), 0);
      dfs(i);
    }
  }
  void dfs2(int v, vector<char> &wr) {
    if (W[v]) return;
    W[v] = 1;
    for (int p : G[v]) {
      wr[p] = 1;
      if (mt[p] != -1) dfs2(mt[p], wr);
    }
  }
  void independ(vector<char> &ansl, vector<char> &ansr) {
    match();
    vector<char> T(((int)(G).size()));
    for (int i = 0; i < (((int)(mt).size())); ++i)
      if (mt[i] != -1) T[mt[i]] = 1;
    W.assign(((int)(G).size()), 0);
    for (int i = 0; i < (((int)(G).size())); ++i)
      if (!T[i]) dfs2(i, ansr);
    for (int i = 0; i < (((int)(mt).size())); ++i) ansr[i] ^= 1;
    ansl = W;
    do {
    } while (false);
    do {
    } while (false);
    do {
    } while (false);
    do {
    } while (false);
  }
};
void solve(vector<pair<int, int>> R, vector<pair<int, pair<int, int>>> &ansr,
           vector<pair<int, pair<int, int>>> &ansc) {
  int n = ((int)(R).size());
  vector<pair<int, int>> C(n);
  for (int i = 0; i < (n); ++i) C[i] = make_pair(R[i].second, R[i].first);
  sort((R).begin(), (R).end());
  sort((C).begin(), (C).end());
  do {
  } while (false);
  do {
  } while (false);
  bigraph G(n, n);
  for (int i = 0; i < (n - 1); ++i) {
    if (R[i + 1].first != R[i].first) continue;
    for (int j = 0; j < (n - 1); ++j) {
      if (C[j + 1].first != C[j].first) continue;
      if (C[j].first > R[i].second && C[j].first < R[i + 1].second &&
          R[i].first > C[j].second && R[i].first < C[j + 1].second)
        G.add(i, j);
    }
  }
  vector<char> AR(n), AC(n);
  G.independ(AR, AC);
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && R[j].first == R[i].first && AR[j - 1]) ++j;
    ansr.push_back(
        make_pair(R[i].first, make_pair(R[i].second, R[j - 1].second)));
    i = j;
  }
  for (int i = 0; i < n;) {
    int j = i + 1;
    while (j < n && C[j].first == C[i].first && AC[j - 1]) ++j;
    ansc.push_back(
        make_pair(C[i].first, make_pair(C[i].second, C[j - 1].second)));
    i = j;
  }
}
vector<pair<int, int>> inters(const vector<pair<int, pair<int, int>>> &R,
                              const vector<pair<int, pair<int, int>>> &C) {
  vector<pair<int, int>> ans;
  for (auto a : R) {
    for (auto b : C) {
      if (a.first >= b.second.first && a.first <= b.second.second &&
          b.first >= a.second.first && b.first <= a.second.second)
        ans.push_back(make_pair(a.first, b.first));
    }
  }
  sort((ans).begin(), (ans).end());
  return ans;
}
void test() {
  vector<pair<int, int>> A;
  for (int n = 1; n <= 20; ++n) {
    for (int s = 1; s <= 20; ++s) {
      if (s * s < n * 2) continue;
      for (int qq = 0; qq < (10000); ++qq) {
        A.resize(n * 2);
        for (int i = 0; i < (((int)(A).size())); ++i)
          A[i] = make_pair(rand() % s, rand() % s);
        sort((A).begin(), (A).end());
        A.erase(unique((A).begin(), (A).end()), A.end());
        if (((int)(A).size()) < n) continue;
        random_shuffle((A).begin(), (A).end());
        A.erase(A.begin() + n, A.end());
        sort((A).begin(), (A).end());
        vector<pair<int, pair<int, int>>> r, c;
        solve(A, r, c);
        auto t = inters(r, c);
        if (A != t) {
          do {
          } while (false);
          return;
        }
      }
    }
  }
  do {
  } while (false);
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);
  srand(time(0));
  int n;
  cin >> n;
  vector<pair<int, int>> A(n);
  for (int i = 0; i < (n); ++i) cin >> A[i].first >> A[i].second;
  vector<pair<int, pair<int, int>>> ansr, ansc;
  solve(A, ansr, ansc);
  cout << ((int)(ansc).size()) << '\n';
  for (auto p : ansc) {
    cout << p.second.first << ' ' << p.first << ' ' << p.second.second << ' '
         << p.first << '\n';
  }
  cout << ((int)(ansr).size()) << '\n';
  for (auto p : ansr) {
    cout << p.first << ' ' << p.second.first << ' ' << p.first << ' '
         << p.second.second << '\n';
  }
  return 0;
}
