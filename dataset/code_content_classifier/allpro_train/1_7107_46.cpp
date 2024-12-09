#include <bits/stdc++.h>
using namespace std;
long long int mpow(long long int a, long long int b) {
  if (!b) return 1;
  long long int temp = mpow(a, b / 2);
  temp = (temp * temp) % 1000000007;
  if (b % 2) return (a * temp) % 1000000007;
  return temp;
}
long long int mod_in(long long int n) { return mpow(n, 1000000007 - 2); }
long long int cl(long long int a, long long int b) {
  if (a % b) return 1 + a / b;
  return a / b;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0;
    exit(0);
  }
  if (a < b) swap(a, b);
  vector<long long int> V;
  for (i = 1; i * i <= (a - b); i++) {
    if ((a - b) % i == 0) {
      V.push_back(i);
      V.push_back((a - b) / i);
    }
  }
  long long int ans = 1000000000000000000, f_ans;
  for (i = 0; i < V.size(); i++) {
    long long int g = V[i];
    long long int k = (g - b % g) % g;
    long long int v = ((a + k) * (b + k)) / g;
    if (v < ans) {
      ans = v;
      f_ans = k;
    }
  }
  cout << f_ans << "\n";
}
