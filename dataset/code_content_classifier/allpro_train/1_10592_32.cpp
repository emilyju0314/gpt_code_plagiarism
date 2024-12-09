#include <bits/stdc++.h>
using namespace std;
inline void scanint(int &x) {
  register int c = getchar();
  x = 0;
  for (; (c < 48 || c > 57); c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
}
int N, ROOT, CHAINS = 0;
vector<pair<int, int>> adj[100005];
int DEPTH[100005];
int EDGE_NODE[100005];
int CHAIN_V[100005];
int CHILD[100005];
int ROOT_CHILD[100005];
int BASE[100005];
int BASE_CNT = 0;
int TREE[100005 * 8];
int NODES[100005];
inline void setRoot() {
  int maxDegree = 0;
  for (int i = 1; i <= N; i++) {
    if (adj[i].size() > maxDegree) {
      maxDegree = adj[i].size();
      ROOT = i;
    }
  }
}
void dfs(int V, int D, int P, int E, int chain) {
  DEPTH[V] = D;
  BASE[V] = BASE_CNT++;
  EDGE_NODE[E] = V;
  CHAIN_V[V] = chain;
  int child, edge;
  for (int i = 0; i < adj[V].size(); i++) {
    child = adj[V][i].first;
    edge = adj[V][i].second;
    if (child == P) continue;
    CHILD[V] = child;
    dfs(child, D + 1, V, edge, chain);
  }
}
inline int LCA(int v, int w) {
  if (CHAIN_V[v] != CHAIN_V[w] || v == ROOT || w == ROOT)
    return ROOT;
  else {
    if (DEPTH[v] < DEPTH[w])
      return v;
    else
      return w;
  }
}
void construct(int start, int end, int node) {
  if (start == end) {
    NODES[start] = node;
    return;
  }
  construct(start, (start + end) / 2, node * 2 + 1);
  construct((start + end) / 2 + 1, end, node * 2 + 2);
}
inline void update(int x, int start, int end, int noxde, int to) {
  int node = NODES[x];
  TREE[node] = to;
  while (node > 0) {
    node = (node - 1) / 2;
    TREE[node] = TREE[node * 2 + 1] + TREE[node * 2 + 2];
  }
}
inline int query1(int a, int b) {
  int sum = 0;
  queue<pair<int, pair<int, int>>> q;
  q.push(make_pair(0, make_pair(0, BASE_CNT - 1)));
  int start, end, node;
  while (!q.empty()) {
    node = q.front().first;
    start = q.front().second.first;
    end = q.front().second.second;
    q.pop();
    if (start >= a && end <= b) {
      sum += TREE[node];
    } else {
      int mid = (start + end) / 2;
      if (b <= mid) {
        q.push(make_pair(node * 2 + 1, make_pair(start, mid)));
      } else if (a > mid) {
        q.push(make_pair(node * 2 + 2, make_pair(mid + 1, end)));
      } else {
        q.push(make_pair(node * 2 + 1, make_pair(start, mid)));
        q.push(make_pair(node * 2 + 2, make_pair(mid + 1, end)));
      }
    }
  }
  return sum;
}
inline int query(int start, int end, int a, int b, int node) {
  return query1(a, b);
}
int main() {
  ios_base::sync_with_stdio(0);
  scanint(N);
  int v, w;
  for (int i = 1; i < N; i++) {
    scanint(v), scanint(w);
    adj[v].push_back(make_pair(w, i));
    adj[w].push_back(make_pair(v, i));
  }
  setRoot();
  int child, edge;
  int V = ROOT;
  for (int i = 0; i < adj[V].size(); i++) {
    child = adj[V][i].first;
    edge = adj[V][i].second;
    CHILD[V] = child;
    dfs(child, 1, V, edge, CHAINS);
    ROOT_CHILD[CHAINS++] = child;
  }
  construct(0, BASE_CNT - 1, 0);
  int M, type;
  scanint(M);
  int x, y;
  int l, l1, l2, h1, h2;
  while (M--) {
    scanint(type);
    if (type == 1) {
      scanint(x);
      y = EDGE_NODE[x];
      update(BASE[y], 0, BASE_CNT - 1, 0, 0);
    } else if (type == 2) {
      scanint(x);
      y = EDGE_NODE[x];
      update(BASE[y], 0, BASE_CNT - 1, 0, 1);
    } else if (type == 3) {
      scanint(x), scanint(y);
      if (x == y) {
        cout << 0 << '\n';
        continue;
      }
      l = LCA(x, y);
      if (l == ROOT) {
        if (l == x) {
          swap(x, y);
        }
        if (l == y) {
          int l = ROOT_CHILD[CHAIN_V[x]];
          h1 = query(0, BASE_CNT - 1, BASE[l], BASE[x], 0);
          if (h1 == 0) {
            cout << DEPTH[x] << '\n';
          } else {
            cout << -1 << '\n';
          }
          continue;
        }
        l1 = ROOT_CHILD[CHAIN_V[x]];
        l2 = ROOT_CHILD[CHAIN_V[y]];
        h1 = query(0, BASE_CNT - 1, BASE[l1], BASE[x], 0);
        h2 = query(0, BASE_CNT - 1, BASE[l2], BASE[y], 0);
        if (h1 == 0 && h2 == 0) {
          cout << DEPTH[x] + DEPTH[y] << '\n';
        } else {
          cout << -1 << '\n';
        }
      } else {
        if (y == l) {
          swap(x, y);
        }
        h1 = query(0, BASE_CNT - 1, BASE[CHILD[x]], BASE[y], 0);
        if (h1 == 0) {
          cout << DEPTH[y] - DEPTH[x] << '\n';
        } else {
          cout << -1 << '\n';
        }
      }
    }
  }
  return 0;
}
