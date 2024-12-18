#include <bits/stdc++.h>
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
template <typename T>
std::ostream& operator<<(std::ostream& o, const vector<T>& t) {
  for (size_t i = 0; i < t.size(); ++i) {
    o << t[i] << " \n"[i == t.size() - 1];
  }
  return o;
}
template <typename T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using maxheap = priority_queue<T, vector<T>, less<T>>;
auto fraclt = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
  return (long long)a.first * b.second < (long long)b.first * a.second;
};
struct cmpfrac {
  bool operator()(const std::pair<int, int>& a,
                  const std::pair<int, int>& b) const {
    return (long long)a.first * b.second < (long long)b.first * a.second;
  }
};
template <typename T>
bool in(T a, T b, T c) {
  return a <= b && b < c;
}
unsigned int logceil(long long first) {
  unsigned int b = 0;
  while (first) {
    first >>= 1;
    ++b;
  }
  return b;
}
namespace std {
template <typename T, typename U>
struct hash<pair<T, U>> {
  hash<T> t;
  hash<U> u;
  size_t operator()(const pair<T, U>& p) const {
    return t(p.first) ^ (u(p.second) << 7);
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
double bsh(double l, double h, const F& f, double p = 1e-9) {
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
double bsl(double l, double h, const F& f, double p = 1e-9) {
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
class vector3 : public vector<vector<vector<T>>> {
 public:
  vector3() {}
  vector3(size_t a, size_t b, size_t c, T t = T())
      : vector<vector<vector<T>>>(a, vector<vector<T>>(b, vector<T>(c, t))) {}
};
template <typename T>
struct bounded_priority_queue {
  inline bounded_priority_queue(unsigned int X) : A(X), B(0) {}
  inline void push(unsigned int L, T V) {
    B = max(B, L);
    A[L].push(V);
  }
  inline const T& top() const { return A[B].front(); }
  inline void pop() {
    A[B].pop();
    while (B > 0 && A[B].empty()) --B;
  }
  inline bool empty() const { return A[B].empty(); }
  inline void clear() {
    B = 0;
    for (auto& a : A) a = queue<T>();
  }

 private:
  vector<queue<T>> A;
  unsigned int B;
};
template <unsigned int N>
class Field {
  inline unsigned int pow(unsigned int a, unsigned int p) {
    unsigned int r = 1, e = a;
    while (p) {
      if (p & 1) {
        r = ((unsigned long long)r * e) % N;
      }
      e = ((unsigned long long)e * e) % N;
      p >>= 1;
    }
    return r;
  }
  inline unsigned int inv(unsigned int a) { return pow(a, N - 2); }

 public:
  inline Field(int first = 0) : v(first) {}
  inline Field<N> pow(int p) { return (*this) ^ p; }
  inline Field<N> operator^(int p) { return {(int)pow(v, (unsigned int)p)}; }
  inline Field<N>& operator+=(const Field<N>& o) {
    if ((long long)v + o.v >= N)
      v = (long long)v + o.v - N;
    else
      v = v + o.v;
    return *this;
  }
  inline Field<N>& operator-=(const Field<N>& o) {
    if (v < o.v)
      v = N - o.v + v;
    else
      v = v - o.v;
    return *this;
  }
  inline Field<N>& operator*=(const Field<N>& o) {
    v = (unsigned long long)v * o.v % N;
    return *this;
  }
  inline Field<N>& operator/=(const Field<N>& o) { return *this *= inv(o.v); }
  inline Field<N> operator+(const Field<N>& o) const {
    Field<N> r{*this};
    return r += o;
  }
  inline Field<N> operator-(const Field<N>& o) const {
    Field<N> r{*this};
    return r -= o;
  }
  inline Field<N> operator*(const Field<N>& o) const {
    Field<N> r{*this};
    return r *= o;
  }
  inline Field<N> operator/(const Field<N>& o) const {
    Field<N> r{*this};
    return r /= o;
  }
  inline Field<N> operator-() {
    if (v)
      return {(int)(N - v)};
    else
      return {0};
  };
  inline Field<N>& operator++() {
    ++v;
    if (v == N) v = 0;
    return *this;
  }
  inline Field<N> operator++(int) {
    Field<N> r{*this};
    ++*this;
    return r;
  }
  inline Field<N>& operator--() {
    --v;
    if (v == -1) v = N - 1;
    return *this;
  }
  inline Field<N> operator--(int) {
    Field<N> r{*this};
    --*this;
    return r;
  }
  inline bool operator==(const Field<N>& o) const { return o.v == v; }
  inline bool operator!=(const Field<N>& o) const { return o.v != v; }
  inline explicit operator unsigned int() const { return v; }
  inline static vector<Field<N>> fact(int t) {
    vector<Field<N>> F(t + 1, 1);
    for (int i = 2; i <= t; ++i) {
      F[i] = F[i - 1] * i;
    }
    return F;
  }
  inline static vector<Field<N>> invfact(int t) {
    vector<Field<N>> F(t + 1, 1);
    Field<N> X{1};
    for (int i = 2; i <= t; ++i) {
      X = X * i;
    }
    F[t] = 1 / X;
    for (int i = t - 1; i >= 2; --i) {
      F[i] = F[i + 1] * (i + 1);
    }
    return F;
  }

 private:
  unsigned int v;
};
template <unsigned int N>
istream& operator>>(std::istream& is, Field<N>& f) {
  unsigned int v;
  is >> v;
  f = v;
  return is;
}
template <unsigned int N>
ostream& operator<<(std::ostream& os, const Field<N>& f) {
  return os << (unsigned int)f;
}
template <unsigned int N>
Field<N> operator+(int i, const Field<N>& f) {
  return Field<N>(i) + f;
}
template <unsigned int N>
Field<N> operator-(int i, const Field<N>& f) {
  return Field<N>(i) - f;
}
template <unsigned int N>
Field<N> operator*(int i, const Field<N>& f) {
  return Field<N>(i) * f;
}
template <unsigned int N>
Field<N> operator/(int i, const Field<N>& f) {
  return Field<N>(i) / f;
}
struct Ring {
  static int div(int p, int q, int N) {
    long long t = 0, nt = 1, r = N, nr = q;
    while (nr) {
      long long q = r / nr;
      t -= q * nt;
      r -= q * nr;
      swap(t, nt);
      swap(r, nr);
    }
    t = (t < 0) ? t + N : t;
    r = (r < 0) ? r + N : r;
    if (gcd(p, N) % r) {
      return 0;
    }
    return (int)(((long long)t * (long long)p / r) % N);
  }
};
class TaskC {
 public:
  void solve(istream& cin, ostream& cout) {
    unsigned int N;
    cin >> N;
    map<int, vector<int>> X, Y;
    vector<std::pair<int, int>> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i].first >> P[i].second;
      X[P[i].first].push_back(i);
      Y[P[i].second].push_back(i);
    }
    Field<1000000007> ans = 1;
    vector<bool> V(N, false);
    for (int i = 0; i < N; ++i) {
      if (V[i]) continue;
      queue<int> Q;
      set<int> VX, VY;
      Q.push(i);
      V[i] = true;
      int p = 1;
      while (!Q.empty()) {
        int q = Q.front();
        Q.pop();
        int first = P[q].first, second = P[q].second;
        if (VX.find(first) == VX.end()) {
          VX.insert(first);
          for (int j : X[first])
            if (!V[j]) {
              V[j] = true;
              Q.push(j);
              ++p;
            }
        }
        if (VY.find(second) == VY.end()) {
          VY.insert(second);
          for (int j : Y[second])
            if (!V[j]) {
              V[j] = true;
              Q.push(j);
              ++p;
            }
        }
      }
      int l = VX.size() + VY.size();
      ans *= Field<1000000007>(2).pow(l) - (p < l);
    }
    cout << ans << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  TaskC solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
