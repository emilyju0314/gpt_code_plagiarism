#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
int v[250];
void calc() {
  double media = 0;
  for (int i = 0; i < 250; i++) media += v[i];
  media /= 250.0;
  double dp = 0;
  for (int i = 0; i < 250; i++) dp += (v[i] - media) * (v[i] - media);
  dp /= 250.0;
  if (media * 2 > dp) {
    puts("poisson");
  } else {
    puts("uniform");
  }
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    for (int i = 0; i < 250; i++) scanf("%d", &v[i]);
    calc();
  }
  return 0;
}
