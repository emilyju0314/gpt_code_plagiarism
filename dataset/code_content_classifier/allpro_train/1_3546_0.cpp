#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
const double lim = 0.0001;
int n; double p[309], sq[309], a[309];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i], sq[i] = sqrt(p[i]), a[i] = 0.03 / n;
	double ret = 1.0e+9; int cnt = 0;
	while (true) {
		double curval = 0.0;
		for (int i = 0; i < n; i++) curval += p[i] / a[i];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				double sa = a[i] + a[j], sp = sq[i] + sq[j];
				a[i] = sq[i] / sp * sa;
				a[j] = sq[j] / sp * sa;
				if (a[i] < lim) a[j] -= lim - a[i], a[i] = lim;
				if (a[j] < lim) a[i] -= lim - a[j], a[j] = lim;
			}
		}
		ret = 0.0;
		for (int i = 0; i < n; i++) ret += p[i] / a[i];
		if (abs(curval - ret) < 1.0e-8) break;
		cnt++;
	}
	cout << fixed << setprecision(15) << 300 * ret << endl;
	return 0;
}
