#include <bits/stdc++.h>
using namespace std;
const long long MaxN = 2003;
long long n, head[MaxN * MaxN], cntEdge;
bool visited[MaxN][MaxN], inStack[MaxN], flag;
long long DFN[MaxN], LOW[MaxN], cntDFN, num;
struct Edge {
  long long destination, nextEdge;
} edge[MaxN * MaxN * 2];
stack<long long> s;
inline long long Read() {
  long long num = 0, op = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = num * 10 + ch - '0';
    ch = getchar();
  }
  return num * op;
}
inline void AddEdge(long long u, long long v) {
  cntEdge++;
  edge[cntEdge].destination = v;
  edge[cntEdge].nextEdge = head[u];
  head[u] = cntEdge;
  return;
}
inline void Tarjan(long long x) {
  DFN[x] = LOW[x] = ++cntDFN;
  inStack[x] = true, s.push(x);
  for (long long i = head[x]; i; i = edge[i].nextEdge) {
    if (!DFN[edge[i].destination]) {
      Tarjan(edge[i].destination);
      LOW[x] = min(LOW[x], LOW[edge[i].destination]);
    } else if (inStack[edge[i].destination])
      LOW[x] = min(LOW[x], DFN[edge[i].destination]);
  }
  long long tmp;
  if (LOW[x] == DFN[x]) {
    num++;
    do {
      tmp = s.top();
      s.pop();
      inStack[tmp] = false;
    } while (x != tmp);
  }
}
signed main() {
  n = Read();
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++) {
      long long tmp = Read();
      if (tmp)
        visited[i][j] = true;
      else
        flag = false;
    }
  if (flag) {
    printf("YES");
    return 0;
  }
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= n; j++)
      if (visited[i][j]) AddEdge(i, j);
  for (long long i = 1; i <= n; i++)
    if (!DFN[i]) Tarjan(i);
  if (num == 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}
