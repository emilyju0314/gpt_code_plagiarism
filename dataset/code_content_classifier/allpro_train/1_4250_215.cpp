#include <bits/stdc++.h>
using namespace std;
long long ar[1000];
vector<long long> ar2;
int main() {
  long long n;
  long long res;
  res = 0;
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &ar[i]);
  }
  for (int i = 1; i < n - 1; i++) {
    if (ar[i - 1] == 1 && ar[i + 1] == 1 && ar[i] == 0) ar2.push_back(i);
  }
  for (int i = 0; i < ar2.size();) {
    if (i != ar2.size() - 1) {
      if (ar2[i] + 2 == ar2[i + 1])
        i = i + 2;
      else
        i++;
    } else
      i++;
    res++;
  }
  printf("%lld\n", res);
}
