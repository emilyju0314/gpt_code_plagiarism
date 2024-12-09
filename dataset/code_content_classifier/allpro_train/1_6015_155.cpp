#include <bits/stdc++.h>
using namespace std;
int h[100010];
int ope[100010];
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < (int)(N); i++) scanf("%d", h + i + 1);
  for (int i = 0; i < (int)(N); i++) ope[i + 1] = min(ope[i] + 1, h[i + 1]);
  int ans = 0;
  for (int i = 0; i < (int)(N); i++) {
    ope[N - i] = min(ope[N - i], ope[N - i + 1] + 1);
    ans = max(ans, ope[N - i]);
  }
  cout << ans << endl;
  return 0;
}
