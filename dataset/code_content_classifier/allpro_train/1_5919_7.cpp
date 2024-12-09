#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 28;
const long long mod = 1LL;
char arr[210][210];
long long par[210];
bool col[210];
vector<long long> adjacency[210];
int main() {
  long long n, i, j, k, l;
  while (cin >> n) {
    for (i = 0; i < n; i++) adjacency[i].clear(), scanf(" %s", arr[i]);
    k = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
        if (arr[i][j] == '.') {
          adjacency[i].push_back(j);
          k++;
          break;
        }
    }
    if (k == n) {
      for (i = 0; i < n; i++)
        printf("%I64d %I64d\n", i + 1, adjacency[i][0] + 1);
      return 0;
    }
    k = 0;
    for (i = 0; i <= n; i++) adjacency[i].clear();
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++)
        if (arr[j][i] == '.') {
          adjacency[i].push_back(j);
          k++;
          break;
        }
    }
    if (k == n) {
      for (i = 0; i < n; i++)
        printf("%I64d %I64d\n", adjacency[i][0] + 1, i + 1);
      return 0;
    }
    printf("-1\n");
  }
  return 0;
}
