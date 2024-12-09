#include <bits/stdc++.h>
using namespace std;
bool cmp(long long int a, long long int b) {
  int cnta, cntb;
  cnta = cntb = 0;
  while (a % 3 == 0) {
    a /= 3;
    cnta++;
  }
  while (b % 3 == 0) {
    b /= 3;
    cntb++;
  }
  if (cnta == cntb) return a < b;
  return cnta > cntb;
}
int main() {
  int n;
  long long int num[1005];
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      cin >> num[i];
    }
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) {
      cout << num[i] << (i == n - 1 ? "\n" : " ");
    }
  }
  return 0;
}
