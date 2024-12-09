#include <bits/stdc++.h>
using namespace std;
map<char, long long int> m;
char c;
int n;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("\n%c", &c);
    m[c]++;
  }
  printf("%I64d\n", abs(m['0'] - m['1']));
  return 0;
}
