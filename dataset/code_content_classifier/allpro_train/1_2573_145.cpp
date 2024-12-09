#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  int adj[n][n];
  memset(adj, 0, sizeof(adj));
  if (min(a, b) > 1) {
    printf("NO");
    return 0;
  }
  if (a == 1 && b == 1) {
    if (n == 2 || n == 3) {
      printf("NO");
    } else {
      printf("YES\n");
      for (int i = 0; i < n - 1; i++) adj[i][i + 1] = adj[i + 1][i] = 1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d", adj[i][j]);
        cout << endl;
      }
    }
    return 0;
  }
  printf("YES\n");
  bool x = 0;
  if (a == 1) {
    swap(a, b);
    x = 1;
  }
  for (int i = 0; i < n - a; i++) adj[i][i + 1] = adj[i + 1][i] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j)
        printf("%d", adj[i][j] ^ x);
      else
        printf("%d", 0);
    }
    cout << endl;
  }
}
