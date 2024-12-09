#include <bits/stdc++.h>
using namespace std;
const int N = 7050;
long long in1[N];
long long ans[N];
long long ram1[N];
map<long long, int> s;
int main(void) {
  int n = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> in1[i];
    s[in1[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> ans[i];
  }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    if (s[in1[i]] >= 2) {
      for (int j = 1; j <= n; j++) {
        if ((in1[i] | in1[j]) == in1[i]) {
          ram1[j] = 1;
        }
      }
    }
  }
  long long sum1 = 0;
  for (int i = 1; i <= n; i++) {
    if (ram1[i] == 1) {
      sum1 += ans[i];
    }
  }
  cout << sum1 << endl;
  return 0;
}
