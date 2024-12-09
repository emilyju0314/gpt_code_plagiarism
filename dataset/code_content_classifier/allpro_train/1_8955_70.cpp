#include <bits/stdc++.h>
using namespace std;
int getint() {
  unsigned int c;
  int x = 0;
  while (((c = getchar()) - '0') >= 10) {
    if (c == '-') return -getint();
    if (!~c) exit(0);
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while (((c = getchar()) - '0') < 10);
  return x;
}
int getstr(char str[]) {
  int c, n = 0;
  while ((c = getchar()) <= ' ') {
    if (!~c) exit(0);
  }
  do {
    str[n++] = c;
  } while ((c = getchar()) > ' ');
  str[n] = 0;
  return n;
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
struct GraphView {
  int direct, LR, n;
  string code;
  vector<pair<int, int> > edge;
  vector<string> node_str;
  vector<string> edge_str;
  GraphView() {}
  GraphView(int graph_node, int digraph = 1, int graph_direction = 1) {
    n = graph_node, direct = digraph, LR = graph_direction, node_str.resize(n);
    for (int i = 0; i < n; i++) {
      stringstream ss;
      ss << i;
      node_str[i] = ss.str();
    }
  }
  void init(int graph_node, int digraph = 1, int graph_direction = 1) {
    n = graph_node, direct = digraph, LR = graph_direction, node_str.resize(n);
    for (int i = 0; i < n; i++) {
      stringstream ss;
      ss << i;
      node_str[i] = ss.str();
    }
    edge.clear(), edge_str.clear();
  }
  void node_name(int i, string name) { node_str[i] = name; }
  void add_edge(int fr, int to, string label) {
    edge.push_back(make_pair(fr, to));
    edge_str.push_back(label);
  }
  string int_to_str(int d) {
    string res = "";
    do {
      res += (char)(d % 26 + 'A');
      d = d / 26;
    } while (d);
    return res;
  }
  string edge_style() {
    if (direct) return "->";
    return "--";
  }
  void make_dot() {
    code = "";
    if (direct)
      code = "digraph ";
    else
      code = "graph ";
    code += "{\n";
    if (LR) code += "    rankdir = LR\n";
    for (int i = 0; i < n; i++) {
      code += "    " + int_to_str(i) + " [label = \"" + node_str[i] + "\"];\n";
    }
    for (int i = 0; i < edge.size(); i++) {
      int u = edge[i].first, v = edge[i].second;
      code += "    " + int_to_str(u) + " " + edge_style() + " " +
              int_to_str(v) + " [label = \"" + edge_str[i] + "\"];\n";
    }
    code += "}\n";
  }
  void view(string file_name) {
    FILE *fp;
    string dotfile = file_name + ".dot";
    string giffile = file_name + ".gif";
    if ((fp = fopen(dotfile.c_str(), "w")) == NULL) return;
    fprintf(fp, "%s", code.c_str());
    fclose(fp);
    string command = "dot -Tgif " + dotfile + " -o " + giffile;
    system(command.c_str());
  }
};
template <typename Ft>
struct MF {
  static const int V = 202 * 51 + 2;
  static const Ft feps = (Ft)1e-10, finf = (Ft)(1 << 28);
  Ft tof;
  int nv, dst[V], srt[V], que[V], qs, qe, src, snk;
  struct edge {
    int to, rv;
    Ft cap;
    edge(int to, int rv, Ft cap) : to(to), rv(rv), cap(cap) {}
    string str() {
      stringstream ss;
      ss << rv << ' ' << cap;
      return ss.str();
    }
  };
  vector<edge> graph[V];
  void init(int v = V) {
    nv = v, tof = 0;
    for (v = 0; v < nv; v++) graph[v].clear();
  }
  void view() {
    GraphView gv;
    gv.init(nv);
    for (int i = 0; i < nv; i++) {
      for (int j = 0; j < graph[i].size(); j++) {
        gv.add_edge(i, graph[i][j].to, graph[i][j].str());
      }
    }
    gv.make_dot();
    gv.view("flow");
  }
  void add_edge(int fr, int to, Ft fcap, Ft rcap = 0) {
    if (fr == to) return;
    int fe = graph[fr].size(), te = graph[to].size();
    graph[fr].push_back(edge(to, te, fcap));
    graph[to].push_back(edge(fr, fe, rcap));
  }
  Ft aug(int u, Ft flo) {
    if (u == snk) return flo;
    Ft df;
    for (int &i = srt[u]; i < graph[u].size(); i++) {
      edge &e = graph[u][i];
      if (e.cap > feps and dst[u] < dst[e.to]) {
        if (flo > e.cap) flo = e.cap;
        if ((df = aug(e.to, flo)) > feps) {
          e.cap -= df, graph[e.to][e.rv].cap += df;
          return df;
        }
      }
    }
    return 0;
  }
  Ft dinic(int source, int sink, Ft flo_lim = finf) {
    int i, v;
    src = source, snk = sink;
    Ft df;
    for (; tof + feps < flo_lim;) {
      memset(dst, ~0, sizeof(dst));
      for (dst[src] = 0, qs = qe = 0, que[qe++] = src; qs != qe;) {
        v = que[qs++];
        for (i = 0; i < graph[v].size(); i++) {
          const edge &e = graph[v][i];
          if (e.cap > feps and !~dst[e.to]) {
            dst[e.to] = dst[v] + 1, que[qe++] = e.to;
            if (v == snk) {
              qs = qe = 0;
              break;
            }
          }
        }
      }
      if (!~dst[snk]) return tof;
      memset(srt, 0, sizeof(srt));
      for (; (df = aug(src, flo_lim - tof)) > feps;) tof += df;
    }
    return tof;
  }
  void cap_inc(int fr, int to, Ft inc) {
    int i;
    for (i = 0; i < graph[fr].size(); i++)
      if (graph[fr][i].to == to) {
        graph[fr][i].cap += inc;
        return;
      }
    add_edge(fr, to, inc);
  }
  Ft cap_dec(int fr, int to, Ft dec) {
    int i;
    Ft df, flo, res;
    for (i = 0; i < graph[fr].size(); i++) {
      if (graph[fr][i].to == to and graph[fr][i].cap > feps) {
        df = min(graph[fr][i].cap, dec);
        dec -= df, graph[fr][i].cap -= df;
        if (dec <= feps) return 0;
      }
    }
    flo = dinic(fr, to, dec);
    res = 0;
    if (dec - flo > feps)
      res = dec - flo, dinic(fr, src, res), dinic(snk, to, res);
    for (i = 0; i < graph[to].size(); i++) {
      if (graph[to][i].to == fr and graph[to][i].cap > feps) {
        df = min(graph[to][i].cap, dec);
        dec -= df, graph[to][i].cap -= df;
        if (dec <= feps) break;
      }
    }
    return res;
  }
};
int n, m;
int coef[55 * 3];
int lb[55], ub[55];
int us[111], vs[111], ds[111];
int nodesrt[55];
MF<int> mf;
int quad(int x, int i) {
  return coef[i * 3] * x * x + coef[i * 3 + 1] * x + coef[i * 3 + 2];
}
inline int node(int j, int i) { return nodesrt[i] + j; }
int main() {
  int i, j, tcc, tc = 1 << 28, level;
  for (tcc = 0; tcc < tc; tcc++) {
    n = getint(), m = getint();
    for (i = 0; i < n; i++) {
      coef[i * 3] = getint();
      coef[i * 3 + 1] = getint();
      coef[i * 3 + 2] = getint();
    }
    for (i = 0; i < n; i++) {
      lb[i] = getint();
      ub[i] = getint();
    }
    for (i = 0; i < m; i++) {
      us[i] = getint() - 1, vs[i] = getint() - 1, ds[i] = getint();
    }
    int s = 0, t = 1, v = 2, maxVal = 0;
    for (i = 0; i < n; i++) {
      nodesrt[i] = v;
      for (level = lb[i]; level <= ub[i]; level++) {
        chmax(maxVal, quad(level, i) + 1);
        v++;
      }
      v++;
    }
    mf.init(v);
    const int inf = 1 << 28;
    for (i = 0; i < n; i++) {
      mf.add_edge(s, node(0, i), inf);
      for (level = lb[i], j = 0; level <= ub[i]; level++, j++) {
        mf.add_edge(node(j, i), node(j + 1, i), maxVal - quad(level, i));
      }
      mf.add_edge(node(j, i), t, inf);
    }
    for (i = 0; i < m; i++) {
      int u = us[i], v = vs[i], d = ds[i];
      for (level = lb[u]; level <= ub[u]; level++) {
        int v_val = level - d;
        if (lb[v] <= v_val and v_val <= ub[v] + 1) {
          int uid = level - lb[u];
          int vid = v_val - lb[v];
          mf.add_edge(node(uid, u), node(vid, v), inf);
        }
      }
    }
    cout << maxVal * n - mf.dinic(s, t) << endl;
  }
  return 0;
}
