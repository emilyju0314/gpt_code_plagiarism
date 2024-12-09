#include <bits/stdc++.h>
using namespace std;
long long int n, I;
vector<long long int> vec;
vector<long long int> comp;
long long int K;
int main() {
  scanf("%lld %lld", &n, &I);
  for (int i = 1; i <= n; i++) {
    long long int a;
    scanf("%lld", &a);
    vec.push_back(a);
  }
  K = 1 << min((long long int)20, 8 * I / n);
  sort(vec.begin(), vec.end());
  long long int pre = -1;
  for (int i = 1; i <= n; i++) {
    if (vec[i - 1] != pre) {
      comp.push_back(i);
      pre = vec[i - 1];
    }
  }
  if (8 * I / n >= 20) {
    printf("0");
    return 0;
  }
  int ans = 1000000000;
  for (int i = 0; i < comp.size(); ++i) {
    int num = comp[i] - 1 + (i + K < comp.size() ? n + 1 - comp[i + K] : 0);
    ans = min(num, ans);
  }
  printf("%d", ans);
  return 0;
}
