#include <bits/stdc++.h>
using namespace std;
bool siv[100000];
vector<long long> prime;
void sieve();
void pri();
long long int fact(long long int n);
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = n - a;
  if (ans > b) {
    cout << b + 1 << endl;
  } else {
    cout << ans << endl;
  }
}
void sieve() {
  memset(siv, true, sizeof(siv));
  int root = sqrt(100000);
  for (int i = 2; i <= root; i++) {
    for (int j = i * 2; j <= 100000; j += i) {
      siv[j] = false;
    }
  }
}
void pri() {
  sieve();
  siv[0] = false;
  siv[1] = false;
  for (int i = 0; i < 100000; i++)
    if (siv[i] == true) prime.push_back(i);
}
long long int fact(long long int n) {
  long long int ans = 1;
  for (long long int i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}
