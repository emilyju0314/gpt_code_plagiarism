#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main()
{
	ld v;
	while (cin >> v) {
		for (int i = 1;; i++) {
			if (v * v <= 98 * i - 98) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}