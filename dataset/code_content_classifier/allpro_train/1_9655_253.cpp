#include <bits/stdc++.h>
using namespace std;
template <int POS, class TUPLE>
void deploy(std::ostream &os, const TUPLE &tuple) {}
template <int POS, class TUPLE, class H, class... Ts>
void deploy(std::ostream &os, const TUPLE &t) {
  os << (POS == 0 ? "" : ", ") << get<POS>(t);
  deploy<POS + 1, TUPLE, Ts...>(os, t);
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "}" : ", ");
  return os;
}
template <class T>
std::ostream &operator<<(std::ostream &os, std::set<T> &v) {
  int remain = v.size();
  os << "{";
  for (auto e : v) os << e << (--remain == 0 ? "}" : ", ");
  return os;
}
template <class T, class K>
std::ostream &operator<<(std::ostream &os, std::map<T, K> &make_pair) {
  int remain = make_pair.size();
  os << "{";
  for (auto e : make_pair)
    os << "(" << e.first << " -> " << e.second << ")"
       << (--remain == 0 ? "}" : ", ");
  return os;
}
int n;
vector<int> edges[100100];
bool color[100100];
long long memo[100100][2];
void dfs(int now) {
  memo[now][0] = 1;
  memo[now][1] = 0;
  for (auto u : edges[now]) {
    dfs(u);
    memo[now][1] *= memo[u][0];
    memo[now][1] %= 1000000007LL;
    memo[now][1] += (memo[now][0] * memo[u][1]) % 1000000007LL;
    memo[now][1] %= 1000000007LL;
    memo[now][0] *= memo[u][0];
    memo[now][0] %= 1000000007LL;
  }
  if (color[now]) {
    memo[now][1] = memo[now][0];
  } else {
    memo[now][0] += memo[now][1];
    memo[now][0] %= 1000000007LL;
  }
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < (n); i++) {
    int x;
    cin >> x;
    edges[x].push_back(i);
  }
  for (int i = 0; i < (n); i++) {
    cin >> color[i];
  }
  dfs(0);
  cout << memo[0][1] << "\n";
  return 0;
}
