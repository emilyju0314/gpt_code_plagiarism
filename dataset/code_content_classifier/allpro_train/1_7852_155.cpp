#include <bits/stdc++.h>
using namespace std;
inline long long int gcd(long long int a, long long int b) {
  long long int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline long long int lcm(long long int a, long long int b) {
  return a / gcd(a, b) * b;
}
int main() {
  string s;
  int hash[26] = {0}, one = 0, two = 0, count = 0, f1 = 0;
  cin >> s;
  if (s.length() >= 4) {
    for (int i = 0; i < s.length(); i++) {
      hash[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (hash[i] > 0) count++;
      if (hash[i] == 1) one++;
      if (hash[i] >= 2) two++;
    }
    if (count == 1) f1 = 1;
    if (count == 2)
      if (two < 2) f1 = 1;
    if (count > 4) f1 = 1;
  } else
    f1 = 1;
  if (f1 == 0)
    cout << "Yes";
  else
    cout << "No";
}
