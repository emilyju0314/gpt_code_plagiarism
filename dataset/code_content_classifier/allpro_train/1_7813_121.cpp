#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T, typename U>
void umin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void umax(T& a, U b) {
  if (a < b) a = b;
}
vector<pair<int, int>> ans;
template <typename T>
void make_equal(T b, T e) {
  int d = e - b;
  if (d == 1) {
    return;
  }
  auto m = b + d / 2;
  auto bb = b, mm = m, mm2 = m;
  make_equal(bb, mm);
  make_equal(mm2, e);
  while (m != e) {
    ans.emplace_back(*b, *m);
    ++b;
    ++m;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> p2;
  int x = 1;
  for (int i = 0; i < 20; ++i) {
    if ((1 << i) & n) {
      p2.emplace_back();
      for (int j = 0; j < (1 << i); ++j) {
        p2.back().push_back(x);
        x += 1;
      }
    }
  }
  for (int i = 0; i < p2.size(); ++i) {
    if (p2[i].size() != 1) {
      make_equal(p2[i].begin(), p2[i].end());
    }
  }
  42;
  ;
  int ind = 0;
  if (p2.size() > 2) {
    for (int i = 0; i + 2 < p2.size(); ++i) {
      while (p2[i].size() != p2[i + 1].size()) {
        int sz = p2[i].size();
        for (int j = 0; j < sz; ++j) {
          ans.emplace_back(p2[i][j], p2.back()[ind]);
          p2[i].push_back(p2.back()[ind]);
          ind += 1;
        }
        42;
        ;
      }
      int sz = p2[i].size();
      for (int j = 0; j < sz; ++j) {
        ans.emplace_back(p2[i][j], p2[i + 1][j]);
        p2[i + 1].push_back(p2[i][j]);
      }
    }
    42;
    ;
  }
  assert(ans.size() <= 500000);
  cout << ans.size() << '\n';
  for (auto [a, b] : ans) {
    cout << a << ' ' << b << '\n';
  }
  return 0;
}
