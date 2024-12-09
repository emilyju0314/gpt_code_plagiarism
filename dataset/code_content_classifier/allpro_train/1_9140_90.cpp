#include <bits/stdc++.h>
using namespace std;
template <class T, class S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  return os << "(" << v.first << ", " << v.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = int(0); i <= int((static_cast<int>((v).size())) - 1); ++i) {
    if (i) os << ", ";
    os << v[i];
  }
  return os << "]";
}
template <class T>
bool setmax(T& _a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T& _a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
vector<pair<pair<int, int>, pair<int, int>>> ans;
set<pair<pair<int, int>, pair<int, int>>> to_erase;
void add_r(int x, int y) {
  ans.emplace_back(make_pair(x, y), make_pair(x, y + 1));
}
void add_d(int x, int y) {
  ans.emplace_back(make_pair(x, y), make_pair(x + 1, y));
}
void erase_r(int x, int y) {
  to_erase.emplace(make_pair(x, y), make_pair(x, y + 1));
}
void erase_d(int x, int y) {
  to_erase.emplace(make_pair(x, y), make_pair(x + 1, y));
}
void initial_framework(int v) {
  for (int i = int(1); i <= int(2); ++i) add_d(4, i);
  for (int i = int(2); i <= int(3); ++i) add_r(i, 3);
  add_d(1, 3);
  if (v == 1) {
    add_d(1, 1), add_d(2, 2);
  }
  if (v == 2) {
    add_d(1, 1), add_d(3, 2);
  }
  if (v == 3) {
    add_d(1, 1);
  }
  if (v == 4) {
    add_d(2, 1), add_d(3, 2);
  }
  if (v == 5) {
    add_r(3, 1), add_d(3, 2);
  }
}
void framework(int x, int y) {
  for (int i = int(y); i <= int(y + 1); ++i) add_d(x + 2, i);
  for (int i = int(x - 2); i <= int(x + 1); ++i) add_r(i, y + 2);
  for (int i = int(x - 3); i <= int(x - 2); ++i) add_r(i, y + 3);
  for (int i = int(y + 2); i <= int(y + 3); ++i) add_d(x - 4, i);
  add_d(x - 3, y + 2);
}
void block(int x, int y, int v) {
  if (v == 0) {
    add_d(x - 1, y);
  }
  if (v == 1) {
    add_d(x, y);
  }
  if (v == 2) {
    add_d(x + 1, y);
  }
  if (v == 3) {
    add_d(x + 1, y + 1);
  }
  if (v == 4) {
    add_d(x, y + 1);
  }
  if (v == 5) {
  }
}
int main() {
  long long t;
  cin >> t;
  vector<int> ts;
  while (t > 0) ts.push_back(t % 6), t /= 6;
  int x = 4, y = 3;
  initial_framework(ts.back()), ts.pop_back();
  while (!ts.empty()) {
    framework(x, y), block(x - 2, y + 1, ts.back()), ts.pop_back();
    x += 2, y += 2;
  }
  auto tmp = ans;
  ans.clear();
  for (const auto& p : tmp)
    if (p.first.first >= 1 && p.first.second >= 1 && p.second.first <= x &&
        p.second.second <= y) {
      if (to_erase.count(p) == 0) ans.push_back(p);
    }
  printf("%d %d\n", x, y);
  printf("%d\n", static_cast<int>((ans).size()));
  for (const auto& p : ans)
    printf("%d %d %d %d\n", p.first.first, p.first.second, p.second.first,
           p.second.second);
  return 0;
}
