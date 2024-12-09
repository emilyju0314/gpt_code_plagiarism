#include <bits/stdc++.h>
using namespace std;
const int p_limit = 1000020;
int status[p_limit + 1];
vector<int> prime;
void factorization_sieve() {
  prime.push_back(2);
  int i;
  for (i = 3; i < p_limit / 2; i += 2) {
    if (status[i] == 0) {
      prime.push_back(i);
      for (int j = i; j <= p_limit; j += i) {
        status[j] = i;
      }
    }
  }
  for (; i <= p_limit; i += 2) {
    if (status[i] == 0) {
      prime.push_back(i);
      status[i] = i;
    }
  }
}
int main() {
  factorization_sieve();
  int x2, x0 = INT_MAX;
  cin >> x2;
  int large_prime_x2 = status[x2];
  if (large_prime_x2 == 0) large_prime_x2 = 2;
  for (int x1 = x2 - large_prime_x2 + 1; x1 <= x2; x1++) {
    int large_prime_x1 = status[x1];
    if (large_prime_x1 == 0) large_prime_x1 = 2;
    if (x1 - large_prime_x1 + 1 < x0 && status[x1] != x1)
      x0 = x1 - large_prime_x1 + 1;
  }
  cout << x0;
}
