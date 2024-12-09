#include <iostream>
#include <vector>
#define rep(i, a) for (int i = 0; i < (a); i++)
using namespace std;

int main() {
	int n;
	cin >> n;

	int odd = 0, even = 0;
	rep(i, n) {
		int a;
		cin >> a;
		if (a % 2)
			odd++;
		else
			even++;
	}

	if (odd == 0 or even == 0)
		cout << 0 << endl;
	else {
		odd--;
		int ans = odd / 2;
		even += odd / 2;
		ans += even;
		cout << ans << endl;
	}
}

