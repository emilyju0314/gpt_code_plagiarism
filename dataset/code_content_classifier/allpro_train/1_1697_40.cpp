#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long LINF = 1e18;
int n;
vector<vector<string>> v;
vector<vector<int>> gr, gt;
unordered_map<string, vector<int>> m;
vector<int> comp, order;
int cur = 1;
void build_gr() {
  for (int i = 0; i < n; i++) {
    string s1 = v[i][0];
    string s2 = v[i][1];
    for (auto j : m[s1]) {
      if (2 * i == j) continue;
      if (j % 2 == 1) {
        gr[2 * i].push_back(j - 1);
        gt[j - 1].push_back(2 * i);
      } else {
        gr[2 * i].push_back(j + 1);
        gt[j + 1].push_back(2 * i);
        gr[2 * i + 1].push_back(j + 1);
        gt[j + 1].push_back(2 * i + 1);
      }
    }
    for (auto j : m[s2]) {
      if (j == 2 * i + 1) continue;
      if (j % 2 == 1) {
        gr[2 * i + 1].push_back(j - 1);
        gt[j - 1].push_back(2 * i + 1);
      } else {
        gr[2 * i + 1].push_back(j + 1);
        gt[j + 1].push_back(2 * i + 1);
      }
    }
  }
}
vector<bool> used;
void dfs1(int x) {
  used[x] = 1;
  for (auto i : gr[x]) {
    if (!used[i]) dfs1(i);
  }
  order.push_back(x);
}
void dfs2(int x) {
  comp[x] = cur;
  for (auto i : gt[x]) {
    if (!comp[i]) dfs2(i);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  v.resize(n, vector<string>(2));
  gr.resize(2 * n);
  gt.resize(2 * n);
  comp.resize(2 * n);
  used.resize(2 * n);
  for (int i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    v[i][0] = a.substr(0, 3);
    v[i][1] = a.substr(0, 2);
    v[i][1].push_back(b[0]);
    m[v[i][0]].push_back(2 * i);
    m[v[i][1]].push_back(2 * i + 1);
  }
  build_gr();
  for (int i = 0; i < 2 * n; i++) {
    if (!used[i]) dfs1(i);
  }
  for (int i = order.size() - 1; i >= 0; i--) {
    if (!comp[order[i]]) {
      dfs2(order[i]);
      cur++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (comp[2 * i] == comp[2 * i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES"
       << "\n";
  for (int i = 0; i < n; i++) {
    if (comp[2 * i] > comp[2 * i + 1])
      cout << v[i][0] << "\n";
    else
      cout << v[i][1] << "\n";
  }
  return 0;
}
