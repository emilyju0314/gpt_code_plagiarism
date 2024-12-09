#include <bits/stdc++.h>
int e[100001][26];
int size;
bool leaf[100001];
bool win[100001];
bool lose[100001];
char S[100001];
void init(int v) {
  for (int i = 0; i < 26; i++) e[v][i] = -1;
  leaf[v] = true;
}
void add(int v, int p, int n) {
  if (p == n) return;
  if (e[v][S[p] - 'a'] == -1) {
    e[v][S[p] - 'a'] = size;
    init(size);
    size++;
    leaf[v] = false;
  }
  add(e[v][S[p] - 'a'], p + 1, n);
}
void solve(int v) {
  if (leaf[v]) {
    win[v] = false;
    lose[v] = true;
    return;
  }
  win[v] = false;
  lose[v] = false;
  for (int i = 0; i < 26; i++) {
    if (e[v][i] == -1) continue;
    solve(e[v][i]);
    win[v] |= (!win[e[v][i]]);
    lose[v] |= (!lose[e[v][i]]);
  }
}
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int i;
  init(0);
  size = 1;
  for (i = 0; i < n; i++) {
    scanf(" %s", S);
    int n = strlen(S);
    add(0, 0, n);
  }
  solve(0);
  if (win[0]) {
    if (lose[0])
      puts("First");
    else
      printf("%s\n", k % 2 == 1 ? "First" : "Second");
  } else
    puts("Second");
  return 0;
}
