#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
float arr[maxn];
map<float, int> cnt;
int main() {
  int n, a, b, c;
  char ch;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> ch;
    scanf("%d+%d)/%d", &a, &b, &c);
    arr[i] = (a + b + 0.0) / (c + 0.0);
    cnt[arr[i]]++;
  }
  for (int i = 0; i < n; i++) printf("%d ", cnt[arr[i]]);
  return 0;
}
