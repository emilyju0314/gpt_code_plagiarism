#include <bits/stdc++.h>
template <typename T>
void pMin(T& a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void pMax(T& a, T b) {
  if (b > a) {
    a = b;
  }
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c);
template <typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& c) {
  std::cout << "(" << c.first << ", " << c.second << ")";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c) {
  if (c.size() == 0) {
    os << "{}";
    return os;
  }
  os << "{" << c[0];
  for (int64_t i = 1; i < (int64_t)c.size(); i++) {
    os << ", " << c[i];
  }
  os << "}";
  return os;
}
const int64_t inf = 2e9;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t n;
  cin >> n;
  vector<pair<int64_t, int64_t>> a(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  multiset<pair<double, double>> lines;
  set<int64_t> vert;
  map<double, int64_t> perGradient;
  for (int64_t i = 0; i < n; i++) {
    for (int64_t j = 0; j < i; j++) {
      if (a[i].first == a[j].first) {
        vert.insert(a[i].first);
      } else {
        double gradient = ((double)(a[i].second - a[j].second)) /
                          ((double)(a[i].first - a[j].first));
        double y = ((double)a[i].second) - (gradient * ((double)a[i].first));
        if (lines.find({gradient, y}) == lines.end()) {
          lines.insert({gradient, y});
          perGradient[gradient]++;
        }
      }
    }
  }
  int64_t totalLines = lines.size() + vert.size();
  int64_t totalIntersect = (totalLines * (totalLines - 1ll)) / 2ll;
  if (vert.size()) {
    totalIntersect -= (vert.size() * (vert.size() - 1ll)) / 2ll;
  }
  for (pair<double, int64_t> pdi : perGradient) {
    totalIntersect -= (pdi.second * (pdi.second - 1ll)) / 2ll;
  }
  cout << totalIntersect << "\n";
  return 0;
}
