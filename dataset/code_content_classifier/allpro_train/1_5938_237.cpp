#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1E9;
int S, T, FN;
int L, adj[(3005 * 4)], dst[(3005 * 4)], pre[(3005 * 4)], pret[(3005 * 4)];
struct llist {
  int id, next, c, f, w;
  llist() {}
  llist(int _id, int _next, int _c, int _w) {
    id = _id;
    next = _next;
    c = _c;
    f = 0;
    w = _w;
  }
} lists[2 * ((3005 * 4) * 6)];
void init() {
  L = 0;
  memset(adj, -1, sizeof(adj));
}
inline void insertList(int &a, int b, int c, int w) {
  lists[L] = llist(b, a, c, w);
  a = L++;
}
inline void insertEdge(int a, int b, int c, int w) {
  insertList(adj[a], b, c, w);
  insertList(adj[b], a, 0, -w);
}
bool spfa() {
  for (int i = (0); i < (FN); i++) dst[i] = INF;
  dst[S] = 0;
  queue<int> que;
  que.push(S);
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    int t = adj[x];
    while (t != -1) {
      int y = lists[t].id, nw = dst[x] + lists[t].w;
      if (lists[t].c != lists[t].f && nw < dst[y]) {
        dst[y] = nw;
        pre[y] = x;
        pret[y] = t;
        que.push(y);
      }
      t = lists[t].next;
    }
  }
  return dst[T] != INF;
}
void reduceCost() {
  for (int x = (0); x < (FN); x++) {
    int t = adj[x];
    while (t != -1) {
      int y = lists[t].id;
      if (lists[t].f != lists[t].c) {
        lists[t].w = lists[t].w + dst[x] - dst[y];
        lists[t ^ 1].w = 0;
      }
      t = lists[t].next;
    }
  }
}
bool dijkstra() {
  for (int i = 0; i < FN; i++) dst[i] = INF;
  dst[S] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      pq;
  pq.push(pair<int, int>(0, S));
  while (!pq.empty()) {
    pair<int, int> now = pq.top();
    pq.pop();
    if (dst[now.second] < now.first) continue;
    int x = now.second, t = adj[x];
    while (t != -1) {
      int y = lists[t].id, nw = dst[x] + lists[t].w;
      if (lists[t].c != lists[t].f && nw < dst[y]) {
        dst[y] = nw;
        pre[y] = x;
        pret[y] = t;
        pq.push(pair<int, int>(dst[y], y));
      }
      t = lists[t].next;
    }
  }
  return dst[T] != INF;
}
pair<int, int> sap() {
  spfa();
  int totw = 0, totf = 0, sumDstT = dst[T];
  reduceCost();
  while (1) {
    bool augable = dijkstra();
    if (!augable) break;
    reduceCost();
    int minflow = INF, x = T;
    while (x != S) {
      int flow = lists[pret[x]].c - lists[pret[x]].f;
      minflow = min(minflow, flow);
      x = pre[x];
    }
    x = T;
    while (x != S) {
      lists[pret[x]].f += minflow;
      lists[pret[x] ^ 1].f = -lists[pret[x]].f;
      x = pre[x];
    }
    totf += minflow;
    sumDstT += dst[T];
    totw += minflow * sumDstT;
  }
  return make_pair(totf, totw);
}
int N, a[3005];
int main() {
  cin >> N;
  int S2 = 4 * N;
  S = S2 + 1;
  T = S + 1;
  FN = T + 1;
  L = 0;
  memset(adj, -1, sizeof(adj));
  for (int i = (0); i < (N); i++) {
    scanf("%d", a + i);
    insertEdge(4 * i, 4 * i + 1, 1, -1);
    insertEdge(4 * i + 1, T, 1, 0);
    insertEdge(4 * i + 2, 4 * i, 1, 0);
    insertEdge(4 * i + 3, 4 * i, 1, 0);
    insertEdge(S2, 4 * i, 1, 0);
  }
  for (int i = (0); i < (N); i++) {
    bool up1 = false, down1 = false, congruent = false, same = false;
    for (int j = (i + 1); j < (N); j++) {
      if (a[j] == a[i] + 1 && !up1) {
        up1 = true;
        insertEdge(4 * i + 1, 4 * j + 2, 1, 0);
      }
      if (a[j] == a[i] - 1 && !down1) {
        down1 = true;
        insertEdge(4 * i + 1, 4 * j + 2, 1, 0);
      }
      if (a[j] == a[i] && !same) {
        same = true;
        insertEdge(4 * i + 2, 4 * j + 2, 4, 0);
      }
      if (a[j] % 7 == a[i] % 7 && !congruent) {
        congruent = true;
        insertEdge(4 * i + 1, 4 * j + 3, 1, 0);
        insertEdge(4 * i + 3, 4 * j + 3, 4, 0);
      }
    }
  }
  insertEdge(S, S2, 4, 0);
  pair<int, int> ans = sap();
  cout << -ans.second << endl;
  return 0;
}
