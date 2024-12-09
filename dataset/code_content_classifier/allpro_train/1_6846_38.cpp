#include <bits/stdc++.h>
using namespace std;
char S[500005], T[500005];
int LS, LT, CS[2], CT[2], CP[2], b[500005], B;
int main() {
  scanf("%s", S);
  LS = strlen(S);
  scanf("%s", T);
  LT = strlen(T);
  if (LT > LS) {
    printf("%s\n", S);
    return 0;
  }
  for (int i = 0; i < LS; i++) CS[S[i] - '0']++;
  for (int i = 0; i < LT; i++) CT[T[i] - '0']++;
  if (CT[0] > CS[0] || CT[1] > CS[1]) {
    printf("%s\n", S);
    return 0;
  }
  for (int i = 1; i < LT; i++) {
    int k = b[i - 1];
    while (k && T[i] != T[k]) k = b[k - 1];
    b[i] = (T[i] == T[k]) ? k + 1 : 0;
  }
  printf("%s", T);
  CS[0] -= CT[0], CS[1] -= CT[1];
  B = b[LT - 1];
  for (int i = B; i < LT; i++) CP[T[i] - '0']++;
  int K = min(CP[0] ? (CS[0] / CP[0]) : 1e9, CP[1] ? (CS[1] / CP[1]) : 1e9);
  CS[0] -= K * CP[0];
  CS[1] -= K * CP[1];
  while (K--) {
    printf("%s", T + B);
  }
  for (int i = 0; i < 2; i++)
    while (CS[i]--) printf("%c", i + '0');
  printf("\n");
}
