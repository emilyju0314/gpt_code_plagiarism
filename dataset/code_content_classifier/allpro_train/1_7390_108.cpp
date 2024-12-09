#include <bits/stdc++.h>
using namespace std;
long long int _xor(long long int a, long long int b) { return a ^ b; }
long long int _and(long long int a, long long int b) { return a & b; }
long long int _or(long long int a, long long int b) { return a | b; }
long long int _not(long long int a) { return ~a; }
long long int pos[1000004], khaoa[2000005];
bool comp(string a, string b) { return a.length() < b.length(); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, ans = 0, j, f;
  cin >> n;
  long long int a[n], b[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    cin >> b[i];
  }
  for (long long i = 0; i < n; i++) {
    f = 0;
    for (long long j = 0; j < n; j++) {
      if (a[i] == b[j] && i != j) {
        f = 1;
      }
    }
    if (f == 1) {
      ans++;
    }
  }
  cout << n - ans;
}
