#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-10;
const long double PI = acos(-1.0);
const int INF = (int)1e9 + 5;
const long long LINF = (long long)1e18 + 5;
template <class T>
long long abs(const T& x) {
  return x < 0 ? -x : x;
}
template <class T>
long long round(const T& x) {
  return x < 0 ? x - 0.5 : x + 0.5;
}
template <class T>
bool chmin(T& x, const T& y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); ++it) {
    os << *it;
    if ((it + 1) != v.end()) os << ", ";
  }
  os << "}";
  return os;
}
template <class P, class Q>
ostream& operator<<(ostream& os, const pair<P, Q>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
bool chmax(T& x, const T& y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}
const long long P = (long long)1e9 + 7;
const int N = 100100;
int n, m, z = 1;
int cnt[N];
vector<int> g[N];
bool used[N];
vector<int> cycle;
vector<vector<long long>> f;
long long dp[N][2][2];
long long gg[N][2];
void dfs(int v, int p) {
  if (used[v]) return;
  used[v] = true;
  cycle.push_back(v);
  for (int to : g[v]) {
    if (to == p) continue;
    dfs(to, v);
  }
}
void process(bool isCycle) {
  vector<long long> ret = {0, 0};
  if (cycle.size() == 1) {
    if (isCycle) {
      ret[cnt[cycle[0]] ^ 1] = 1;
      ret[0]++;
    } else {
      ret[cnt[cycle[0]]] = 1;
      ret[0]++;
    }
    f.push_back(ret);
    return;
  }
  for (int val = 0; val < 2; val++) {
    for (int p = 0; p < (int)cycle.size(); p++) {
      for (int q = 0; q < 2; q++) {
        for (int z = 0; z < 2; z++) {
          dp[p][q][z] = 0;
        }
      }
    }
    dp[0][val][val * cnt[cycle[0]]] = 1;
    for (int i = 0; i < (int)cycle.size() - 1; i++) {
      for (int cur = 0; cur < 2; cur++) {
        for (int s = 0; s < 2; s++) {
          int idx = cycle[i + 1];
          for (int nw = 0; nw < 2; nw++) {
            (dp[i + 1][nw][s ^ (cur * nw) ^ (nw * cnt[idx])] +=
             dp[i][cur][s]) %= P;
          }
        }
      }
    }
    if (isCycle) {
      for (int cur = 0; cur < 2; cur++) {
        for (int s = 0; s < 2; s++) {
          int nwSum = s ^ (cur * val);
          (ret[nwSum] += dp[(int)cycle.size() - 1][cur][s]) %= P;
        }
      }
    } else {
      for (int cur = 0; cur < 2; cur++) {
        for (int s = 0; s < 2; s++) {
          int nwSum = s;
          (ret[nwSum] += dp[(int)cycle.size() - 1][cur][s]) %= P;
        }
      }
    }
  }
  f.push_back(ret);
}
void add(int x, int y) {
  g[x].push_back(y);
  g[y].push_back(x);
}
int main() {
  srand(time(0));
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++) {
    int k, x, y;
    scanf("%d", &k);
    if (k == 1) {
      scanf("%d", &x);
      cnt[abs(x)] ^= 1;
      if (x < 0) z ^= 1;
    } else {
      scanf("%d%d", &x, &y);
      if (x > 0 && y < 0) {
        swap(x, y);
      }
      if (x > 0 && y > 0) {
        cnt[x] ^= 1;
        cnt[y] ^= 1;
        add(x, y);
      } else if (x < 0 && y > 0) {
        cnt[-x] ^= 1;
        z ^= 1;
        add(-x, y);
      } else {
        add(-x, -y);
        z ^= 1;
      }
    }
  }
  vector<int> ff;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() <= 1) {
      ff.push_back(i);
    }
  }
  for (int i : ff) {
    if (!used[i]) {
      cycle.clear();
      dfs(i, -1);
      process(false);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      cycle.clear();
      dfs(i, -1);
      process(true);
    }
  }
  gg[0][0] = 1;
  for (int pref = 0; pref < (int)f.size(); pref++) {
    for (int s = 0; s < 2; s++) {
      for (int x = 0; x < 2; x++) {
        (gg[pref + 1][s ^ x] += f[pref][x] * gg[pref][s]) %= P;
      }
    }
  }
  cout << gg[f.size()][z] << endl;
}
