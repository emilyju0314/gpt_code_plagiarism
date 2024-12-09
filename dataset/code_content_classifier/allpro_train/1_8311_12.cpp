#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

long double deg(long double px, long double py) {
	long double T = px / sqrtl(px * px + py * py);
	long double E = acos(T) * 180.0L / 3.14159265358979L;
	if (py >= 0) return E;
	return 360.0L - E;
}

int N, x[1009], y[1009];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

	bool ok = false;

	for (int i = 0; i < N - 1; i++) {
		// ---------------------------- 辺の最初で判定 ----------------------------
		long double maxa = 0, maxb = 0, maxc = 0, maxd = 0;
		for (int j = 0; j < i; j++) {
			long double D1 = deg(x[i] - x[i + 1], y[i] - y[i + 1]);
			long double D2 = deg(x[j] - x[i], y[j] - y[i]);

			long double SA = D1 - D2; if (SA < -180.0L) SA += 360.0L; else if (SA > 180.0L) SA -= 360.0L;
			if (SA < 0.0L) maxa = max(maxa, -SA);
			else maxb = max(maxb, SA);
		}
		for (int j = i + 1; j < N; j++) {
			long double D1 = deg(x[i + 1] - x[i], y[i + 1] - y[i]);
			long double D2 = deg(x[j] - x[i], y[j] - y[i]);

			long double SA = D1 - D2; if (SA < -180.0L) SA += 360.0L; else if (SA > 180.0L) SA -= 360.0L;
			if (SA < 0.0L) maxc = max(maxc, -SA);
			else maxd = max(maxd, SA);
		}
		if (maxa + maxb > 180.0L || maxb + maxc > 180.0L || maxc + maxd > 180.0L || maxd + maxa > 180.0L) {
			ok = true;
		}

		// -------------------------- 辺の最後で判定 -----------------------------
		maxa = 0; maxb = 0; maxc = 0;
		for (int j = 0; j <= i; j++) {
			long double D1 = deg(x[i] - x[i + 1], y[i] - y[i + 1]);
			long double D2 = deg(x[j] - x[i + 1], y[j] - y[i + 1]);

			long double SA = D1 - D2; if (SA < -180.0L) SA += 360.0L; else if (SA > 180.0L) SA -= 360.0L;
			if (SA < 0.0L) maxa = max(maxa, -SA);
			else maxb = max(maxb, SA);
		}
		for (int j = i + 2; j < N; j++) {
			long double D1 = deg(x[i + 1] - x[i], y[i + 1] - y[i]);
			long double D2 = deg(x[j] - x[i + 1], y[j] - y[i + 1]);

			long double SA = D1 - D2; if (SA < -180.0L) SA += 360.0L; else if (SA > 180.0L) SA -= 360.0L;
			if (SA < 0.0L) maxc = max(maxc, -SA);
			else maxd = max(maxd, SA);
		}
		if (maxa + maxb > 180.0L || maxb + maxc > 180.0L || maxc + maxd > 180.0L || maxd + maxa > 180.0L) {
			ok = true;
		}
	}
	if (ok == true) cout << "Impossible" << endl;
	else cout << "Possible" << endl;
	return 0;
}
