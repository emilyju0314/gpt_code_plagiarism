#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<long long, short> > mass;
  long n, k;
  scanf("%li %li", &n, &k);
  long long a, b;
  for (long i = 0; i < n; i++) {
    scanf("%I64d %I64d", &a, &b);
    mass.push_back(make_pair(a, -1));
    mass.push_back(make_pair(b, 1));
  }
  sort(mass.begin(), mass.end());
  vector<pair<long long, long long> > ans(n);
  long long x = 0, balance = 0;
  for (long i = 0; i < n * 2; i++) {
    if (mass[i].second == -1 && balance == k - 1) ans[x].first = mass[i].first;
    if (balance == k && mass[i].second == 1) ans[x++].second = mass[i].first;
    balance -= mass[i].second;
  }
  printf("%I64d \n", x);
  for (long i = 0; i < x; i++)
    printf("%I64d %I64d \n", ans[i].first, ans[i].second);
}
