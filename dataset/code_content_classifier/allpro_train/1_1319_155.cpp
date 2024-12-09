#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
void primegen(int ub) {
  bool w[1001] = {false};
  for (int p = 2; p <= ub; p++)
    if (!w[p]) {
      for (int i = p; i <= ub; i += p) w[i] = true;
      primes.push_back(p);
    }
}
int main() {
  string s;
  cin >> s;
  int len = int((s).size());
  primegen(len);
  int c[26] = {0};
  bool mul[len];
  for (int i = (0); i < (len); i++) {
    mul[i] = false;
    c[s[i] - 'a']++;
  }
  for (int i = (0); i < (int((primes).size())); i++) {
    if (primes[i] * 2 > len) break;
    for (int p = primes[i]; p <= len; p += primes[i]) mul[p - 1] = true;
  }
  int req = 0, provider = 0;
  for (int i = (0); i < (len); i++) req += mul[i];
  for (int i = (0); i < (26); i++)
    if (c[provider] < c[i]) provider = i;
  if (c[provider] < req)
    cout << "NO";
  else {
    c[provider] -= req;
    for (int i = (0); i < (len); i++) {
      if (mul[i])
        s[i] = 'a' + provider;
      else
        for (int j = (0); j < (26); j++)
          if (c[j]) {
            s[i] = 'a' + j;
            c[j]--;
            break;
          }
    }
    cout << "YES" << endl << s;
  }
  return 0;
}
