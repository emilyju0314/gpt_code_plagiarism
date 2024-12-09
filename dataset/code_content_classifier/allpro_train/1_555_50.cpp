#include <bits/stdc++.h>
using namespace std;
const int MM = 1000000007;
const int MX = 100005;
string D;
long long cK[MX], cL[MX], tot[MX];
char s[100005];
long long pw(long long a, int b) {
  long long ans = 1, mul = a;
  while (b) {
    if (b & 1) ans = ans * mul % MM;
    mul = mul * mul % MM;
    b /= 2;
  }
  return ans;
}
long long rev(long long a) { return pw(a, MM - 2); }
int main() {
  int N, K;
  scanf("%d%d%s", &N, &K, s);
  D = s;
  N--;
  cK[K] = 1, cL[K - 1] = 1;
  cL[K] = K;
  for (int i = K + 1; i < MX; i++) {
    cK[i] = cK[i - 1] * i % MM * rev(i - K) % MM;
    cL[i] = cL[i - 1] * i % MM * rev(i - K + 1) % MM;
  }
  long long mul = 10, ans = 0;
  tot[0] = cL[N - 1];
  for (int i = 1; i < MX; i++) {
    tot[i] = (tot[i - 1] + cL[N - i - 1] * mul) % MM;
    mul = mul * 10 % MM;
  }
  mul = 1;
  for (int i = N; i >= 0; i--) {
    ans += (D[i] - '0') * ((i == N ? 0 : tot[N - i - 1]) + mul * cK[i] % MM);
    mul = mul * 10 % MM;
    ans %= MM;
  }
  printf("%I64d", ans);
}
