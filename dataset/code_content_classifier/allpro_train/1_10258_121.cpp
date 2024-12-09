#include <bits/stdc++.h>
using namespace std;
int n;
long long sum = 0;
char a[55];
int main() {
  scanf("%d%s", &n, a);
  for (int i = n - 1; i >= 0; i--)
    if (a[i] == 'B') sum += pow(2, i);
  cout << sum;
  return 0;
}
