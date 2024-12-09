#include <bits/stdc++.h>
const int INF = std::numeric_limits<int>::max() / 2;
const long long INFLL = std::numeric_limits<long long>::max() / 2;
const int MAX_N = 10005;
int n, p, m, cnt[MAX_N + 10];
std::unordered_map<int, int> min[MAX_N], max[MAX_N];
std::vector<int> adj[MAX_N];
std::string str;
void build_tree() {
  std::stack<int> stk;
  stk.push(0);
  int j = 0;
  for (int i = 1; i < str.size(); ++i) switch (str[i]) {
      case '(':
        adj[stk.top()].push_back(++j);
        stk.push(j);
        break;
      case '?':
        break;
      case ')':
        cnt[stk.top()] = cnt[adj[stk.top()][0]] + cnt[adj[stk.top()][1]] + 1;
        stk.pop();
        break;
      default:
        adj[stk.top()].push_back(MAX_N + str[i] - '0');
    }
}
int maximize(int i, int p);
int minimize(int i, int p) {
  if (i >= MAX_N)
    return i - MAX_N;
  else if (!min[i].count(p)) {
    int &r = min[i][p] = INF;
    int m = cnt[i] - p;
    for (int j = std::max(0, cnt[adj[i][0]] - m);
         j <= std::min(cnt[adj[i][0]], p - 1); ++j)
      r = std::min(r, minimize(adj[i][0], j) + minimize(adj[i][1], p - j - 1));
    for (int j = std::max(0, cnt[adj[i][0]] - m + 1);
         j <= std::min(cnt[adj[i][0]], p); ++j)
      r = std::min(r, minimize(adj[i][0], j) - maximize(adj[i][1], p - j));
  }
  return min[i][p];
}
int maximize(int i, int p) {
  if (i >= MAX_N)
    return i - MAX_N;
  else if (!max[i].count(p)) {
    int &r = max[i][p] = -INF;
    int m = cnt[i] - p;
    for (int j = std::max(0, cnt[adj[i][0]] - m);
         j <= std::min(cnt[adj[i][0]], p - 1); ++j)
      r = std::max(r, maximize(adj[i][0], j) + maximize(adj[i][1], p - j - 1));
    for (int j = std::max(0, cnt[adj[i][0]] - m + 1);
         j <= std::min(cnt[adj[i][0]], p); ++j)
      r = std::max(r, maximize(adj[i][0], j) - minimize(adj[i][1], p - j));
  }
  return max[i][p];
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> str >> p >> m;
  if (str.size() == 1)
    std::cout << str[0] - '0' << '\n';
  else {
    build_tree();
    std::cout << maximize(0, p) << '\n';
  }
  return 0;
}
