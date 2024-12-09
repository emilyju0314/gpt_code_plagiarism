#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
unsigned long long hash1[N], hash2[N];
unsigned long long p[N];
int num[N];
string s[5];
unsigned long long get(unsigned long long hash[], int R, int L) {
  return hash[R] - hash[L - 1] * p[R - L + 1];
}
void init(int n) {
  p[0] = 1;
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] * 131;
}
string merge(string a, string b) {
  a = " " + a;
  b = " " + b;
  int lena = a.length() - 1, lenb = b.length() - 1;
  for (int i = 1; i <= lena; i++) hash1[i] = hash1[i - 1] * 131 + a[i] - '0';
  for (int i = 1; i <= lenb; i++) hash2[i] = hash2[i - 1] * 131 + b[i] - '0';
  for (int i = 1; i <= lena - lenb + 1; i++)
    if (hash1[i + lenb - 1] - hash1[i - 1] * p[lenb] == hash2[lenb])
      return a.substr(1);
  for (int i = max(1, lena - lenb + 2); i <= lena; i++) {
    int len = lena - i + 1;
    if (hash1[lena] - hash1[i - 1] * p[len] == hash2[len])
      return a.substr(1) + b.substr(len + 1);
  }
  return a.substr(1) + b.substr(1);
}
string merge(string a, string b, string c) { return merge(merge(a, b), c); }
int main() {
  init(300005);
  for (int i = 1; i <= 3; i++) cin >> s[i];
  for (int i = 1; i <= 3; i++) num[i] = i;
  int MIN = N;
  do {
    string ans = merge(s[num[1]], s[num[2]], s[num[3]]);
    MIN = min((int)ans.length(), MIN);
  } while (next_permutation(num + 1, num + 4));
  printf("%d\n", MIN);
}
