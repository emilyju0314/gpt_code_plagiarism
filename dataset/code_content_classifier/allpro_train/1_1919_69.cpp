#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Outln(const string &sep, const T &val) {
  cout << val << '\n';
}
template <typename T, typename... Args>
void Outln(const string &sep, const T &val, Args... args) {
  cout << val << sep;
  Outln(sep, std::forward<Args>(args)...);
}
template <typename T>
void Outln(const char &ch, const T &val) {
  cout << val << '\n';
}
template <typename T, typename... Args>
void Outln(const char &ch, const T &val, Args... args) {
  cout << val << ch;
  Outln(ch, std::forward<Args>(args)...);
}
template <typename T>
inline void OutN(T x) {
  size_t i, len = x.size() - 1;
  for (i = 0; i < len; i++) cout << x[i] << " ";
  cout << x[len] << '\n';
}
template <typename T>
inline void OutaN(T x[], const size_t &n) {
  size_t i, len = n - 1;
  for (i = 0; i < len; i++) cout << x[i] << " ";
  cout << x[len] << '\n';
}
template <typename T>
inline void Outit(T x) {
  auto end = x.end();
  end--;
  for (auto it = x.begin(); it != end; it++) cout << *it << " ";
  cout << *end << '\n';
}
template <typename T>
void Debug(const T &val) {
  cerr << val << '\n';
}
template <typename T, typename... Args>
void Debug(const T &val, Args... args) {
  cerr << val << ' ';
  Debug(std::forward<Args>(args)...);
}
template <typename T>
inline bool Max(T &x, const T &y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline bool Min(T &x, const T &y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
using V = vector<T>;
template <typename T>
using VV = V<V<T> >;
inline bool isSame(const string &first, const string &second) {
  return first.compare(second) == 0;
}
inline bool isLess(const string &first, const string &second) {
  return first.compare(second) < 0;
}
inline bool isGreater(const string &first, const string &second) {
  return first.compare(second) > 0;
}
inline string Str(const char &ch, const int &n) { return string(n, ch); }
inline string Str(const int &n, const char &ch) { return string(n, ch); }
vector<string> getStrLine() {
  vector<string> v;
  string str;
  getline(cin, str);
  istringstream iss(str);
  for (string word; iss >> word;) v.push_back(word);
  return v;
}
static const long long MOD = 1e9 + 7;
static const double PI = 3.141592653589793;
inline double rad2deg(const double &rad) { return rad * (180.0 / PI); }
inline double deg2rad(const double &deg) { return deg * (PI / 180.0); }
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  int n;
  int g, s, second;
  int left, right;
  int i, len;
  while (t--) {
    cin >> n;
    int p[n];
    len = n / 2;
    for ((i) = 0; (i) < (n); (i)++) cin >> p[i];
    sort(p, p + sizeof(p) / sizeof(__typeof(p[0])),
         std::greater<__typeof(p[0])>());
    while (0 <= len - 1 && p[len - 1] == p[len]) len--;
    if (len < 5) {
      Outln(" ", 0, 0, 0);
    } else {
      for ((i) = (1); (i) < (len); (i)++)
        if (p[0] != p[i]) break;
      g = i;
      left = i;
      for ((i) = (len - 1) - 1; (left) <= (i); (i)--)
        if (p[len - 1] != p[i]) break;
      right = i;
      second = len - right;
      s = right - left;
      second--;
      s++;
      if (g < s && g < second) {
        Outln(" ", g, s, second);
      } else {
        while (left < right) {
          for ((i) = (right)-1; (left) <= (i); (i)--)
            if (p[right] != p[i]) break;
          right = i;
          second = len - right;
          s = right - left;
          second--;
          s++;
          if (g < s && g < second) break;
        }
        if (g < s && g < second)
          Outln(" ", g, s, second);
        else
          Outln(" ", 0, 0, 0);
      }
    }
  }
  return 0;
}
