#include <bits/stdc++.h>
using namespace std;
const int Max_N = 1000005;
const int inf = 0x3F3F3F3F;
const int Max_K = 8;
bool hav[Max_K];
int N, Cases;
int F[Max_N][Max_K], G[Max_K][Max_K], H[Max_K][1 << Max_K][Max_K][1 << Max_K],
    stat[Max_N];
int cnt[Max_K][1 << Max_K];
long long Ans[Max_K * 2];
char s[Max_N];
int str[Max_N];
void bfs(int chr) {
  static queue<int> q;
  static int stk[Max_K][Max_N], top[Max_K];
  memset(top, 0, sizeof(top));
  for (int i = 1; i <= N; i++) {
    if (str[i] == chr)
      F[i][chr] = 0, q.push(i);
    else
      stk[str[i]][++top[str[i]]] = i;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    while (top[str[u]]) {
      int id = str[u];
      if (F[stk[id][top[id]]][chr] == inf) {
        F[stk[id][top[id]]][chr] = F[u][chr] + 1;
        q.push(stk[id][top[id]]);
      }
      top[id]--;
    }
    if (u < N && F[u + 1][chr] == inf)
      F[u + 1][chr] = F[u][chr] + 1, q.push(u + 1);
    if (u > 1 && F[u - 1][chr] == inf)
      F[u - 1][chr] = F[u][chr] + 1, q.push(u - 1);
  }
}
void clear() {
  memset(hav, 0, sizeof(hav));
  memset(F, 0x3F, sizeof(F));
  memset(G, 0x3F, sizeof(G));
  memset(Ans, 0, sizeof(Ans));
  memset(H, 0x3F, sizeof(H));
}
int main() {
  Cases = 1;
  while (Cases--) {
    clear();
    scanf("%d", &N);
    scanf("%s", s + 1);
    N = strlen(s + 1);
    for (int i = 1; i <= N; i++) str[i] = s[i] - 'a', hav[str[i]] = 1;
    for (int i = 0; i < Max_K; i++)
      if (hav[i]) bfs(i);
    for (int i = 1; i <= N; i++)
      for (int j = 0; j < Max_K; j++)
        if (hav[j]) G[str[i]][j] = G[j][str[i]] = min(G[str[i]][j], F[i][j]);
    for (int i = 1; i <= N; i++)
      for (int j = i + 1; j <= N && j <= i + 15; j++) {
        int ret = j - i;
        for (int k = 0; k < Max_K; k++) ret = min(ret, F[i][k] + F[j][k] + 1);
        Ans[ret]++;
      }
    for (int i = 0; i < Max_K; i++)
      for (int j = 0; j < (1 << Max_K); j++)
        for (int k = 0; k < Max_K; k++)
          for (int t = 0; t < (1 << Max_K); t++)
            for (int x = 0; x < Max_K; x++)
              H[i][j][k][t] =
                  min(H[i][j][k][t],
                      G[i][x] + ((j >> x) & 1) + G[k][x] + ((t >> x) & 1) + 1);
    for (int i = 1; i <= N; i++) {
      stat[i] = 0;
      for (int j = 0; j < Max_K; j++)
        if (hav[j]) stat[i] += (F[i][j] - G[str[i]][j]) * (1 << j);
    }
    for (int i = 17; i <= N; i++) {
      cnt[str[i - 16]][stat[i - 16]]++;
      for (int j = 0; j < Max_K; j++)
        for (int k = 0; k < (1 << Max_K); k++)
          if (cnt[j][k]) Ans[H[str[i]][stat[i]][j][k]] += cnt[j][k];
    }
    int ret = 0;
    for (int i = Max_K * 2 - 1; i >= 1; i--) ret += (Ans[i] != 0);
    for (int i = Max_K * 2 - 1; i >= 1; i--)
      if (Ans[i] != 0) {
        printf("%d %lld\n", i, Ans[i]);
        break;
      }
  }
  return 0;
}
