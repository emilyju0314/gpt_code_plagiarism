#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e6 + 5;
int buf[maxm];
double q[maxm];
int len[maxm];
void run_case() {
  int n;
  scanf("%d", &n);
  int top = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &buf[i]);
  q[++top] = buf[1], len[1] = 1;
  for (int i = 2; i <= n; ++i) {
    double now = buf[i];
    int nowlen = 1;
    while (q[top] > now) {
      now = (now * nowlen + q[top] * len[top]) / (nowlen + len[top]);
      nowlen += len[top--];
    }
    q[++top] = now, len[top] = nowlen;
  }
  for (int i = 1; i <= top; ++i)
    for (int j = 0; j < len[i]; ++j) printf("%.10f\n", q[i]);
}
int main() {
  run_case();
  return 0;
}
