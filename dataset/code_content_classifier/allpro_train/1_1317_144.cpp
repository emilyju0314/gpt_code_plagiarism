#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 10;
const int ALPHASIZE = 26;
vector<pair<int, int>> songs[MAXN];
vector<pair<int, int>> queries[MAXN];
vector<int> FailTree[MAXN];
int fail[MAXN];
int ans[MAXN];
int trans[MAXN][ALPHASIZE];
int time_in[MAXN], time_out[MAXN];
int BIT[MAXN];
int Trieidx;
int dfs_time;
int insert(string& pattern) {
  int now = 0;
  for (int i = 0; i < pattern.size(); i++)
    if (trans[now][pattern[i] - 'a'])
      now = trans[now][pattern[i] - 'a'];
    else
      now = trans[now][pattern[i] - 'a'] = ++Trieidx;
  return now;
}
void build() {
  int now = 0;
  queue<int> q;
  for (int i = 0; i < ALPHASIZE; i++)
    if (trans[now][i]) q.push(trans[now][i]);
  while (!q.empty()) {
    now = q.front();
    q.pop();
    for (int i = 0; i < ALPHASIZE; i++) {
      if (trans[now][i]) {
        fail[trans[now][i]] = trans[fail[now]][i];
        q.push(trans[now][i]);
      } else
        trans[now][i] = trans[fail[now]][i];
    }
  }
  for (int i = 1; i <= Trieidx; i++) FailTree[fail[i]].emplace_back(i);
}
void dfs_order(int now) {
  time_in[now] = ++dfs_time;
  for (int nxt : FailTree[now]) dfs_order(nxt);
  time_out[now] = dfs_time;
}
void add(int pos, int val) {
  for (; pos <= dfs_time; pos += pos & -pos) BIT[pos] += val;
}
int sum(int pos) {
  int ret = 0;
  for (; pos; pos -= pos & -pos) ret += BIT[pos];
  return ret;
}
void dfs_solve_query(int Trie_pos, int song_pos) {
  add(time_in[Trie_pos], 1);
  for (auto it : queries[song_pos])
    ans[it.second] = sum(time_out[it.first]) - sum(time_in[it.first] - 1);
  for (auto it : songs[song_pos])
    dfs_solve_query(trans[Trie_pos][it.first], it.second);
  add(time_in[Trie_pos], -1);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1, type, parent; i <= n; i++) {
    char c;
    cin >> type;
    if (type == 1) {
      parent = 0;
      cin >> c;
    } else
      cin >> parent >> c;
    songs[parent].emplace_back(make_pair(c - 'a', i));
  }
  int m;
  cin >> m;
  for (int i = 1, which; i <= m; i++) {
    string pattern;
    cin >> which >> pattern;
    queries[which].emplace_back(make_pair(insert(pattern), i));
  }
  build();
  dfs_order(0);
  dfs_solve_query(0, 0);
  for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}
