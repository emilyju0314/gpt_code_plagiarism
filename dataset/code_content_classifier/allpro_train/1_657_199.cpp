#include <bits/stdc++.h>
using namespace std;
namespace {
using Integer = long long;
template <class T, class S>
istream& operator>>(istream& is, pair<T, S>& p) {
  return is >> p.first >> p.second;
}
template <class T>
istream& operator>>(istream& is, vector<T>& vec) {
  for (T& val : vec) is >> val;
  return is;
}
template <class T>
istream& operator,(istream& is, T& val) {
  return is >> val;
}
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& p) {
  return os << p.first << " " << p.second;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  for (size_t i = 0; i < vec.size(); i++)
    os << vec[i] << (i == vec.size() - 1 ? "" : " ");
  return os;
}
template <class T>
ostream& operator,(ostream& os, const T& val) {
  return os << " " << val;
}
template <class H>
void print(const H& head) {
  cout << head;
}
template <class H, class... T>
void print(const H& head, const T&... tail) {
  cout << head << " ";
  print(tail...);
}
template <class... T>
void println(const T&... values) {
  print(values...);
  cout << endl;
}
template <class H>
void eprint(const H& head) {
  cerr << head;
}
template <class H, class... T>
void eprint(const H& head, const T&... tail) {
  cerr << head << " ";
  eprint(tail...);
}
template <class... T>
void eprintln(const T&... values) {
  eprint(values...);
  cerr << endl;
}
class range {
  Integer start_, end_, step_;

 public:
  struct range_iterator {
    Integer val, step_;
    range_iterator(Integer v, Integer step) : val(v), step_(step) {}
    Integer operator*() { return val; }
    void operator++() { val += step_; }
    bool operator!=(range_iterator& x) {
      return step_ > 0 ? val < x.val : val > x.val;
    }
  };
  range(Integer len) : start_(0), end_(len), step_(1) {}
  range(Integer start, Integer end) : start_(start), end_(end), step_(1) {}
  range(Integer start, Integer end, Integer step)
      : start_(start), end_(end), step_(step) {}
  range_iterator begin() { return range_iterator(start_, step_); }
  range_iterator end() { return range_iterator(end_, step_); }
};
inline string operator"" _s(const char* str, size_t size) {
  return move(string(str));
}
constexpr Integer my_pow(Integer x, Integer k, Integer z = 1) {
  return k == 0    ? z
         : k == 1  ? z * x
         : (k & 1) ? my_pow(x * x, k >> 1, z * x)
                   : my_pow(x * x, k >> 1, z);
}
constexpr Integer my_pow_mod(Integer x, Integer k, Integer M, Integer z = 1) {
  return k == 0    ? z % M
         : k == 1  ? z * x % M
         : (k & 1) ? my_pow_mod(x * x % M, k >> 1, M, z * x % M)
                   : my_pow_mod(x * x % M, k >> 1, M, z);
}
constexpr unsigned long long operator"" _ten(unsigned long long value) {
  return my_pow(10, value);
}
inline int k_bit(Integer x, int k) { return (x >> k) & 1; }
mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(
               chrono::steady_clock::now().time_since_epoch())
               .count());
template <class T>
string join(const vector<T>& v, const string& sep) {
  stringstream ss;
  for (size_t i = 0; i < v.size(); i++) {
    if (i > 0) ss << sep;
    ss << v[i];
  }
  return ss.str();
}
inline string operator*(string s, int k) {
  string ret;
  while (k) {
    if (k & 1) ret += s;
    s += s;
    k >>= 1;
  }
  return ret;
}
}  // namespace
constexpr long long mod = 9_ten + 7;
int main() {
  int n;
  cin >> n;
  vector<string> ex, rg;
  for (int i = 0; i < n; i++) {
    string name;
    int type;
    cin >> name, type;
    if (type == 1) {
      ex.push_back(name);
    } else {
      rg.push_back(name);
    }
  }
  set<string> unused_e, unused_r;
  for (int i = 0; i < ex.size(); i++) {
    char buff[50];
    sprintf(buff, "%d", i + 1);
    unused_e.insert(string(buff));
  }
  for (int i = 0; i < rg.size(); i++) {
    char buff[50];
    sprintf(buff, "%d", i + 1 + ex.size());
    unused_r.insert(string(buff));
  }
  set<string> e_to_r, r_to_e, o_to_e, o_to_r;
  for (int i = 0; i < ex.size(); i++) {
    if (unused_e.count(ex[i])) {
      unused_e.erase(ex[i]);
    } else if (unused_r.count(ex[i])) {
      unused_r.erase(ex[i]);
      r_to_e.insert(ex[i]);
    } else {
      o_to_e.insert(ex[i]);
    }
  }
  for (int i = 0; i < rg.size(); i++) {
    if (unused_r.count(rg[i])) {
      unused_r.erase(rg[i]);
    } else if (unused_e.count(rg[i])) {
      unused_e.erase(rg[i]);
      e_to_r.insert(rg[i]);
    } else {
      o_to_r.insert(rg[i]);
    }
  }
  vector<pair<string, string>> ans;
  if (unused_e.size() == 0 && unused_r.size() == 0) {
    if (e_to_r.size()) {
      string name = *e_to_r.begin();
      e_to_r.erase(name);
      unused_e.insert(name);
      o_to_r.insert("0");
      ans.emplace_back(name, "0");
    } else if (r_to_e.size()) {
      string name = *r_to_e.begin();
      r_to_e.erase(name);
      unused_r.insert(name);
      o_to_e.insert("0");
      ans.emplace_back(name, "0");
    }
  }
  while (unused_e.size() || unused_r.size()) {
    if (unused_e.size()) {
      if (r_to_e.size()) {
        string name = *r_to_e.begin();
        r_to_e.erase(r_to_e.begin());
        unused_r.insert(name);
        string name_ = *unused_e.begin();
        unused_e.erase(unused_e.begin());
        ans.emplace_back(name, name_);
      } else if (o_to_e.size()) {
        string name = *o_to_e.begin();
        o_to_e.erase(o_to_e.begin());
        string name_ = *unused_e.begin();
        unused_e.erase(unused_e.begin());
        ans.emplace_back(name, name_);
      } else {
        abort();
      }
    } else {
      if (e_to_r.size()) {
        string name = *e_to_r.begin();
        e_to_r.erase(e_to_r.begin());
        unused_e.insert(name);
        string name_ = *unused_r.begin();
        unused_r.erase(unused_r.begin());
        ans.emplace_back(name, name_);
      } else if (o_to_r.size()) {
        string name = *o_to_r.begin();
        o_to_r.erase(o_to_r.begin());
        string name_ = *unused_r.begin();
        unused_r.erase(unused_r.begin());
        ans.emplace_back(name, name_);
      } else {
        abort();
      }
    }
  }
  println(ans.size());
  for (int i = 0; i < ans.size(); i++) {
    println("move", ans[i].first, ans[i].second);
  }
  return 0;
}
