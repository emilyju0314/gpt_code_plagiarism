#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 3;
const int MOD2 = 1e9 + 7;
struct Hash {
  Hash(int x) : first(x % MOD1), second(x % MOD2) {}
  Hash() : first(0), second(0) {}
  int first;
  int second;
};
const Hash P = Hash(31);
bool operator<(const Hash& lhs, const Hash& rhs) {
  return lhs.first < rhs.first ||
         (lhs.first == rhs.first && lhs.second < rhs.second);
}
bool operator==(const Hash& lhs, const Hash& rhs) {
  return lhs.first == rhs.first && lhs.second == rhs.second;
}
Hash& operator*=(Hash& lhs, const Hash& rhs) {
  lhs.first = (1LL * lhs.first * rhs.first) % MOD1;
  lhs.second = (1LL * lhs.second * rhs.second) % MOD2;
  return lhs;
}
Hash operator*(const Hash& lhs, const Hash& rhs) {
  Hash result(lhs);
  result *= rhs;
  return result;
}
Hash& operator+=(Hash& lhs, const Hash& rhs) {
  lhs.first += rhs.first;
  if (lhs.first >= MOD1) {
    lhs.first -= MOD1;
  }
  lhs.second += rhs.second;
  if (lhs.second >= MOD2) {
    lhs.second -= MOD2;
  }
  return lhs;
}
Hash operator+(const Hash& lhs, const Hash& rhs) {
  Hash result(lhs);
  result += rhs;
  return result;
}
const int MAX_N = 3e5 + 100;
Hash powers[MAX_N];
void BuildPowers() {
  powers[0] = Hash(1);
  for (int i = 1; i < MAX_N; ++i) {
    powers[i] = P;
    powers[i] *= powers[i - 1];
  }
}
Hash& operator<<=(Hash& lhs, int rhs) {
  lhs *= powers[rhs];
  return lhs;
}
Hash operator<<(const Hash& lhs, int rhs) {
  Hash result(lhs);
  result <<= rhs;
  return result;
}
int n;
int c[MAX_N];
long long ans[MAX_N];
string s;
vector<vector<int>> g;
Hash hashes[MAX_N];
struct Query {
  int l;
  int r;
  int index;
};
vector<Query> qs;
vector<Hash> tour;
void Dfs(int v, int pr, int d) {
  hashes[v] = Hash(s[v] - 'a' + 1);
  if (d != 0) {
    hashes[v] <<= d;
    hashes[v] += hashes[pr];
  }
  tour.push_back(hashes[v]);
  int l = tour.size() - 1;
  for (int i : g[v]) {
    if (i == pr) {
      continue;
    }
    Dfs(i, v, d + 1);
  }
  tour.push_back(hashes[v]);
  int r = tour.size() - 1;
  qs.push_back(Query{l, r, v});
}
struct FenwickTree {
  void Init(int n) { t.assign(n, 0); }
  void Update(int pos, int val) {
    for (; pos < (int)t.size(); pos |= (pos + 1)) {
      t[pos] += val;
    }
  }
  int Get(int pos) {
    int result = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
      result += t[pos];
    }
    return result;
  }
  int Get(int l, int r) {
    if (l == 0) {
      return Get(r);
    } else {
      return Get(r) - Get(l - 1);
    }
  }
  vector<int> t;
};
void ProcessQueries() {
  int n = tour.size();
  map<Hash, int> compressor;
  vector<int> compressed(n);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    const Hash& val = tour[i];
    if (compressor.find(val) == compressor.end()) {
      compressor[val] = m++;
    }
    compressed[i] = compressor[val];
  }
  vector<int> last(m, n);
  vector<int> nxt(n);
  for (int i = n - 1; i >= 0; --i) {
    nxt[i] = last[compressed[i]];
    last[compressed[i]] = i;
  }
  FenwickTree ft;
  ft.Init(n + 1);
  for (int i = 0; i < m; ++i) {
    ft.Update(last[i], +1);
  }
  sort(qs.begin(), qs.end(),
       [](const Query& lhs, const Query& rhs) { return lhs.l < rhs.l; });
  for (int i = 0, qi = 0; i < n; ++i) {
    while (qi < (int)qs.size() && qs[qi].l == i) {
      ans[qs[qi].index] = ft.Get(0, qs[qi].r);
      ++qi;
    }
    ft.Update(i, -1);
    ft.Update(nxt[i], +1);
  }
}
void ShowAns() {
  for (int i = 0; i < n; ++i) {
    ans[i] += c[i];
  }
  long long ansValue = ans[0];
  int ansCount = 1;
  for (int i = 1; i < n; ++i) {
    if (ans[i] == ansValue) {
      ++ansCount;
    } else if (ans[i] > ansValue) {
      ansValue = ans[i];
      ansCount = 1;
    }
  }
  cout << ansValue << endl;
  cout << ansCount << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  BuildPowers();
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  cin >> s;
  g.resize(n);
  for (int i = 0; i + 1 < n; ++i) {
    int v1, v2;
    cin >> v1 >> v2;
    --v1;
    --v2;
    g[v1].push_back(v2);
    g[v2].push_back(v1);
  }
  Dfs(0, -1, 0);
  ProcessQueries();
  ShowAns();
  return 0;
}
