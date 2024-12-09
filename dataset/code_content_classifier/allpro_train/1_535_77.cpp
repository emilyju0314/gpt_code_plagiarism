#include <bits/stdc++.h>
using namespace std;
long long int n, m, l, r, x;
long long int arr[1000006];
vector<int> primes;
void getPrime() {
  int prime[10001] = {0};
  for (int i = 2; i < 10001; ++i) {
    if (!prime[i]) {
      primes.push_back(i);
      for (int j = i + i; j < 10001; j += i) {
        prime[j] = 1;
      }
    }
  }
}
void TestingChaluKarEyy() {
  cin >> n;
  for (int i = n; i <= 2 * n - 1; ++i) cout << i * 2 << " ";
  cout << "\n";
}
void sublime() {}
int main() {
  sublime();
  getPrime();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int TestingKaravvuChhe = 1;
  cin >> TestingKaravvuChhe;
  while (TestingKaravvuChhe--) {
    TestingChaluKarEyy();
  }
}
