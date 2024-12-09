#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using iii = pair<int, ii>;
using viii = vector<iii>;
using ll = long long int;
using vc = vector<char>;
using vb = vector<bool>;
using ib = pair<int, bool>;
using vib = vector<ib>;
vector<bool> marcaje(450000, true);
vector<ll> primes;
void sieve() {
  marcaje[0] = marcaje[1] = 0;
  for (ll i = 2; i < marcaje.size(); i++)
    if (marcaje[i]) {
      for (ll j = i * i; j < marcaje.size(); j += i) marcaje[j] = 0;
      primes.push_back(i);
    }
}
bool isPrime(ll N) {
  if (N < marcaje.size()) return marcaje[N];
  for (int i = 0; i < primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}
bool resuelveCaso() {
  sieve();
  int nc;
  cin >> nc;
  if (!cin) return false;
  for (int i = 0; i < nc; ++i) {
    ll a, b;
    cin >> a >> b;
    if (a - 1 == b) {
      ll area = b + b + 1;
      if (isPrime(area))
        cout << "YES\n";
      else
        cout << "NO\n";
    } else
      cout << "NO\n";
  }
  return true;
}
int main() {
  while (resuelveCaso()) {
  }
  return 0;
}
