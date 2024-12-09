#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long ans, n, m;
char s1[1000010], s2[1000010];
int num[1000010][26];
int main() {
  int len1, len2;
  int i, j, k;
  cin >> n >> m;
  scanf("%s%s", s1, s2);
  len1 = strlen(s1);
  len2 = strlen(s2);
  int g = gcd(len1, len2);
  for (i = 0; i < len2; i++) num[i % g][s2[i] - 'a']++;
  long long ci = n / (len2 / g);
  for (i = 0; i < len1; i++) ans += num[i % g][s1[i] - 'a'] * ci;
  ans = n * len1 - ans;
  cout << ans << endl;
}
