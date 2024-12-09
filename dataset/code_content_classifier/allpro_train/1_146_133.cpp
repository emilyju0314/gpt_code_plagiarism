#include <iostream>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

map<ll, ll> prime_factor(ll n){
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

int main(int argc, char const *argv[])
{
	ll n, p;
	cin >> n >> p;
	map<ll, ll> mp;
	mp = prime_factor(p);
	ll ans = 1;
	for (auto x : mp){
		if (x.second >= n) ans*=pow(x.first, x.second/n);
	}
	cout << ans << endl;
	return 0;
}