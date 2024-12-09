#include <bits/stdc++.h>
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
using namespace std;
struct Dinic {
  int n, source, sink;
  vector<int> starte, d;
  vector<vector<long long> > cap;
  vector<vector<int> > nei;
  inline bool bfs() {
    d = vector<int>(n + 1, -1);
    d[source] = 0;
    vector<int> q(1, source);
    for (long long i = (long long)0; i < (long long)q.size(); i++) {
      int v = q[i];
      for (auto w : nei[v])
        if (d[w] == -1 && cap[v][w]) {
          q.push_back(w);
          d[w] = d[v] + 1;
        }
    }
    return d[sink] != -1;
  }
  long long dfs(int v, long long mincap) {
    if (!mincap || v == sink) return mincap;
    long long fp = 0;
    for (long long i = (long long)starte[v]; i < (long long)nei[v].size();
         i++) {
      if (!mincap)
        break;
      else
        starte[v] = i;
      int w = nei[v][i];
      if (d[w] == d[v] + 1) {
        long long f = dfs(w, min(mincap, cap[v][w]));
        mincap -= f;
        fp += f;
        cap[v][w] -= f;
        cap[w][v] += f;
      }
    }
    return fp;
  }
  Dinic(int in, int isource, int isink)
      : n(in),
        source(isource),
        sink(isink),
        cap(n + 1, vector<long long>(n + 1, 0)),
        nei(n + 1) {}
  Dinic() = default;
  long long flow() {
    long long maxflow = 0;
    while (bfs()) {
      starte = vector<int>(n + 1, 0);
      maxflow += dfs(source, INF);
    }
    return maxflow;
  }
  void add_edge(int from, int to, long long capacity, long long cap2 = 0) {
    if (0) cout << "ADDING " << from << " " << to << " " << capacity << "\n";
    nei[from].push_back(to);
    nei[to].push_back(from);
    cap[from][to] += capacity;
    cap[to][from] += cap2;
  }
  vector<int> find_source_cc() {
    bfs();
    vector<int> ans;
    for (int i = 0; i <= n; i++)
      if (d[i] != -1) ans.push_back(i);
    return ans;
  }
};
const int N = 300;
int n;
int num_ccl[N + 1], ccl_pr[N + 1];
bool visited[N + 1];
vector<pair<int, int> > cond;
int max_pr;
vector<int> prc[N + 1], ccl[N + 1], fr;
vector<int> set_verts[N + 1][N + 1];
int sat[N + 1][N + 1];
int res[N + 1];
bool run_dinic(int l_tr) {
  int f = 2 * n + 1, s = 2 * n + 2, t = 2 * n + 3, k = 3 * n + 5;
  Dinic d(k, s, t);
  int cnt = 2 * n + 4;
  int ans = 0;
  for (long long i = (long long)0; i < (long long)n + 1; i++) {
    d.add_edge(s, i, (int)(prc[i].size()));
  }
  for (long long i = (long long)n + 1; i < (long long)2 * n + 1; i++) {
    d.add_edge(s, i, (int)(ccl[i - n].size()));
  }
  d.add_edge(s, f, (int)(fr.size()));
  if (0)
    cout << "ADDED VERTS"
         << "\n";
  for (long long i = (long long)1; i < (long long)n + 1; i++) {
    int mi = (i - (num_ccl[i] % i)) % i;
    if (num_ccl[i] == 0 and visited[i]) {
      mi = i;
    }
    if (mi) {
      if (cnt >= k) {
        return false;
      }
      ans += mi;
      d.add_edge(cnt, t, mi);
      d.add_edge(0, cnt, IINF);
      d.add_edge(n + i, cnt, IINF);
      d.add_edge(f, cnt, IINF);
      cnt++;
    }
  }
  for (long long i = (long long)1; i < (long long)n + 1; i++) {
    if (0)
      cout << "i"
           << " = " << i << "\n";
    if (0)
      cout << "ccl_pr[i]"
           << " = " << ccl_pr[i] << "\n";
    for (int j = ccl_pr[i]; j > 0; j--) {
      if (!(int)(set_verts[i][j].size())) {
        if (cnt >= k) {
          return false;
        }
        if (0)
          cout << "i"
               << " = " << i << "\n";
        if (0)
          cout << "j"
               << " = " << j << "\n";
        ans++;
        d.add_edge(cnt, t, 1);
        d.add_edge(j, cnt, IINF);
        d.add_edge(n + i, cnt, IINF);
        d.add_edge(f, cnt, IINF);
        cnt++;
      }
    }
  }
  if (0)
    cout << "ADDED CONDS"
         << "\n";
  if (d.flow() == ans) {
    cnt = 2 * n + 4;
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      int mi = (i - (num_ccl[i] % i)) % i;
      if (num_ccl[i] == 0 and visited[i]) {
        mi = i;
      }
      if (mi) {
        if (0)
          cout << "i"
               << " = " << i << "\n";
        if (0)
          cout << "mi"
               << " = " << mi << "\n";
        for (long long j = (long long)0; j < (long long)d.cap[cnt][0]; j++) {
          set_verts[i][0].push_back(prc[0].back());
          prc[0].pop_back();
        }
        for (long long j = (long long)0; j < (long long)d.cap[cnt][n + i];
             j++) {
          set_verts[i][0].push_back(ccl[i].back());
          ccl[i].pop_back();
        }
        for (long long j = (long long)0; j < (long long)d.cap[cnt][f]; j++) {
          set_verts[i][0].push_back(fr.back());
          fr.pop_back();
        }
        cnt++;
      }
    }
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      for (int j = ccl_pr[i]; j > 0; j--) {
        if (!(int)(set_verts[i][j].size())) {
          if (0)
            cout << "i"
                 << " = " << i << "\n";
          if (0)
            cout << "j"
                 << " = " << j << "\n";
          for (long long l = (long long)0; l < (long long)d.cap[cnt][j]; l++) {
            set_verts[i][j].push_back(prc[j].back());
            prc[j].pop_back();
          }
          for (long long l = (long long)0; l < (long long)d.cap[cnt][n + i];
               l++) {
            set_verts[i][j].push_back(ccl[i].back());
            ccl[i].pop_back();
          }
          for (long long l = (long long)0; l < (long long)d.cap[cnt][f]; l++) {
            set_verts[i][j].push_back(fr.back());
            fr.pop_back();
          }
          cnt++;
        }
      }
    }
    for (auto& v : fr) {
      set_verts[1][0].push_back(v);
    }
    for (auto& v : prc[0]) {
      set_verts[1][0].push_back(v);
    }
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      for (auto& v : prc[i]) {
        set_verts[l_tr][i].push_back(v);
      }
    }
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      for (auto& v : ccl[i]) {
        set_verts[i][1].push_back(v);
      }
    }
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      for (long long j = (long long)0; j < (long long)n + 1; j++) {
        if (0) cout << i << " " << j << "  ";
        for (auto& v : set_verts[i][j]) {
          if (0) cout << v << " ";
        }
        if (0) cout << "\n";
      }
    }
    for (long long i = (long long)1; i < (long long)n + 1; i++) {
      for (long long l = (long long)0;
           l < (long long)(int)(set_verts[i][0].size()); l++) {
        if ((l + 1) % i) {
          res[set_verts[i][0][l]] = set_verts[i][0][(l + 1)];
        } else {
          res[set_verts[i][0][l]] = set_verts[i][0][l + 1 - i];
        }
      }
      for (long long j = (long long)1; j < (long long)n + 1; j++) {
        for (auto& v : set_verts[i][j]) {
          res[v] = set_verts[i][j - 1][0];
        }
      }
    }
    return true;
  } else {
    return false;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = (long long)0; i < (long long)n; i++) {
    string c1, c2;
    cin >> c1 >> c2;
    if (c1 == "?" and c2 == "?") {
      fr.push_back(i);
    } else if (c1 == "?" and c2 != "?") {
      if (0)
        cout << "stoi(c2)"
             << " = " << stoi(c2) << "\n";
      ccl[stoi(c2)].push_back(i);
      visited[stoi(c2)] = true;
    } else if (c1 != "?" and c2 == "?") {
      max_pr = max(max_pr, stoi(c1));
      prc[stoi(c1)].push_back(i);
    } else {
      ccl_pr[stoi(c2)] = max(ccl_pr[stoi(c2)], stoi(c1));
      max_pr = max(max_pr, stoi(c1));
      cond.push_back({stoi(c1), stoi(c2)});
      visited[stoi(c2)] = true;
      sat[stoi(c2)][stoi(c1)] = i;
      set_verts[stoi(c2)][stoi(c1)].push_back(i);
      if (c1 == "0") {
        num_ccl[stoi(c2)]++;
      }
    }
  }
  bool tr = true;
  for (long long i = (long long)1; i < (long long)n + 1; i++) {
    if (0)
      cout << "JESTE"
           << "\n";
    swap(max_pr, ccl_pr[i]);
    swap(tr, visited[i]);
    if (run_dinic(i)) {
      for (long long j = (long long)0; j < (long long)n; j++) {
        cout << res[j] + 1 << " \n"[j == n - 1];
      }
      return 0;
    }
    swap(tr, visited[i]);
    swap(max_pr, ccl_pr[i]);
  }
  cout << "-1\n";
  return 0;
}
