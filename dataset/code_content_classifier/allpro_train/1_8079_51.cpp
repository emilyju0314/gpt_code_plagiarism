#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100 * 1000;
int ok[MaxN];
int bad[MaxN];
char TYPE[MaxN];
int QUERY[MaxN];
bool crime[MaxN];
int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  int sumWrong = 0;
  for (int i = 0; i < n; i++) {
    char type;
    int x;
    scanf("%c%d", &type, &x);
    if (i != n - 1) scanf("\n");
    TYPE[i] = type;
    QUERY[i] = x - 1;
    if (type == '+') {
      bad[x - 1]++;
    } else {
      ok[x - 1]++;
      sumWrong++;
    }
  }
  int sz = 0;
  for (int i = 0; i < n; i++) {
    int right = bad[i] + sumWrong - ok[i];
    if (right == m) {
      crime[i] = true;
      sz++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (TYPE[i] == '-') {
      if (!crime[QUERY[i]]) printf("Truth\n");
      if (crime[QUERY[i]] && sz > 1) printf("Not defined\n");
      if (crime[QUERY[i]] && sz == 1) printf("Lie\n");
    } else {
      if (!crime[QUERY[i]]) printf("Lie\n");
      if (crime[QUERY[i]] && sz > 1) printf("Not defined\n");
      if (crime[QUERY[i]] && sz == 1) printf("Truth\n");
    }
  }
}
