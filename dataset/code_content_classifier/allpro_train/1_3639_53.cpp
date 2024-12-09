#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	ll	a, b;
	cin >> a >> b;
	bitset<32>	bsa(a), bsb(b);

	cout << (bsa & bsb) << endl;
	cout << (bsa | bsb) << endl;
	cout << (bsa ^ bsb) << endl;
}

