#include <iostream>
using namespace std;

int main() {
	long long X, K, D;
	cin >> X >> K >> D;
	if (X < 0) X *= -1ll;
	if (X / D >= K) {
		cout << X - K * D << endl;
		return 0;
	}
	K -= X / D;
	X = X % D;
	cout << (K % 2ll == 0ll ? X : D - X) << endl;
}
