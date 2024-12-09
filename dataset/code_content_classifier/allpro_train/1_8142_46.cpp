#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
const int P = (1 << 16);
int N;
long long X, Y;
long long A[MAXN];
int m1[P], m2[P];
vector<long long> plist;
long long gcf(long long a, long long b) {
  return ((b == 0) ? a : gcf(b, a % b));
}
long long pplist(long long a) {
  for (int i = 2; i <= 1000000; i++) {
    if (a % i == 0) {
      plist.push_back(i);
      while (a % i == 0) a /= i;
    }
  }
  return a;
}
int clean(long long v) {
  int res = 0;
  for (int i = 0; i < plist.size(); i++) {
    if (v % plist[i] == 0) res += (1 << i);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> N;
  cin >> X >> Y;
  for (int i = 0; i < N; i++) cin >> A[i];
  if (Y % X != 0) {
    cout << "0\n";
    return 0;
  }
  long long nm = pplist(Y / X);
  if (nm > 1) plist.push_back(nm);
  for (int i = 0; i < N; i++) {
    long long g = gcf(nm, A[i]);
    if (g > 1 && g < nm) {
      plist.push_back(g);
      plist.push_back(nm / g);
      break;
    }
  }
  for (int i = 0; i < N; i++) {
    if (A[i] % X == 0) {
      long long v = gcf(A[i], Y) / X;
      m1[clean(v)]++;
    }
    if (Y % A[i] == 0) {
      long long v = Y / (A[i] / gcf(A[i], X) * X);
      m2[clean(v)]++;
    }
  }
  for (int i = 0; i < 16; i++)
    for (int j = 0; j < P; j++)
      if (!(j & (1 << i))) m1[j + (1 << i)] += m1[j];
  long long ans = 0;
  for (int i = 0; i < P; i++) ans += m1[i] * (long long)m2[(P - 1 - i)];
  cout << ans << "\n";
}
