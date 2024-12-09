#include <bits/stdc++.h>
using namespace std;
int solve();
int main() { solve(); }
const int BUFSZ = (int)1e5 + 7;
char buf[BUFSZ];
string get_str() {
  scanf(" %s", buf);
  return string(buf);
}
struct Node {
  vector<int> nxt;
  int t;
  Node() { nxt.assign(5, -1), t = 0; };
};
struct Trie {
  vector<int> was;
  int it;
  vector<Node> t;
  Trie() { t.push_back(Node()), was.push_back(0), it = 0; };
  void add(string &s) {
    int u = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      if (t[u].nxt[s[i] - 'a'] == -1) {
        t[u].nxt[s[i] - 'a'] = t.size();
        t.push_back(Node());
        was.push_back(0);
      }
      u = t[u].nxt[s[i] - 'a'];
    }
    ++t[u].t;
  }
  int get(string &s) {
    queue<int> q;
    q.push(0);
    for (size_t c = 0; c < s.size(); ++c) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        int u = q.front();
        q.pop();
        if (s[c] != '?') {
          if (t[u].nxt[s[c] - 'a'] != -1) {
            q.push(t[u].nxt[s[c] - 'a']);
          }
        } else {
          q.push(u);
          for (int i = 0; i < 5; ++i) {
            if (t[u].nxt[i] != -1) {
              q.push(t[u].nxt[i]);
            }
          }
        }
      }
    }
    int ans = 0;
    ++it;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (was[u] != it) {
        ans += t[u].t;
        was[u] = it;
      }
    }
    return ans;
  }
};
int solve() {
  int n, q;
  scanf("%d %d", &n, &q);
  Trie T;
  for (int i = 0; i < n; ++i) {
    string s = get_str();
    T.add(s);
  }
  for (int i = 0; i < q; ++i) {
    string s = get_str();
    printf("%d\n", T.get(s));
  }
  return 0;
}
