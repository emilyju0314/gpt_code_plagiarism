#include <bits/stdc++.h>
using namespace std;
template <class htpe, class cmp>
using heap = priority_queue<htpe, vector<htpe>, cmp>;
template <class htpe>
using min_heap = heap<htpe, greater<htpe> >;
template <class htpe>
using max_heap = heap<htpe, less<htpe> >;
const int INF = 1791791791;
const long long INFLL = 1791791791791791791ll;
template <int input_buf_size, int output_buf_size>
class FastIO {
  char cbuf[input_buf_size + 1];
  int icur = 0;
  inline bool go_to_next_token() {
    while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
    while (cbuf[icur] == 0) {
      icur = 0;
      if (fgets(cbuf, sizeof(cbuf), stdin) != cbuf) return false;
      while (cbuf[icur] == ' ' || cbuf[icur] == '\n') icur++;
    }
    return true;
  }

 public:
  string readString() {
    assert(go_to_next_token());
    string ans;
    while (cbuf[icur] != ' ' && cbuf[icur] != '\n' && cbuf[icur] != 0)
      ans.push_back(cbuf[icur++]);
    ans.shrink_to_fit();
    return ans;
  }
  template <class int_type>
  int_type readInt() {
    assert(go_to_next_token());
    int_type x = 0;
    bool m = cbuf[icur] == '-';
    if (m) icur++;
    while ('0' <= cbuf[icur] && cbuf[icur] <= '9') {
      x *= 10;
      x += (cbuf[icur] - '0');
      icur++;
    }
    if (m) x = -x;
    return x;
  }
  bool seekEof() { return !go_to_next_token(); }

 private:
  char obuf[output_buf_size + 1];
  int ocur = 0;
  inline void write_string(const char *str, size_t sz = 0) {
    if (sz == 0) sz = strlen(str);
    if (ocur + sz > output_buf_size) {
      fputs(obuf, stdout);
      fputs(str, stdout);
      ocur = 0;
      obuf[0] = 0;
      return;
    }
    strcpy(obuf + ocur, str);
    ocur += sz;
    obuf[ocur] = 0;
  }

 public:
  template <class int_type>
  void writeInt(int_type x, bool sp = true) {
    char buf[21];
    int c = 0;
    if (x < 0) {
      buf[c++] = '-';
      x = -x;
    }
    int s = c;
    if (x == 0) {
      buf[c++] = '0';
    }
    while (x > 0) {
      buf[c++] = (x % 10) + '0';
      x /= 10;
    }
    for (int i = 0; 2 * i < c - s; i++) {
      swap(buf[s + i], buf[c - 1 - i]);
    }
    buf[c] = 0;
    write_string(buf, c);
    if (sp) write_string(" ", 1);
  }
  void writeString(string s, bool space = true) {
    write_string(s.c_str(), s.size());
    if (space) write_string(" ", 1);
  }
  void writeEndl() { write_string("\n", 1); }
  void flush() {
    fputs(obuf, stdout);
    ocur = 0;
    obuf[0] = 0;
  }

 private:
  bool lflush;

 public:
  FastIO(bool local_flush) {
    obuf[0] = 0;
    lflush = local_flush;
  }
  ~FastIO() { fputs(obuf, stdout); }
};
FastIO<10000000, 10000000> IO(true);
const int maxn = 1e5 + 179;
vector<pair<int, int> > clauses;
struct edge {
  int u;
  bool su;
  int v;
  bool sv;
  edge(int _u, int _v) {
    u = abs(_u);
    v = abs(_v);
    su = _u < 0;
    sv = _v < 0;
  }
};
vector<edge> adj[maxn];
bool vis[maxn];
vector<array<long long, 2> > components;
const long long MOD = 1e9 + 7;
void solve_bamboo(int start) {
  if (adj[start].empty()) {
    components.push_back({2, 0});
    return;
  }
  vector<int> bamboo = {start};
  vector<edge> es;
  int last = -1;
  int v = start;
  vis[v] = true;
  while (v == start || adj[v].size() == 2) {
    if (v == last && (v != start || adj[v].size() == 1)) break;
    if (last == -1 && adj[v][0].v == v) {
      es.push_back(adj[v][0]);
      tie(last, v) = make_pair(v, adj[v][0].v);
    } else if (last == -1 && adj[v].size() == 2 && adj[v][1].v == v) {
      es.push_back(adj[v][1]);
      tie(last, v) = make_pair(v, adj[v][1].v);
    } else if (adj[v][0].v != last) {
      es.push_back(adj[v][0]);
      tie(last, v) = make_pair(v, adj[v][0].v);
    } else {
      es.push_back(adj[v][1]);
      tie(last, v) = make_pair(v, adj[v][1].v);
    }
    assert(v == last || !vis[v]);
    vis[v] = true;
    bamboo.push_back(v);
  }
  long long dp[2][2];
  dp[0][0] = dp[0][1] = 1;
  dp[1][0] = dp[1][1] = 0;
  for (int i = 0; i < ((int)(es.size())); ++i) {
    long long ndp[2][2];
    if (es[i].u == es[i].v) {
      ndp[0][es[i].sv] = dp[1][es[i].sv];
      ndp[0][!es[i].sv] = dp[0][!es[i].sv];
      ndp[1][es[i].sv] = dp[0][es[i].sv];
      ndp[1][!es[i].sv] = dp[1][!es[i].sv];
    } else if (es[i].sv) {
      ndp[0][0] = (dp[0][!es[i].su] + dp[1][es[i].su]) % MOD;
      ndp[1][0] = (dp[1][!es[i].su] + dp[0][es[i].su]) % MOD;
      ndp[0][1] = (dp[1][0] + dp[1][1]) % MOD;
      ndp[1][1] = (dp[0][0] + dp[0][1]) % MOD;
    } else {
      ndp[0][0] = (dp[1][0] + dp[1][1]) % MOD;
      ndp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
      ndp[0][1] = (dp[0][!es[i].su] + dp[1][es[i].su]) % MOD;
      ndp[1][1] = (dp[1][!es[i].su] + dp[0][es[i].su]) % MOD;
    }
    tie(dp[0][0], dp[0][1]) = make_pair(ndp[0][0], ndp[0][1]);
    tie(dp[1][0], dp[1][1]) = make_pair(ndp[1][0], ndp[1][1]);
  }
  components.push_back(
      {(dp[0][0] + dp[0][1]) % MOD, (dp[1][0] + dp[1][1]) % MOD});
}
void solve_cycle(int start) {
  vector<int> cycle;
  vector<edge> es;
  int last = -1;
  int v = start;
  vis[v] = true;
  while (es.empty() || v != start) {
    if (adj[v][0].v != last) {
      es.push_back(adj[v][0]);
      tie(last, v) = make_pair(v, adj[v][0].v);
    } else {
      es.push_back(adj[v][1]);
      tie(last, v) = make_pair(v, adj[v][1].v);
    }
    assert(v == start || !vis[v]);
    vis[v] = true;
    cycle.push_back(v);
  }
  array<long long, 2> ans = {0, 0};
  for (int f = 0; f < ((int)(2)); ++f) {
    long long dp[2][2];
    dp[0][0] = dp[0][1] = dp[1][0] = dp[1][1] = 0;
    dp[0][f] = 1;
    for (int i = 0; i < ((int)(es.size())); ++i) {
      long long ndp[2][2];
      if (es[i].sv) {
        ndp[0][0] = (dp[0][!es[i].su] + dp[1][es[i].su]) % MOD;
        ndp[1][0] = (dp[1][!es[i].su] + dp[0][es[i].su]) % MOD;
        ndp[0][1] = (dp[1][0] + dp[1][1]) % MOD;
        ndp[1][1] = (dp[0][0] + dp[0][1]) % MOD;
      } else {
        ndp[0][0] = (dp[1][0] + dp[1][1]) % MOD;
        ndp[1][0] = (dp[0][0] + dp[0][1]) % MOD;
        ndp[0][1] = (dp[0][!es[i].su] + dp[1][es[i].su]) % MOD;
        ndp[1][1] = (dp[1][!es[i].su] + dp[0][es[i].su]) % MOD;
      }
      tie(dp[0][0], dp[0][1]) = make_pair(ndp[0][0], ndp[0][1]);
      tie(dp[1][0], dp[1][1]) = make_pair(ndp[1][0], ndp[1][1]);
    }
    ans[0] = (ans[0] + dp[0][f]) % MOD;
    ans[1] = (ans[1] + dp[1][f]) % MOD;
  }
  components.push_back(ans);
}
void solve(int v) {
  if (adj[v].empty() || (adj[v].size() == 1 && adj[v][0].u == adj[v][0].v)) {
    solve_bamboo(v);
  } else {
    int u = adj[v][0].v;
    int last = v;
    while (adj[u].size() == 2 && u != v) {
      if (u == last) break;
      if (adj[u][0].v != last)
        tie(last, u) = make_pair(u, adj[u][0].v);
      else
        tie(last, u) = make_pair(u, adj[u][1].v);
    }
    if (last != u && u == v)
      solve_cycle(v);
    else
      solve_bamboo(u);
  }
}
bool val(vector<bool> vals) {
  bool ans = 0;
  for (auto p : clauses) {
    int u, v;
    tie(u, v) = p;
    u = abs(u);
    v = abs(v);
    u--;
    v--;
    bool vu = p.first < 0 ? !vals[u] : vals[u];
    bool vv = p.second < 0 ? !vals[v] : vals[v];
    ans ^= (vu | vv);
  }
  return ans;
}
long long brute(int m) {
  long long ans = 0;
  for (long long mask = 0; mask < (1ll << m); mask++) {
    vector<bool> expand(m);
    for (int i = 0; i < ((int)(m)); ++i) expand[i] = (mask >> i) & 1;
    ans += val(expand);
  }
  return ans % MOD;
}
bool fend = 1;
bool block[maxn];
void add_loop(int u) {
  if (adj[abs(u)].size() == 1 && adj[abs(u)][0].v == abs(u)) {
    if (adj[abs(u)][0].sv != edge(u, u).sv) fend ^= 1;
    adj[abs(u)].clear();
  } else
    adj[abs(u)].push_back(edge(u, u));
}
void add_edge(int u, int v) {
  adj[abs(u)].push_back(edge(u, v));
  if (abs(u) != abs(v)) adj[abs(v)].push_back(edge(v, u));
}
int main() {
  int n = IO.readInt<int>();
  int m = IO.readInt<int>();
  clauses.resize(n);
  for (int i = 0; i < ((int)(n)); ++i) {
    int k = IO.readInt<int>();
    if (k == 1) {
      int u = IO.readInt<int>();
      clauses[i] = make_pair(u, u);
      add_loop(u);
    } else {
      int u = IO.readInt<int>();
      int v = IO.readInt<int>();
      clauses[i] = make_pair(u, v);
      if (abs(u) == abs(v)) {
        if (u == v)
          add_loop(u);
        else
          fend ^= 1;
      } else
        add_edge(u, v);
    }
  }
  for (int i = (int)(1); i < ((int)(m + 1)); ++i)
    if (!vis[i]) {
      solve(i);
    }
  array<long long, 2> dp = {1, 0};
  for (auto p : components) {
    array<long long, 2> ndp;
    ndp[0] = (dp[0] * p[0] + dp[1] * p[1]) % MOD;
    ndp[1] = (dp[1] * p[0] + dp[0] * p[1]) % MOD;
    dp = ndp;
  }
  IO.writeInt(dp[fend]);
  IO.writeEndl();
  return 0;
}
