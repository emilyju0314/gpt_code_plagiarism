#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using ld = double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
ull A;
int main(void) {
  ios::sync_with_stdio(false);
  scanf(" %llu", &A);
  if (A == 1)
    puts("1 1\n1");
  else
    printf("%lld 2\n1 2\n", (A - 1) * 2);
  return 0;
}
