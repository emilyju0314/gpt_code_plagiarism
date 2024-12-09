#include <bits/stdc++.h>
using namespace std;
int N, M, P, Dsum[100010];
long long A[100010], B[100010][103], ans;
void scaninput() {
  scanf("%d%d%d", &N, &M, &P);
  for (int i = 2; i <= N; i++) {
    int D;
    scanf("%d", &D);
    Dsum[i] = Dsum[i - 1] + D;
  }
  for (int i = 0; i < M; i++) {
    int H, T;
    scanf("%d%d", &H, &T);
    A[i] = T - Dsum[H] + Dsum[1];
  }
  sort(A, A + M);
}
deque<long long> dq[103];
void DQpush(int i, int j) {
  while (dq[j].size() >= 2) {
    int a = *(dq[j].end() - 2);
    int b = *(dq[j].end() - 1);
    int c = i;
    long long v1 = (B[a][j] - B[b][j]) * (c - b);
    long long v2 = (B[b][j] - B[c][j]) * (b - a);
    if (v1 < v2) break;
    dq[j].pop_back();
  }
  dq[j].push_back(i);
}
long long DQquery(int i, int j) {
  long long X = A[i] - A[M - 1];
  while (dq[j].size() >= 2) {
    int a = *(dq[j].begin() + 0);
    int b = *(dq[j].begin() + 1);
    long long v1 = a * X + B[a][j];
    long long v2 = b * X + B[b][j];
    if (v1 > v2) break;
    dq[j].pop_front();
  }
  int a = dq[j].front();
  return (A[M - 1] - A[i]) * (i - a) + B[a][j];
}
void solve() {
  long long bst = 0;
  for (int i = 0; i < M; i++) {
    ans += A[M - 1] - A[i];
    for (int j = 1; j <= P; j++) {
      if (j > i + 1) break;
      if (j == 1)
        B[i][j] = (A[M - 1] - A[i]) * (i + 1);
      else
        B[i][j] = DQquery(i, j - 1);
      if (i == M - 1 || j != P) bst = max(bst, B[i][j]);
      DQpush(i, j);
    }
  }
  printf("%I64d\n", ans - bst);
}
int main() {
  scaninput();
  solve();
}
