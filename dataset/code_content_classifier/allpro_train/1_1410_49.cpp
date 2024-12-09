#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct QuickRead {
  QuickRead() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
  }
} quickread;
void dfs(vector<vector<int>>& adj, vector<bool>& visited, int u,
         long long& loop_num) {
  loop_num++;
  visited[u] = true;
  for (auto& v : adj[u]) {
    if (visited[v]) continue;
    dfs(adj, visited, v, loop_num);
  }
}
long long dp_left[2005][4008];
long long dp_right[2005][4008];
long long dp_left_missing[2005][4008];
long long dp_right_missing[2005][4008];
long long ZERO = 2002;
long long solve(vector<long long>& loops) {
  dp_left[0][ZERO] = 1;
  dp_left_missing[0][ZERO] = 1;
  int N = loops.size();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 4008; ++j) {
      dp_left_missing[i + 1][j] += dp_left_missing[i][j];
      dp_left_missing[i + 1][j] %= MOD;
      if (j - loops[i] >= 0) {
        dp_left[i + 1][j - loops[i]] += dp_left[i][j];
        dp_left[i + 1][j - loops[i]] %= MOD;
        dp_left_missing[i + 1][j - loops[i]] += dp_left_missing[i][j];
        dp_left_missing[i + 1][j - loops[i]] %= MOD;
      }
      if (j + loops[i] < 4008) {
        dp_left[i + 1][j + loops[i]] += dp_left[i][j];
        dp_left[i + 1][j + loops[i]] %= MOD;
        dp_left_missing[i + 1][j + loops[i]] += dp_left_missing[i][j];
        dp_left_missing[i + 1][j + loops[i]] %= MOD;
      }
    }
  }
  dp_right[N][ZERO] = 1;
  dp_right_missing[N][ZERO] = 1;
  for (int i = N - 1; i >= 0; --i) {
    for (int j = 0; j < 4008; ++j) {
      dp_right_missing[i][j] += dp_right_missing[i + 1][j];
      dp_right_missing[i][j] %= MOD;
      if (j - loops[i] >= 0) {
        dp_right[i][j - loops[i]] += dp_right[i + 1][j];
        dp_right[i][j - loops[i]] %= MOD;
        dp_right_missing[i][j - loops[i]] += dp_right_missing[i + 1][j];
        dp_right_missing[i][j - loops[i]] %= MOD;
      }
      if (j + loops[i] < 4008) {
        dp_right[i][j + loops[i]] += dp_right[i + 1][j];
        dp_right[i][j + loops[i]] %= MOD;
        dp_right_missing[i][j + loops[i]] += dp_right_missing[i + 1][j];
        dp_right_missing[i][j + loops[i]] %= MOD;
      }
    }
  }
  long long ret = 0;
  ret += dp_left[N][ZERO];
  ret %= MOD;
  for (int i = 0; i < N; ++i) {
    long long ret_equal = 0;
    for (int j = 0; j < 4008; ++j) {
      int right_pos = 2 * ZERO - j;
      if (right_pos >= 0 && right_pos < 4008) {
        ret_equal +=
            (dp_left_missing[i][j] * dp_right_missing[i + 1][right_pos]);
        ret_equal %= MOD;
      }
    }
    ret += ret_equal * 2;
    ret %= MOD;
    for (int k = 1; k <= loops[i] - 2; ++k) {
      long long ret_inner = 0;
      for (int j = 0; j < 4008; ++j) {
        int right_pos = 2 * ZERO - j + k;
        if (right_pos >= 0 && right_pos < 4008) {
          ret_inner +=
              (dp_left_missing[i][j] * dp_right_missing[i + 1][right_pos]);
          ret_inner %= MOD;
        }
      }
      ret += ret_inner * 4;
      ret %= MOD;
    }
    long long ret_diff_1 = 0;
    for (int j = 0; j < 4008; ++j) {
      int right_pos = 2 * ZERO - j + loops[i] - 1;
      if (right_pos >= 0 && right_pos < 4008) {
        ret_diff_1 += (dp_left[i][j] * dp_right[i + 1][right_pos]);
        ret_diff_1 %= MOD;
      }
    }
    ret += ret_diff_1 * 4;
    ret %= MOD;
  }
  return ret;
}
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  vector<long long> loops;
  vector<bool> visited(N, false);
  visited[0] = true;
  for (auto& v : adj[0]) {
    if (visited[v]) continue;
    loops.push_back(1);
    dfs(adj, visited, v, loops.back());
  }
  cout << solve(loops) << "\n";
  return 0;
}
