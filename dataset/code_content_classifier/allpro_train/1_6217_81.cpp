#include <iostream>
#include <math.h>
#include <algorithm>


using namespace std;

int main() {
	int d, w, h;
	while (true) {
		cin >> d >> w >> h;
		if (!d && !w && !h)break;
		int min1, min2;
		min1 = min(d, w);
		if (min1 == d)min2 = min(w, h);
		else min2 = (d, h);

		double s = sqrt(min1 * min1 + min2 * min2);

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int r;
			cin >> r;
			if (s < 2*r) cout << "OK\n";
			else cout << "NA\n";
		}
	}
	return 0;
}
