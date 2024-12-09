#include <bits/stdc++.h>
using namespace std;
const int kMaxN = 20000 + 5;
const int kMaxM = 10 * kMaxN;
const int NIL = -1;
struct Network {
  struct Edge {
    int v, cap;
    int next;
  } G[2 * kMaxM];
  int head[kMaxN];
  int N;
  int edgePtr;
  void SetSize(const int numNodes) {
    memset(head, NIL, 4 * numNodes);
    N = numNodes;
    edgePtr = 0;
  }
  void AddEdge(const int u, const int v, const int cap) {
    G[edgePtr].v = v;
    G[edgePtr].cap = cap;
    G[edgePtr].next = head[u];
    head[u] = edgePtr++;
  }
  int dist[kMaxN];
  int Q[kMaxN];
  bool BFS() {
    int qHead = 0, qTail = 1;
    memset(dist, 0, 4 * N);
    Q[0] = 0;
    dist[0] = 1;
    while ((qHead != qTail) && (!dist[N - 1])) {
      const int node = Q[qHead++];
      for (int i = head[node]; i != NIL; i = G[i].next) {
        const int son = G[i].v;
        if (G[i].cap > 0 && !dist[son]) {
          dist[son] = dist[node] + 1;
          Q[qTail++] = son;
        }
      }
    }
    return dist[N - 1];
  }
  int to[kMaxN];
  int DFS(const int node, const int flow) {
    if (node == N - 1) {
      return flow;
    }
    for (; to[node] != NIL; to[node] = G[to[node]].next) {
      if ((G[to[node]].cap > 0) && (dist[G[to[node]].v] == dist[node] + 1)) {
        const int pushFlow = (flow < G[to[node]].cap ? flow : G[to[node]].cap);
        const int pushed = DFS(G[to[node]].v, pushFlow);
        if (pushed) {
          G[to[node]].cap -= pushed;
          G[to[node] ^ 1].cap += pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
  int MaxFlow() {
    int flow = 0;
    while (BFS()) {
      memmove(to, head, 4 * N);
      int pushed;
      do {
        pushed = DFS(0, 0x3f3f3f3f);
        flow += pushed;
      } while (pushed);
    }
    return flow;
  }
};
int n, m;
pair<int, int> edges[kMaxM];
int edge_type[kMaxM];
int GetFlow(int edge_cap) {
  static Network Dinic;
  Dinic.SetSize(n + m + 2);
  for (int i = 0; i < n; ++i) {
    Dinic.AddEdge(0, 1 + i, edge_cap);
    Dinic.AddEdge(1 + i, 0, 0);
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    x = edges[i].first;
    y = edges[i].second;
    Dinic.AddEdge(x, n + 1 + i, 1);
    Dinic.AddEdge(n + 1 + i, x, 0);
    Dinic.AddEdge(y, n + 1 + i, 1);
    Dinic.AddEdge(n + 1 + i, y, 0);
    Dinic.AddEdge(n + 1 + i, n + m + 1, 1);
    Dinic.AddEdge(n + 1 + m, n + i + 1, 0);
  }
  int answer = Dinic.MaxFlow();
  for (int i = 0; i < m; ++i) {
    edge_type[i] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = Dinic.head[i]; j != NIL; j = Dinic.G[j].next) {
      if (Dinic.G[j].cap == 0 && Dinic.G[j].v != 0) {
        edge_type[Dinic.G[j].v - n - 1] = i;
      }
    }
  }
  return answer;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    edges[i] = make_pair(x, y);
  }
  int left = -1, right = m + 1;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (GetFlow(middle) == m) {
      right = middle;
    } else {
      left = middle;
    }
  }
  cout << right << endl;
  GetFlow(right);
  for (int i = 0; i < m; ++i) {
    int x = edges[i].first, y = edges[i].second;
    if (edge_type[i] == y) {
      swap(x, y);
    }
    cout << x << ' ' << y << '\n';
  }
}
