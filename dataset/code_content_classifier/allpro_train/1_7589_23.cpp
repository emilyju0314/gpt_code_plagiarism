#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
double fRand(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}
template <class T>
T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T max(T a, T b, T c) {
  return max(a, max(b, c));
}
string s =
    "What are you doing at the end of the world? Are you busy? Will you save "
    "us?";
string t1 = "What are you doing while sending \"";
string t2 = "\"? Are you busy? Will you send \"";
string t3 = "\"?";
long long f[100005];
char Solve(int n, long long k) {
  if (k >= f[n]) return '.';
  if (n == 0) return s[k];
  if (k >= (int)t1.size() + f[n - 1] + (int)t2.size() + f[n - 1])
    return t3[k - ((int)t1.size() + f[n - 1] + (int)t2.size() + f[n - 1])];
  if (k >= (int)t1.size() + f[n - 1] + (int)t2.size())
    return Solve(n - 1, k - ((int)t1.size() + f[n - 1] + (int)t2.size()));
  if (k >= (int)t1.size() + f[n - 1])
    return t2[k - ((int)t1.size() + f[n - 1])];
  if (k >= (int)t1.size()) return Solve(n - 1, k - (int)t1.size());
  return t1[k];
}
int main() {
  f[0] = (int)s.size();
  for (int i = (1); i <= (100000); ++i)
    f[i] = min(1000000000000000007LL,
               2 * f[i - 1] + (int)t1.size() + (int)t2.size() + (int)t3.size());
  int q;
  scanf("%d", &q);
  for (int i = (1); i <= (q); ++i) {
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    printf("%c", Solve(n, k - 1));
  }
  return 0;
}
