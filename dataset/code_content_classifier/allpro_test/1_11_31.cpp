#include <bits/stdc++.h>
using namespace std;
template <typename T>
T max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <typename T>
T max4(T a, T b, T c, T d) {
  return max(max(a, d), max(b, c));
}
template <typename T>
T min3(T a, T b, T c) {
  return min(a, min(b, c));
}
template <typename T>
T min4(T a, T b, T c, T d) {
  return min(min(a, d), min(b, c));
}
template <typename T>
T binex(T a, T b, T mod) {
  T ans = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) {
      ans *= a;
      ans %= mod;
    }
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ans;
}
template <class T>
ostream &operator<<(ostream &os, vector<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T>
ostream &operator<<(ostream &os, multiset<T> a) {
  for (auto x : a) {
    os << x << " ";
  }
  return os;
}
template <class T, class Q>
ostream &operator<<(ostream &os, pair<T, Q> a) {
  os << "| ";
  os << a.first << ", " << a.second << " ";
  return os << "|";
}
template <class P, class Q, class T>
ostream &operator<<(ostream &os, tuple<P, Q, T> a) {
  os << "| " << (get<0>(a)) << ", " << (get<1>(a)) << ", " << (get<2>(a))
     << "|";
  return os;
}
void precomp() {}
bool comp(pair<int64_t, int64_t> &a, pair<int64_t, int64_t> &b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first > b.first) {
    return false;
  } else {
    return a.second > b.second;
  }
}
void solve() {
  int64_t n;
  cin >> n;
  vector<pair<int64_t, int64_t>> a(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1 - a[i].first;
  }
  sort(a.begin(), a.end(), comp);
  vector<int64_t> sto;
  sto.push_back(0);
  for (int64_t i = 0; i < n; i++) {
    if (a[i].second < 0) {
      continue;
    }
    if (sto.back() <= a[i].second) {
      sto.push_back(a[i].second);
    } else {
      int64_t ind = 0;
      while (ind < sto.size()) {
        if (sto[ind] <= a[i].second) {
          ind++;
        } else {
          break;
        }
      }
      sto[ind] = a[i].second;
    }
  }
  cout << sto.size() - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int64_t T;
  T = 1;
  precomp();
  for (int64_t I = 1; I <= T; I++) {
    solve();
  }
}
