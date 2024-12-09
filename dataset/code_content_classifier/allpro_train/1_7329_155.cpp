#include <bits/stdc++.h>
using namespace std;
long long binary(long long a, long long p) {
  if (p == 0) return 1;
  if (p == 1) return a;
  long long k = binary(a, p / 2);
  k *= k;
  k %= 1000000007;
  if (p % 2) k *= a;
  k %= 1000000007;
  return k;
}
long long fat[1123456];
long long inv[1123456];
void process() {
  fat[0] = 1;
  fat[1] = 1;
  inv[1] = 1;
  for (long long i = 2; i < 1123456; i++) {
    fat[i] = fat[i - 1] * i;
    fat[i] %= 1000000007;
    inv[i] = binary(fat[i], 1000000007 - 2);
  }
}
long long cnt[26];
long long f(string a) {
  long long n = a.size();
  long long ans = 0;
  long long tot = a.size();
  for (long long i = 0; i < n; i++) {
    long long number = 0;
    for (long long c = 0; c < (long long)(a[i] - 'a'); c++) {
      if (cnt[c] != 0) number++;
    }
    long long add = fat[tot - 1];
    long long mul = 1;
    for (long long j = 0; j < 26; j++) {
      if (cnt[j] == 0) continue;
      mul *= inv[cnt[j]];
      mul %= 1000000007;
    }
    long long sum = 0;
    for (long long j = 0; j < 26; j++) {
      if (cnt[j] == 0) continue;
      if (j >= (long long)(a[i] - 'a')) continue;
      long long aux = mul;
      aux *= fat[cnt[j]];
      aux %= 1000000007;
      if (cnt[j] > 1) aux *= inv[cnt[j] - 1];
      aux %= 1000000007;
      sum += aux;
      sum %= 1000000007;
    }
    add *= sum;
    add %= 1000000007;
    ans += add;
    ans %= 1000000007;
    if (cnt[a[i] - 'a'] > 0) {
      cnt[a[i] - 'a']--;
      tot--;
    } else
      break;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a >> b;
  long long n = a.size();
  for (long long i = 0; i < 26; i++) cnt[i] = 0;
  for (long long i = 0; i < n; i++) {
    cnt[a[i] - 'a']++;
  }
  process();
  long long fb = f(b);
  for (long long i = 0; i < 26; i++) cnt[i] = 0;
  for (long long i = 0; i < n; i++) {
    cnt[a[i] - 'a']++;
  }
  long long fa = f(a);
  cout << ((fb - fa - 1) % 1000000007 + 1000000007) % 1000000007 << endl;
}
