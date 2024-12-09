#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long double EPS = 1e-9;
template <class second, class T>
ostream& operator<<(ostream& os, const pair<second, T>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const unordered_set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class second, class T>
ostream& operator<<(ostream& os, const unordered_map<second, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const set<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, const multiset<T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class second, class T>
ostream& operator<<(ostream& os, const map<second, T>& p) {
  os << "[ ";
  for (auto& it : p) os << it << " ";
  return os << "]";
}
template <class T>
void dbs(string str, T t) {
  cerr << str << " : " << t << "\n";
}
template <class T, class... second>
void dbs(string str, T t, second... s) {
  long long idx = str.find(',');
  cerr << str.substr(0, idx) << " : " << t << ",";
  dbs(str.substr(idx + 1), s...);
}
template <class T>
void prc(T a, T b) {
  cerr << "[";
  for (T i = a; i != b; ++i) {
    if (i != a) cerr << ", ";
    cerr << *i;
  }
  cerr << "]\n";
}
long long binpow(long long b, long long p, long long mod) {
  long long ans = 1;
  for (; p; p >>= 1) {
    if (p & 1) ans = ans * b % mod;
    b = b * b % mod;
  }
  return ans;
}
void pre() {}
struct Fen {
  vector<long long> ft;
  Fen(long long i = 0) { ft.assign(i + 1, 0); }
  long long rsq(long long b) {
    long long sumer = 0;
    for (; b > 0; b -= (b & (-b))) sumer += ft[b];
    return sumer;
  }
  void addat(long long k, long long v) {
    for (; k < (long long)ft.size(); k += (k & (-k))) ft[k] += v;
  }
};
struct node {
  int suff_link, par;
  char c;
  map<char, int> go;
  vector<long long> SuffixChild;
  node() { suff_link = -1, par = -1; }
};
struct AhoCorasickAdvanced {
  vector<node> trie;
  int curTime;
  AhoCorasickAdvanced() {
    curTime = 1;
    trie.clear();
    node root;
    root.suff_link = 0;
    trie.push_back(root);
  }
  int add_string(string s, int pos) {
    int cur_node = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
      int go = trie[cur_node].go[s[i]];
      if (go == 0) {
        node add;
        add.par = cur_node;
        add.c = s[i];
        trie.push_back(add);
        go = (long long)trie.size() - 1;
        trie[cur_node].go[s[i]] = go;
      }
      cur_node = go;
    }
    return cur_node;
  }
  int getSuffLink(int cur_node) {
    if (trie[cur_node].suff_link != -1) return trie[cur_node].suff_link;
    if (trie[cur_node].par == 0) return trie[cur_node].suff_link = 0;
    char c = trie[cur_node].c;
    int parent = trie[cur_node].par;
    return trie[cur_node].suff_link = go(trie[parent].suff_link, c);
  }
  int go(int cur_node, char c) {
    if (trie[cur_node].go.count(c) > 0) return trie[cur_node].go[c];
    if (cur_node == 0) return trie[cur_node].go[c] = 0;
    int suff_link = getSuffLink(cur_node);
    return trie[cur_node].go[c] = go(suff_link, c);
  }
  void buildSuffix() {
    vector<long long> bfs;
    bfs.emplace_back(0);
    int cur = 0;
    while (cur < bfs.size()) {
      int cur_node = bfs[cur];
      cur++;
      for (auto it : trie[cur_node].go) {
        bfs.emplace_back(it.second);
      }
      int suff_link = getSuffLink(cur_node);
      trie[cur_node].suff_link = suff_link;
      trie[suff_link].SuffixChild.emplace_back(cur_node);
    }
  }
  vector<long long> inTime, outTime;
  Fen pathSum;
  vector<long long> curval;
  void dfs(int nn) {
    inTime[nn] = curTime++;
    for (auto v : trie[nn].SuffixChild) {
      if (v != nn) dfs(v);
    }
    outTime[nn] = curTime++;
  }
  void delta(int x, int d) {
    if ((d == -1 && curval[x] == 1) || (d == 1 && curval[x] == 0)) {
      pathSum.addat(inTime[x], d);
      pathSum.addat(outTime[x], -d);
      curval[x] += d;
    }
  }
  void init_eulerTour() {
    inTime = outTime = curval = vector<long long>(2 * (trie.size() + 2));
    pathSum = Fen(2 * (trie.size() + 2));
    dfs(0);
  }
  vector<long long> marknode;
  void Prepare(vector<string> arr) {
    marknode = vector<long long>(arr.size());
    for (long long i = 0; i < arr.size(); ++i) {
      marknode[i] = add_string(arr[i], 0);
    }
    buildSuffix();
    init_eulerTour();
  }
  void activate(int i) { delta(marknode[i], 1); }
  void deactivate(int i) { delta(marknode[i], -1); }
  long long getCnt(string s) {
    long long ans = 0;
    int cur = 0;
    for (int i = 0; i < s.length(); i++) {
      cur = go(cur, s[i]);
      ans += pathSum.rsq(inTime[cur]);
    }
    return ans;
  }
};
AhoCorasickAdvanced aho;
void solve() {
  long long n, k;
  cin >> n >> k;
  std::vector<string> v(k);
  for (long long i = 0; i < k; ++i) {
    cin >> v[i];
  }
  aho.Prepare(v);
  for (long long i = 0; i < k; ++i) {
    aho.activate(i);
  }
  for (long long i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    if (ch == '+') {
      int x;
      cin >> x;
      aho.activate(x - 1);
    } else if (ch == '-') {
      int x;
      cin >> x;
      aho.deactivate(x - 1);
    } else {
      string s;
      cin >> s;
      cout << aho.getCnt(s) << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre();
  long long t = 1;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
