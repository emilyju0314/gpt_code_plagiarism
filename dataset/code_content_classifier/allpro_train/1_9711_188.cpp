#include <bits/stdc++.h>
using namespace std;
int f(int n) {
  n += 1;
  while (n % 10 == 0) {
    n /= 10;
  }
  return n;
}
int main() {
  int n;
  scanf("%d", &n);
  map<int, int> mp;
  mp[n]++;
  n = f(n);
  while (!mp[n]) {
    mp[n]++;
    n = f(n);
  }
  printf("%d\n", mp.size());
  return 0;
}
