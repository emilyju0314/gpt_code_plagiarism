#include <bits/stdc++.h>
using namespace std;
template <class U, class V>
istream &operator>>(istream &is, pair<U, V> &p) {
  return is >> p.first >> p.second;
}
template <class U, class V>
ostream &operator<<(ostream &os, const pair<U, V> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <
    class Istream, class Container,
    typename std::enable_if<is_same<Istream, istream>::value, int>::type = 0>
Istream &operator>>(Istream &is, Container &container) {
  for (auto &value : container) is >> value;
  return is;
}
template <
    class Ostream, class Container,
    typename std::enable_if<is_same<Ostream, ostream>::value, int>::type = 0>
Ostream &operator<<(Ostream &os, const Container &container) {
  auto _begin = begin(container), _end = end(container);
  for (auto it = _begin; it != _end;)
    os << "{ "[it != _begin] << *it << ",}"[++it == _end];
  return os;
}
namespace io {
template <class... As>
struct last {};
template <class... As>
using last_t = typename last<As...>::type;
template <class A>
struct last<A> {
  using type = A;
};
template <class A, class... As>
struct last<A, As...> {
  using type = typename last<As...>::type;
};
template <class Z>
Z read(Z z) {
  cin >> z;
  return z;
}
template <class A, class... As>
last_t<As...> read(A &a, As &...as) {
  return cin >> a, read(as...);
}
void log_rest() {}
template <class A, class... As>
void log_rest(const A &a, const As &...as) {
  cerr << ", " << a;
  log_rest(as...);
}
template <class A, class... As>
void log(const string &pref, const A &a, const As &...as) {
  cerr << pref << a, log_rest(as...);
}
}  // namespace io
template <class T>
T make_vec(T default_value) {
  return default_value;
}
template <class T, class Arg, class... Args>
auto make_vec(T default_value, Arg size, Args... rest)
    -> vector<decltype(make_vec(default_value, rest...))> {
  auto level = make_vec(default_value, rest...);
  return vector<decltype(level)>(size, level);
}
template <class Xs>
int len(const Xs &xs) {
  return static_cast<int>(xs.size());
}
template <class T, class P>
auto bin_search(T l, T r, P p) -> T {
  for (T m; m = (l + r) / 2, m != l && m != r; (p(m) ? l : r) = m)
    ;
  return l;
}
using i64 = int64_t;
using f80 = long double;
using Str = string;
template <class T = int>
using Vec = vector<T>;
template <class K = int, class H = hash<K>>
using US = unordered_set<K, H>;
template <class K, class V, class H = hash<K>>
using UM = unordered_map<K, V, H>;
template <class U = int, class V = U>
using P = pair<U, V>;
using G = Vec<Vec<int>>;
class Float {
 public:
  static double kPrecision;
  Float(double value = 0, int = 0) : value_{value} {}
  explicit operator double() const { return value_; }
  Float operator-() const { return Float{-value_}; }
  Float &operator+=(const Float &rhs) { return value_ += rhs.value_, *this; }
  Float &operator-=(const Float &rhs) { return value_ -= rhs.value_, *this; }
  Float &operator*=(const Float &rhs) { return value_ *= rhs.value_, *this; }
  Float &operator/=(const Float &rhs) { return value_ /= rhs.value_, *this; }
  friend bool operator<(const Float &lhs, const Float &rhs) {
    return lhs.value_ + kPrecision < rhs.value_;
  }
  friend bool operator>(const Float &lhs, const Float &rhs) {
    return lhs.value_ - kPrecision > rhs.value_;
  }
  friend bool operator==(const Float &lhs, const Float &rhs) {
    return !(lhs < rhs) && !(rhs < lhs);
  }
  friend bool operator!=(const Float &lhs, const Float &rhs) {
    return !(lhs == rhs);
  }

 private:
  friend std::istream &operator>>(std::istream &os, Float &value);
  friend std::ostream &operator<<(std::ostream &os, const Float &value);
  double value_;
};
double Float::kPrecision = 1e-9;
Float operator+(const Float &lhs, const Float &rhs) {
  return Float(lhs) += rhs;
}
Float operator-(const Float &lhs, const Float &rhs) {
  return Float(lhs) -= rhs;
}
Float operator*(const Float &lhs, const Float &rhs) {
  return Float(lhs) *= rhs;
}
Float operator/(const Float &lhs, const Float &rhs) {
  return Float(lhs) /= rhs;
}
Float operator""_f(unsigned long long value) { return Float(value); }
Float operator""_f(long double value) { return Float(value); }
std::ostream &operator<<(std::ostream &os, const Float &value) {
  return os << static_cast<double>(value);
}
std::istream &operator>>(std::istream &is, Float &value) {
  return is >> value.value_;
}
const double PI = acos(-1);
int main() {
  int n, k = io::read(n, k);
  Vec<P<>> ps(n);
  cin >> ps;
  double max_dist = 0;
  for (auto [x, y] : ps) {
    max_dist = max(max_dist, hypot(double(x), double(y)));
  }
  for (auto &[x, y] : ps) {
    if (x == 0 && y == 0) {
      swap(ps.back().first, x);
      swap(ps.back().second, y);
      --k;
      ps.pop_back();
    }
  }
  Float::kPrecision = 1e-9;
  cout << bin_search(10 * max_dist + 0_f, 0_f,
                     [&](Float radius) {
                       Vec<P<double>> segments;
                       for (auto [x, y] : ps) {
                         double d = hypot<double>(x, y);
                         if (!(d < 2 * radius)) {
                           continue;
                         }
                         double ang = atan2<double>(y, x);
                         double diff =
                             acos(d / 2 / static_cast<double>(radius));
                         segments.emplace_back(ang - diff, ang + diff);
                       }
                       int opened = 0;
                       Vec<P<double, int>> events;
                       for (auto [start, end] : segments) {
                         while (start < 0 && end < 0) {
                           start += 2 * PI;
                           end += 2 * PI;
                         }
                         while (end > 2 * PI) {
                           start -= 2 * PI;
                           end -= 2 * PI;
                         }
                         if (start < 0) {
                           ++opened;
                           events.emplace_back(start + 2 * PI, +1);
                         } else {
                           events.emplace_back(start, +1);
                         }
                         events.emplace_back(end, -1);
                       }
                       sort(::std::begin(events), ::std::end(events));
                       if (opened >= k) return true;
                       for (auto [_, diff] : events) {
                         opened += diff;
                         if (opened >= k) {
                           return true;
                         }
                       }
                       return false;
                     })
              .
              operator double()
       << '\n';
}
namespace {
auto fast_io = [] {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(10) << fixed;
  cerr << boolalpha << setprecision(4) << fixed;
  return 0;
}();
}
