#include <bits/stdc++.h>
using namespace std;
bool check[1000001];
vector<int> prime;
void sieve() {
  check[1] = true;
  for (int i = 2; i <= 1000001; i++) {
    if (check[i] == false) {
      for (int j = 2 * i; j <= 1000001; j += i) {
        check[j] = true;
      }
    }
  }
}
long long int power(long long int n) {
  long long int a = 2;
  long long int res = 1;
  while (n) {
    if (n & 1) {
      res = (res * a);
    }
    n >>= 1;
    a = a * a;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  sieve();
  for (int i = 1; i <= 1000; i++) {
    if (check[n * i + 1]) {
      cout << i << endl;
      return 0;
    }
  }
}
