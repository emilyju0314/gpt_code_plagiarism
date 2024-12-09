#include <bits/stdc++.h>
using namespace std;
struct AhoCorasick {
  enum { alpha = 26, first = 'a' };
  struct Node {
    int back, next[alpha], nmatches = 0;
    Node(int v) { memset(next, v, sizeof(next)); }
  };
  vector<Node> N;
  AhoCorasick() {}
  AhoCorasick(vector<string>::iterator st, vector<string>::iterator en)
      : N(1, -1) {
    for (auto& s = st; s != en; s = next(s)) {
      int n = 0;
      for (char& c : *s) {
        int& m = N[n].next[c - first];
        if (m == -1) {
          n = m = N.size();
          N.emplace_back(-1);
        } else
          n = m;
      }
      N[n].nmatches++;
    }
    N[0].back = N.size();
    N.emplace_back(0);
    for (queue<int> q{{0}}; !q.empty(); q.pop()) {
      int n = q.front(), prev = N[n].back;
      for (int i = 0; i < alpha; i++) {
        int &ed = N[n].next[i], y = N[prev].next[i];
        if (ed == -1)
          ed = y;
        else {
          N[ed].back = y;
          N[ed].nmatches += N[y].nmatches;
          q.push(ed);
        }
      }
    }
  }
  long long count(string& s) {
    int n = 0;
    long long cnt = 0;
    for (char& c : s) {
      n = N[n].next[c - first];
      cnt += N[n].nmatches;
    }
    return cnt;
  }
};
struct Dynamic_AC {
  int n = 0;
  vector<string> inds;
  vector<AhoCorasick> sets;
  void insert(string& s) {
    inds.push_back(s), n++;
    if (!(n & (n - 1))) sets.push_back(AhoCorasick());
    sets[__builtin_ctz(n)] = AhoCorasick(inds.end() - (n & -n), inds.end());
  }
  long long count(string& s) {
    long long res = 0;
    for (int i = 0; i < sets.size(); i++)
      if (n >> i & 1) res += sets[i].count(s);
    return res;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, t;
  string s;
  cin >> q;
  Dynamic_AC in, out;
  while (q--) {
    cin >> t >> s;
    if (t == 1)
      in.insert(s);
    else if (t == 2)
      out.insert(s);
    else
      cout << in.count(s) - out.count(s) << endl;
  }
}
