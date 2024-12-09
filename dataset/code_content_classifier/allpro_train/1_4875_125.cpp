#include <bits/stdc++.h>
using namespace std;
struct Node {
  int i, j;
  double Value;
};
bool operator<(Node A, Node B) { return A.Value < B.Value; }
int Get() {
  char c;
  while (c = getchar(), c < '0' || c > '9')
    ;
  int X = 0;
  while (c >= '0' && c <= '9') {
    X = X * 10 + c - 48;
    c = getchar();
  }
  return X;
}
int main() {
  int N = Get(), M = Get();
  static double P[3000][300];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) P[i][j] = (double)Get() / 1000;
  static double DP[300][3000];
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) DP[i][j] = 1;
  priority_queue<Node> All;
  for (int i = 0; i < M; i++) All.push((Node){0, i, 1.0});
  double Ans = 0;
  for (int Rest = N; Rest;) {
    Node T = All.top();
    All.pop();
    if (T.i) {
      Rest--;
      Ans += T.Value;
    }
    if (T.i == N) continue;
    int K = T.j;
    double Temp = T.i ? DP[K][T.i - 1] : 1;
    for (int i = 0; i < T.i; i++) DP[K][i] = 0;
    for (int i = T.i; i < N; i++) {
      double New = DP[K][i];
      DP[K][i] = P[i][K] * Temp;
      if (i) DP[K][i] += (1 - P[i][K]) * DP[K][i - 1];
      Temp = New;
    }
    All.push((Node){T.i + 1, K, DP[K][N - 1]});
  }
  printf("%0.10lf\n", Ans);
  return 0;
}
