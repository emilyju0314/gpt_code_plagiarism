#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> G[100005], V[65], V2[65];
int A[100005], Level[100005];
int Prime[100005], pr, cnt;
int Left[100005], Right[100005], Father[20][100005], Log[100005];
pair<int, int> A2[100005];
int Arb[800005], Aux[100005], Arb2[200005];
const int MOD = 1000000007;
int Res[100005];
bool X[5005];
struct query {
  int u, v, x, pos, lca;
} Q[100005];
int q;
int power(int n, int p) {
  int sol = 1;
  while (p) {
    if ((p & 1)) {
      sol = (1LL * sol * n) % MOD;
    }
    p /= 2;
    n = (1LL * n * n) % MOD;
  }
  return sol;
}
int inv(int x) { return power(x, MOD - 2); }
void Eratostenes() {
  for (int i = 2; i * i <= 10000000; i++) {
    if (X[i] == 0) {
      Prime[++pr] = i;
      for (int j = i + i; j * j <= 10000000; j += i) X[j] = 1;
    }
  }
}
void Read() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &Q[i].u, &Q[i].v, &Q[i].x);
    Q[i].pos = i;
  }
}
void DFS(int node, int father) {
  Father[0][node] = father;
  Level[node] = Level[father] + 1;
  Left[node] = ++cnt;
  for (int i = 0; i < G[node].size(); i++) {
    int neighb = G[node][i];
    if (neighb == father) continue;
    DFS(neighb, node);
  }
  Right[node] = ++cnt;
}
void precalcLog() {
  for (int i = 2; i <= N; i++) Log[i] = Log[i / 2] + 1;
}
void precalcFather() {
  for (int i = 1; i <= Log[N]; i++)
    for (int j = 1; j <= N; j++) Father[i][j] = Father[i - 1][Father[i - 1][j]];
}
int Anc(int node, int dist) {
  while (dist > 0) {
    int k = Log[dist];
    node = Father[k][node];
    dist -= (1 << k);
  }
  return node;
}
int LCA(int x, int y) {
  if (Level[x] > Level[y]) swap(x, y);
  y = Anc(y, Level[y] - Level[x]);
  if (x == y) return x;
  for (int k = Log[N]; k >= 0; k--)
    if (Father[k][x] != Father[k][y]) {
      x = Father[k][x];
      y = Father[k][y];
    }
  return Father[0][x];
}
void Update(int K, int L, int R, int pos, int val) {
  if (L > R || R < pos || L > pos) return;
  if (L == R) {
    Arb[K] = (1LL * Arb[K] * val) % MOD;
    return;
  }
  if (pos > (L + R) / 2) {
    Update(K * 2 + 1, (L + R) / 2 + 1, R, pos, val);
  } else
    Update(K * 2, L, (L + R) / 2, pos, val);
  Arb[K] = (1LL * Arb[K * 2] * Arb[K * 2 + 1]) % MOD;
}
int Query(int K, int L, int R, int x, int y) {
  if (L > R || R < x || L > y) return 1;
  if (L >= x && R <= y) return Arb[K];
  int a = Query(K * 2, L, (L + R) / 2, x, y);
  int b = Query(K * 2 + 1, (L + R) / 2 + 1, R, x, y);
  return (1LL * a * b) % MOD;
}
void Upd(int pos, int val) {
  while (pos <= N * 2) {
    Arb2[pos] += val;
    pos += (pos & (-pos));
  }
}
int Sum(int pos) {
  int ret = 0;
  while (pos >= 1) {
    ret += Arb2[pos];
    pos -= (pos & (-pos));
  }
  return ret;
}
void smallPrime(int prime) {
  for (int i = 0; i <= 60; i++) {
    V[i].clear();
    V2[i].clear();
  }
  for (int i = 1; i <= q; i++) {
    int exp = 0;
    while (Q[i].x % prime == 0) {
      ++exp;
      Q[i].x /= prime;
    }
    V[exp].push_back(i);
  }
  for (int i = 1; i <= 8 * N; i++) Arb[i] = 1;
  for (int i = 1; i <= 2 * N; i++) Arb2[i] = 0;
  int total = N;
  for (int i = 1; i <= N; i++) {
    int exp = 0;
    while (A[i] % prime == 0) {
      ++exp;
      A[i] /= prime;
    }
    Aux[i] = exp;
    V2[exp].push_back(i);
  }
  for (int i = 1; i <= N; i++) {
    if (Aux[i] == 0) continue;
    Upd(Left[i], 1);
    Upd(Right[i], -1);
  }
  for (int i = 1; i < 30; i++) {
    int init = power(prime, i);
    for (int j = 0; j < V[i].size(); j++) {
      int p = V[i][j];
      int u = Q[p].u, v = Q[p].v;
      int lca = Q[p].lca;
      total = Sum(Left[v]) - Sum(Left[lca] - 1) + Sum(Left[u]) -
              Sum(Left[lca] - 1) - (Sum(Left[lca]) - Sum(Left[lca] - 1));
      int aux = Query(1, 1, N * 2, Left[lca], Left[u]);
      aux = (1LL * aux * Query(1, 1, N * 2, Left[lca], Left[v])) % MOD;
      aux = (1LL * aux * inv(Query(1, 1, N * 2, Left[lca], Left[lca]))) % MOD;
      int pw = init;
      pw = power(pw, total);
      Res[p] = (1LL * Res[p] * pw) % MOD;
      Res[p] = (1LL * Res[p] * aux) % MOD;
    }
    int rev = inv(init);
    for (int j = 0; j < V2[i].size(); j++) {
      int node = V2[i][j];
      Update(1, 1, N * 2, Left[node], init);
      Update(1, 1, N * 2, Right[node], rev);
      Upd(Left[node], -1);
      Upd(Right[node], 1);
    }
  }
}
inline bool comp(query a, query b) { return a.x < b.x; }
void bigPrimes() {
  for (int i = 1; i <= N; i++) A2[i] = make_pair(A[i], i);
  for (int i = 1; i <= 2 * N; i++) Arb2[i] = 0;
  sort(A2 + 1, A2 + N + 1);
  sort(Q + 1, Q + q + 1, comp);
  int point = 1;
  for (int i = 1; i <= q; i++) {
    if (Q[i].x != Q[i - 1].x) {
      int point2 = point - 1;
      while (point2 > 0 && A2[point2].first == Q[i - 1].x) {
        Upd(Left[A2[point2].second], -1);
        Upd(Right[A2[point2].second], 1);
        --point2;
      }
      while (point <= N && A2[point].first < Q[i].x) ++point;
      while (point <= N && A2[point].first == Q[i].x) {
        int node = A2[point].second;
        Upd(Left[node], 1);
        Upd(Right[node], -1);
        ++point;
      }
    }
    int u = Q[i].u, v = Q[i].v;
    int lca = Q[i].lca;
    int total = Sum(Left[v]) - Sum(Left[lca]) + Sum(Left[u]) - Sum(Left[lca]) +
                Sum(Left[lca]) - Sum(Left[lca] - 1);
    Res[Q[i].pos] = (1LL * Res[Q[i].pos] * power(Q[i].x, total)) % MOD;
  }
}
int main() {
  Read();
  for (int i = 1; i <= q; i++) Res[i] = 1;
  precalcLog();
  DFS(1, 0);
  precalcFather();
  for (int i = 1; i <= q; i++) {
    Q[i].lca = LCA(Q[i].u, Q[i].v);
  }
  Eratostenes();
  for (int i = 1; i <= pr; i++) smallPrime(Prime[i]);
  bigPrimes();
  for (int i = 1; i <= q; i++) printf("%d\n", Res[i]);
  return 0;
}
