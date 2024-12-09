#include <bits/stdc++.h>
using namespace std;
int n, q, c;
int w[310000];
long long ans[310000];
long long dp[310000];
vector<pair<pair<int, int>, int> > v;
inline long long s(int a, int b) {
  long long sum = 0;
  for (; a < n; a += b) sum += w[a];
  return sum;
}
int main() {
  scanf("%d", &n);
  c = sqrt(n + .0) + 1;
  for (int i = 0; i < n; ++i) scanf("%d", w + i);
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    v.push_back(make_pair(make_pair(b, a), i));
  }
  sort(v.begin(), v.end());
  int pb = -1;
  for (int i = 0; i < v.size(); ++i) {
    int b = v[i].first.first;
    if (b != pb && b < c) {
      for (int j = n - 1; j >= 0; --j)
        if (j + b >= n)
          dp[j] = w[j];
        else
          dp[j] = w[j] + dp[j + b];
    }
    int a = v[i].first.second;
    int ind = v[i].second;
    if (b >= c)
      ans[ind] = s(a, b);
    else {
      ans[ind] = dp[a];
    }
    pb = b;
  }
  for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
}
