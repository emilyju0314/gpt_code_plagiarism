#include <bits/stdc++.h>
using namespace std;
bool mem[100100][26];
bool vis[100100][26];
bool dp(int k, int i) {
  if (k < 0) return 0;
  if (i == 26) {
    return (k == 0);
  }
  if (vis[k][i]) return mem[k][i];
  vis[k][i] = 1;
  for (int s = 1; s * (s - 1) / 2 <= k; s++)
    if (dp(k - s * (s - 1) / 2, i + 1)) return mem[k][i] = 1;
  return mem[k][i] = 0;
}
void go(int k, int i) {
  if (i == 26) return;
  for (int s = 1; s * (s - 1) / 2 <= k; s++)
    if (dp(k - s * (s - 1) / 2, i + 1)) {
      for (int j = 0; j < s; j++) printf("%c", (char)(i + 'a'));
      go(k - s * (s - 1) / 2, i + 1);
      return;
    }
}
int main() {
  int k;
  scanf("%d", &k);
  dp(k, 0);
  go(k, 0);
  printf("\n");
  return 0;
}
