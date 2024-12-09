#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int alpha = 26;
struct Node {
  int child[alpha];
  bool done;
  int depth, back;
  Node() {
    for (int i = 0; i < alpha; i++) child[i] = 0;
    done = false;
    depth = 0;
    back = 0;
  }
};
struct AhoCorasick {
  vector<struct Node> trie;
  vector<vector<int>> store;
  int siz;
  AhoCorasick(int n) {
    trie.emplace_back();
    siz = n;
    for (int i = 0; i <= siz; i++) {
      vector<int> temp;
      store.push_back(temp);
      for (int j = 0; j < alpha; j++) store[i].push_back(-1);
    }
  }
  int getchild(int node, int target) {
    if (trie[node].child[target] == 0) {
      trie[node].child[target] = trie.size();
      trie.emplace_back();
      trie[trie.size() - 1].depth = trie[node].depth + 1;
    }
    return trie[node].child[target];
  }
  void insert(string S) {
    int cur = 0;
    for (int i = 0; i < (int)S.length(); i++)
      cur = getchild(cur, (int)(S[i] - 'a'));
    trie[cur].done = true;
  }
  void process() {
    queue<int> q;
    vector<int> v;
    q.push(0);
    while (!q.empty()) {
      int X = q.front();
      q.pop();
      if (X != 0) v.push_back(X);
      for (int i = 0; i < alpha; i++) {
        if (trie[X].child[i] != 0) q.push(trie[X].child[i]);
      }
    }
    for (int i : v) {
      for (int j = 0; j < alpha; j++) {
        int cur = trie[i].back;
        while (trie[cur].child[j] == 0 && cur != 0) {
          if (store[cur][j] != -1) {
            cur = store[cur][j];
            break;
          }
          cur = trie[cur].back;
        }
        int temp = trie[i].back;
        while (trie[temp].child[j] == 0 && temp != 0) {
          if (store[temp][j] != -1) break;
          store[temp][j] = cur;
        }
        cur = trie[cur].child[j];
        if (trie[i].child[j] != 0)
          trie[trie[i].child[j]].back = cur;
        else
          trie[i].child[j] = cur;
      }
    }
    for (int i : v) trie[i].done = trie[i].done | trie[trie[i].back].done;
  }
};
string S, T;
vector<vector<int>> dp;
int main() {
  cin >> S >> T;
  AhoCorasick ac = AhoCorasick((int)T.length());
  ac.insert(T);
  ac.process();
  int N = S.length();
  int M = T.length();
  for (int i = 0; i <= N; i++) {
    vector<int> v;
    dp.push_back(v);
    for (int j = 0; j <= M + 1; j++) dp[i].push_back(-2001001001);
  }
  dp[0][0] = 0;
  for (int i = 0; i < N; i++)
    for (int j = 0; j <= M; j++) {
      if (S[i] != '?') {
        int nextChild = ac.trie[j].child[(int)(S[i] - 'a')];
        dp[i + 1][nextChild] =
            max(dp[i + 1][nextChild], dp[i][j] + (ac.trie[nextChild].done));
      } else {
        for (int k = 0; k < 26; k++) {
          int nextChild = ac.trie[j].child[k];
          dp[i + 1][nextChild] =
              max(dp[i + 1][nextChild], dp[i][j] + (ac.trie[nextChild].done));
        }
      }
    }
  int ans = 0;
  for (int j = 0; j <= M; j++) ans = max(ans, dp[N][j]);
  cout << ans << endl;
  return 0;
}
