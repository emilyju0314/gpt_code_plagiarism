#include <bits/stdc++.h>
using namespace std;
pair<int, int> b[300001];
int ret[300001];
int main() {
  int n, val;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    b[i] = pair<int, int>(val, i);
  }
  sort(b, b + n);
  ret[b[0].second] = b[0].first;
  for (int i = 1; i < n; i++) {
    if (b[i - 1].first >= b[i].first) b[i].first = b[i - 1].first + 1;
    ret[b[i].second] = b[i].first;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", ret[i]);
  }
  puts("");
  return 0;
}
