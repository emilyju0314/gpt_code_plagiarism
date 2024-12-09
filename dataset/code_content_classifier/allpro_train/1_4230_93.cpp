#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	double x1, y1, x2, y2, x3, y3;
	char c;
	double veku[2];
	while (cin >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> x3 >> c >> y3) {
		veku[0] = x2 - x1;
		veku[1] = y2 - y1;
		if (fabs(veku[0]) <= 0.0001) {
			printf("%.6f %.6f\n", -x3, y3);
		} else {
			double kaku = -atan(veku[1]/veku[0]);
			double x4, y4, x5, y5;
			double b = y2 - (veku[1]/veku[0])*x2;
			x4 = cos(kaku)*x3-sin(kaku)*(y3-b);
			y4 = sin(kaku)*x3+cos(kaku)*(y3-b);
			y4 = -y4;
			x5 = cos(-kaku)*x4-sin(-kaku)*y4;
			y5 = sin(-kaku)*x4+cos(-kaku)*y4;
			printf("%.6f %.6f\n", x5, y5+b);
		}
	}
	return 0;
}