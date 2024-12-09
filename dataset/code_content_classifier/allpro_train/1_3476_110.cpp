#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, x, n, m, k, q;
long long a[5000005];
vector<long long> v1, vis;
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld", &n);
    string s1;
    cin >> s1;
    long long sum1 = n, sum2 = n;
    long long maxim1 = 0, minim1 = 0;
    long long maxim2 = 0, minim2 = 0;
    for (long long i = 0; i < n; i++) {
      if (s1[i] == '1') {
        maxim1 = max(i, n - i);
        minim1 = min(i, n - i);
        break;
      }
    }
    for (long long i = n - 1; i >= 0; i--) {
      if (s1[i] == '1') {
        maxim2 = max(i + 1, n - i - 1);
        minim2 = min(i + 1, n - i - 1);
        break;
      }
    }
    sum1 += maxim1;
    sum1 -= minim1;
    sum2 += maxim2;
    sum2 -= minim2;
    printf("%lld", max(sum1, sum2));
    printf("\n");
  }
}
