#include <bits/stdc++.h>
char Input[500020];
using namespace std;
struct Edge {
  int to, next;
} E[500020 << 1];
int In[500020], qaq;
int T, N, head[500020], A, qwq, B, i, j, ans, cnt;
inline void Add(int u, int v) {
  E[++cnt].to = v, In[v]++;
  E[cnt].next = head[u], head[u] = cnt;
  E[++cnt].to = u, In[u]++;
  E[cnt].next = head[v], head[v] = cnt;
}
int main() {
  cin >> T;
  while (T--) {
    scanf("%d", &N), ++qwq;
    fill(In, In + N + 4, 0);
    fill(head, head + N + 4, 0), ans = 0, qaq = 0;
    for (i = 1; i < N; ++i) scanf("%d%d", &A, &B), Add(A, B);
    scanf("%s", Input);
    if (N < 3)
      puts("Draw");
    else if (N == 3) {
      for (i = 0; i < N; ++i) ans += Input[i] == 'W';
      puts(ans >= 2 ? "White" : "Draw");
    } else {
      int Linshi = 0;
      for (i = 0; i < N; ++i)
        if (Input[i] == 'W') {
          head[++N] = 0, Add(i + 1, N), In[N] = 3;
        }
      for (i = 1; i <= N && ans <= 0; ++i) {
        if (In[i] > 3)
          ans++;
        else if (In[i] == 3) {
          Linshi = 0;
          for (j = head[i]; j; j = E[j].next) Linshi += (In[E[j].to] >= 2);
          ans += Linshi > 1, qaq++;
        }
      }
      if (qaq == 2 && (N % 2)) ans++;
      puts(ans ? "White" : "Draw");
    }
  }
}
