#include <bits/stdc++.h>
using namespace std;
using namespace std;
template <typename T, typename U>
std::istream& operator>>(std::istream& i, pair<T, U>& p) {
  i >> p.first >> p.second;
  return i;
}
template <typename T>
std::istream& operator>>(std::istream& i, vector<T>& t) {
  for (auto& v : t) {
    i >> v;
  }
  return i;
}
template <typename T, typename U>
std::ostream& operator<<(std::ostream& o, const pair<T, U>& p) {
  o << p.first << ' ' << p.second;
  return o;
}
template <typename T>
std::ostream& operator<<(std::ostream& o, const vector<T>& t) {
  if (t.empty()) o << '\n';
  for (size_t i = 0; i < t.size(); ++i) {
    o << t[i] << " \n"[i == t.size() - 1];
  }
  return o;
}
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
bool in(T a, T b, T c) {
  return a <= b && b < c;
}
unsigned int logceil(int x) { return 8 * sizeof(int) - __builtin_clz(x); }
namespace std {
template <typename T, typename U>
struct hash<pair<T, U>> {
  hash<T> t;
  hash<U> u;
  size_t operator()(const pair<T, U>& p) const {
    return t(p.x) ^ (u(p.y) << 7);
  }
};
}  // namespace std
template <typename T, typename F>
T bsh(T l, T h, const F& f) {
  T r = -1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (f(m)) {
      l = m + 1;
      r = m;
    } else {
      h = m - 1;
    }
  }
  return r;
}
template <typename F>
double bshd(double l, double h, const F& f, double p = 1e-9) {
  unsigned int r = 3 + (unsigned int)log2((h - l) / p);
  while (r--) {
    double m = (l + h) / 2;
    if (f(m)) {
      l = m;
    } else {
      h = m;
    }
  }
  return (l + h) / 2;
}
template <typename T, typename F>
T bsl(T l, T h, const F& f) {
  T r = -1, m;
  while (l <= h) {
    m = (l + h) / 2;
    if (f(m)) {
      h = m - 1;
      r = m;
    } else {
      l = m + 1;
    }
  }
  return r;
}
template <typename F>
double bsld(double l, double h, const F& f, double p = 1e-9) {
  unsigned int r = 3 + (unsigned int)log2((h - l) / p);
  while (r--) {
    double m = (l + h) / 2;
    if (f(m)) {
      h = m;
    } else {
      l = m;
    }
  }
  return (l + h) / 2;
}
template <typename T>
T gcd(T a, T b) {
  if (a < b) swap(a, b);
  return b ? gcd(b, a % b) : a;
}
template <typename T>
class vector2 : public vector<vector<T>> {
 public:
  vector2() {}
  vector2(size_t a, size_t b, T t = T())
      : vector<vector<T>>(a, vector<T>(b, t)) {}
};
template <typename T>
class vector3 : public vector<vector2<T>> {
 public:
  vector3() {}
  vector3(size_t a, size_t b, size_t c, T t = T())
      : vector<vector2<T>>(a, vector2<T>(b, c, t)) {}
};
template <typename T>
class vector4 : public vector<vector3<T>> {
 public:
  vector4() {}
  vector4(size_t a, size_t b, size_t c, size_t d, T t = T())
      : vector<vector3<T>>(a, vector3<T>(b, c, d, t)) {}
};
template <typename T>
class vector5 : public vector<vector4<T>> {
 public:
  vector5() {}
  vector5(size_t a, size_t b, size_t c, size_t d, size_t e, T t = T())
      : vector<vector4<T>>(a, vector4<T>(b, c, d, e, t)) {}
};
void fastIO() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
class ADianaILiana {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n, k, m, s;
    in >> n >> k >> m >> s;
    int rm = n - k * m;
    int ok = k;
    k += rm;
    vector<int> a(n);
    in >> a;
    map<int, int> b;
    int t;
    b.clear();
    for (int i = 0; i < s; ++i) {
      in >> t;
      b[t]++;
    }
    map<int, int> c = b;
    int bad = c.size();
    for (int i = 0; i < k; ++i) {
      if (c.count(a[i])) {
        c[a[i]]--;
        if (c[a[i]] == 0) --bad;
      }
    }
    int st = 0;
    while (st + k < n) {
      if (bad == 0 && st % ok == 0) break;
      if (c.count(a[st])) {
        if (c[a[st]] == 0) ++bad;
        c[a[st]]++;
      }
      if (c.count(a[st + k])) {
        c[a[st + k]]--;
        if (c[a[st + k]] == 0) --bad;
      }
      ++st;
    }
    if (bad || (st % ok != 0)) {
      out << -1 << endl;
      return;
    }
    out << rm << endl;
    for (int i = 0; i < k; ++i) {
      int p = st + i;
      if (rm == 0) break;
      if (b[a[p]] > 0) {
        --b[a[p]];
        continue;
      }
      out << p + 1 << " ";
      --rm;
    }
    out << endl;
  }
};
int main() {
  ADianaILiana solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
