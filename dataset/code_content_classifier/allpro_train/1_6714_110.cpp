#include <bits/stdc++.h>
using namespace std;
const int MOD = int(1e9 + 7);
map<char, long long> m;
long long calPow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n % 2) res = (res * a) % MOD;
    a = (a * a) % MOD;
    n >>= 1;
  }
  return res;
}
long long calBit0(long long n) {
  long long cnt = 0;
  for (int i = 0; i < 6; i++) {
    if ((n & (1LL << i)) == 0) cnt++;
  }
  return cnt;
}
string s;
int main() {
  cin >> s;
  for (char i = '0', j = 0; i <= '9'; i++, j++) m[i] = j;
  for (char i = 'A', j = 10; i <= 'Z'; i++, j++) m[i] = j;
  for (char i = 'a', j = 36; i <= 'z'; i++, j++) m[i] = j;
  m['-'] = 62, m['_'] = 63;
  int len = s.size();
  long long cnt = 0;
  for (int i = 0; i < len; i++) cnt += calBit0(m[s[i]]);
  cout << calPow(3, cnt) << endl;
  return 0;
}
