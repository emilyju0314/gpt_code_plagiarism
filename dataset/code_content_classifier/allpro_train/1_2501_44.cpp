#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define pow2(x) ((x)*(x))

int main() {
	double x0, y0, x1, y1, X0, Y0, X1, Y1;
	double a1, b1, a2, b2, a3, b3;
	int n;
	cin >> n;
	while(n--) {
		cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
		x0 = (a1 + a2) / 2.0; y0 = (b1 + b2) / 2.0;
		x1 = -(b2 - b1); y1 = (a2 - a1);
		X0 = (a2 + a3) / 2.0; Y0 = (b2 + b3) / 2.0;
		X1 = -(b3 - b2); Y1 = (a3 - a2);
		double s = (Y1*(x0 - X0) - X1*(y0 - Y0)) / (X1*y1 - Y1*x1);
		double p = x0 + s * x1, q = y0 + s * y1;
		double r = sqrt(pow2(p - a1) + pow2(q - b1));
		printf("%.3f %.3f %.3f\n", p, q, r);
	}
	return 0;
}