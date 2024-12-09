#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main(void) {
	int num, i;
	ll ans = 1;
	cin >> num;
	vector<int> s(num), t(num), ss(num, false), tt(num, false);
	for (i = 0; i < num; i++)
		scanf("%d", &s[i]);
	for (i = 0; i < num; i++)
		scanf("%d", &t[i]);
	for (i = num - 1; i > 0; i--) {
		if (s[i] != s[i - 1])
			ss[i] = true;
	}
	for (i = 0; i < num - 1; i++) {
		if (t[i] != t[i + 1])
			tt[i] = true;
	}
	ss[0] = true;
	tt[num - 1] = true;
	for (i = 0; i < num; i++) {
		if (ss[i]) {
			if (s[i] > t[i])
				ans = 0;
			if (tt[i] && s[i] != t[i])
				ans = 0;
			s[i] = 1;
		}
		else if (tt[i]) {
			if (t[i] > s[i])
				ans = 0;
			t[i] = 1;
		}
		ans *= (ll)min(s[i], t[i]);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}