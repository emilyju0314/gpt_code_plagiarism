#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long cub(int a) { return a * 1ll * a * 1ll * a; }
int get(long long x) {
  if (x <= 7) return x;
  int s = pow(x, 1. / 3), c = s;
  for (int a = max(1, s - 1); a < s + 2; a++)
    if (cub(a) <= s) c = a;
  return 1 + get(x - cub(c));
}
pair<int, long long> solve(long long x) {
  if (x <= 7) return make_pair(x, x);
  int c = (int)(pow(x, 1. / 3) + 0.00001);
  auto ans1 = solve(min(x - cub(c), cub(c + 1) - cub(c) - 1));
  auto ans2 = solve(min(x - cub(c - 1), cub(c) - cub(c - 1) - 1));
  if (ans1.first > ans2.first)
    return make_pair(ans1.first + 1, ans1.second + cub(c));
  if (ans1.first < ans2.first)
    return make_pair(ans2.first + 1, ans2.second + cub(c - 1));
  return make_pair(ans1.first + 1,
                   max(ans1.second + cub(c), ans2.second + cub(c - 1)));
}
int main() {
  long long x;
  scanf("%lld", &x);
  auto np = solve(x);
  printf(
      "%d "
      "%lld"
      "\n",
      np.first, np.second);
  return 0;
}
