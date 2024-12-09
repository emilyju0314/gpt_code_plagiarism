#include <bits/stdc++.h>
using namespace std;
vector<int> adj[500000];
char col[500000];
queue<int> Q;
bool inqueue[500000];
bool wrong(int v) {
  int c = 0;
  for (__typeof((adj[v]).begin()) it = (adj[v]).begin(); it != (adj[v]).end();
       ++it)
    if (col[*it] == col[v]) ++c;
  return c > 1;
}
void check(int v) {
  if (inqueue[v]) return;
  if (wrong(v)) {
    Q.push(v);
    inqueue[v] = true;
  }
}
int main() {
  int N;
  scanf("%d", &N);
  int M;
  scanf("%d", &M);
  for (int i = 0; i < (M); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0; i < (N); ++i) check(i);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    inqueue[v] = false;
    if (wrong(v)) {
      col[v] = 1 - col[v];
      for (__typeof((adj[v]).begin()) it = (adj[v]).begin();
           it != (adj[v]).end(); ++it)
        check(*it);
    }
  }
  for (int i = 0; i < (N); ++i) col[i] += '0';
  printf("%s\n", col);
}
