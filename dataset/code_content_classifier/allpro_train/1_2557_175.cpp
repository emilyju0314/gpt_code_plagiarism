#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x1, x2;
  scanf("%d %d %d", &n, &x1, &x2);
  vector<pair<pair<long long, int>, int>> y1, y2;
  for (int i = 0; i < n; i++) {
    int k, b;
    scanf("%d %d", &k, &b);
    y1.push_back({{static_cast<long long>(k) * x1 + b, k}, i});
    y2.push_back({{static_cast<long long>(k) * x2 + b, -k}, i});
  }
  sort(y1.begin(), y1.end());
  sort(y2.begin(), y2.end());
  for (int i = 0; i < n; i++) {
    if (y1[i].second != y2[i].second) {
      printf("Yes");
      return 0;
    }
  }
  printf("No");
}
