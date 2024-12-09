#include <bits/stdc++.h>

/* -------------------------------- Template -------------------------------- */

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

template<typename T> T inf() { assert(false); }
template<> constexpr int inf<int>() { return 1e9; }
template<> constexpr ll inf<ll>() { return 1e18; }
template<> constexpr ld inf<ld>() { return 1e30; }

/* -------------------------------- Library -------------------------------- */

struct Trie {
  static const int SIZE = 32;
  struct State {
    int index, next[SIZE];
    State(int index) : index(index) { memset(next, -1, sizeof(next)); }
  };

  vector<State> pma;
  vector<int> cnt;
  vector<int> acc;

  void dfs(int v) {
    int res = 0;
    REP(i,SIZE) {
      int nv = pma[v].next[i];
      if (nv != -1) {
        dfs(nv);
        res += cnt[nv];
      }
    }
    cnt[v] += res;
  }

  Trie(const vector<string> &str) {
    pma.clear();
    pma.push_back(State(0));
    cnt.clear();
    cnt.push_back(0);
    acc.clear();
    acc.push_back(0);

    REP(i,str.size()) {
      int t = 0;
      for (char cc : str[i]) {
        int c = cc - 'a';
        if (pma[t].next[c] == -1) {
          int m = pma.size();
          pma[t].next[c] = m;
          pma.push_back(State(m));
          cnt.push_back(0);
          acc.push_back(0);
        }
        t = pma[t].next[c];
      }
      ++cnt[t];
      ++acc[t];
    }
    dfs(0);
  }

  pair<vector<vector<int>>,int> query(const string &str) {
    vector<vector<int>> table(26, vector<int>(26, 0));
    int res = 1;
    int st = 0;
    REP(i,str.size()) {
      res += acc[st];
      REP(j,SIZE) {
        int nst = pma[st].next[j];
        if (nst != -1)
          table[str[i] - 'a'][j] += cnt[nst];
      }
      st = pma[st].next[str[i] - 'a'];
    }
    return make_pair(table, res);
  }
};

/* ---------------------------------- Main ---------------------------------- */

int main() {
  int N, Q;
  cin >> N;
  vector<string> strs(N);
  REP(i,N) cin >> strs[i];
  Trie trie(strs);

  vector<pair<vector<vector<int>>,int>> pre(N);
  REP(i,N) pre[i] = trie.query(strs[i]);

  cin >> Q;
  REP(i,Q) {
    int k; string ord;
    cin >> k >> ord; --k;
    int res = pre[k].second;
    REP(i,26) REP(j,i) {
      int from = ord[i] - 'a';
      int to   = ord[j] - 'a';
      res += pre[k].first[from][to];
    }
    cout << res << endl;
  }
  return 0;
}
