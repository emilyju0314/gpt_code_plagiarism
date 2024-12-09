#include <bits/stdc++.h>
using namespace std;
long long last[2000005];
long long pred[2000005];
bool vis[2000005];
long long ed[2000005], st[2000005];
long long n, m, k;
long long k1 = 0, kc = 0, kn = 0;
long long Q[2000005];
void bfs(long long x) {
  vis[x] = true;
  long long rear = 1, front = 1;
  Q[1] = x;
  while (front <= rear) {
    long long fr = Q[front];
    front++;
    fr = last[fr];
    while (fr > 0) {
      long long to = ed[fr];
      if (!vis[to]) {
        rear++;
        vis[to] = true;
        Q[rear] = to;
      }
      fr = pred[fr];
    }
  }
  kc++;
  if (rear > k) rear = k;
  if (rear == 1)
    k1++;
  else
    kn += rear - 2;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld", &st[i], &ed[i]);
    st[i + m] = ed[i];
    ed[i + m] = st[i];
  }
  for (long long i = 1; i <= 2 * m; i++) {
    pred[i] = last[st[i]];
    last[st[i]] = i;
  }
  for (long long i = 1; i <= n; i++)
    if (!vis[i]) bfs(i);
  kn += 2;
  if (kc == 1)
    printf("%d\n", 0);
  else if (k == 1)
    printf("%d\n", kc - 2);
  else if (kn >= k1)
    printf("%d\n", 0);
  else
    printf("%d\n", (k1 - kn + 1) / 2);
  return 0;
}
