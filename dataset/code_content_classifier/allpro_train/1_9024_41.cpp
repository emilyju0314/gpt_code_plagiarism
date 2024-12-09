#include <bits/stdc++.h>
using namespace std;
bool prime(long long num) {
  if (num < 4 && num > 1) return true;
  if (num == 1 || num % 2 == 0 || num % 3 == 0) return false;
  long long c = 5;
  while (c * c <= num) {
    if (num % c == 0 || num % (c + 2) == 0) return false;
    c += 6;
  }
  return true;
}
int t, n;
int main() {
  scanf("%d", &t);
  while (t--) {
    cin >> n;
    int s2 = 0, s55 = 0, one = 1;
    if (n == 1) one = 0;
    while (n % 2 == 0) {
      s2 += 1;
      n /= 2;
    }
    if ((n == 1 && s2 > 0) || (s2 == 1 && prime(n))) one = 0;
    if (n == 1 && s2 == 1) one = 1;
    printf(one ? "Ashishgup\n" : "FastestFinger\n");
  }
  return 0;
}
