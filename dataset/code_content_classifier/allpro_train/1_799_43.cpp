#include <bits/stdc++.h>
namespace hash_tuple {
template <typename TT>
struct hash {
  size_t operator()(TT const &tt) const { return std::hash<TT>()(tt); }
};
template <class T>
inline void hash_combine(std::size_t &seed, T const &v) {
  seed ^= hash_tuple::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}
template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
struct HashValueImpl {
  void operator()(size_t &seed, Tuple const &tuple) const {
    HashValueImpl<Tuple, Index - 1>{}(seed, tuple);
    hash_combine(seed, std::get<Index>(tuple));
  }
};
template <class Tuple>
struct HashValueImpl<Tuple, 0> {
  void operator()(size_t &seed, Tuple const &tuple) const {
    hash_combine(seed, std::get<0>(tuple));
  }
};
template <typename... TT>
struct hash<std::tuple<TT...>> {
  size_t operator()(std::tuple<TT...> const &tt) const {
    size_t seed = 0;
    HashValueImpl<std::tuple<TT...>>{}(seed, tt);
    return seed;
  }
};
template <typename T>
inline void hash_val(std::size_t &seed, const T &val) {
  hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &...args) {
  hash_combine(seed, val);
  hash_val(seed, args...);
}
template <typename... Types>
inline std::size_t hash_val(const Types &...args) {
  std::size_t seed = 0;
  hash_val(seed, args...);
  return seed;
}
struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &p) const {
    return hash_val(p.first, p.second);
  }
};
}  // namespace hash_tuple
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int count = 0;
    int wins = 0;
    int losses = 0;
    vector<int> losing_streaks;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'W') {
        wins++;
        count++;
        if (i != 0 && s[i - 1] == 'W') count++;
      }
      if (s[i] == 'L') {
        losses++;
        if (i == 0 || s[i - 1] == 'W') losing_streaks.push_back(0);
        losing_streaks.back()++;
      }
    }
    if (k >= losses) {
      cout << 2 * n - 1 << "\n";
      continue;
    }
    if (wins == 0) {
      if (k == 0)
        cout << 0 << "\n";
      else
        cout << 2 * k - 1 << "\n";
      continue;
    }
    if (s[0] == 'L') losing_streaks[0] = 1e8;
    if (s[n - 1] == 'L') losing_streaks.back() = 1e8;
    sort(losing_streaks.begin(), losing_streaks.end());
    int temp = k;
    for (int ls : losing_streaks) {
      if (ls > k) break;
      k -= ls;
      count++;
    }
    cout << count + (2 * temp) << "\n";
  }
}
