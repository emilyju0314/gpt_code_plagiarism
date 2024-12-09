#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double x[1001], y[1001];
	double dm, du, dc, d3, tmp;

	dm = 0.0; du = 0.0; dc = 0.0; d3 = 0.0;
	cin >> n;
	
	for(int i=0; i<n; i++) cin >> x[i];
	for(int i=0; i<n; i++) cin >> y[i];

	for(int i=0; i<n; i++) {
		tmp = abs(x[i] - y[i]);
		if(dc < tmp) dc = tmp;
		dm += tmp;
		du += pow(tmp, 2);
		d3 += pow(tmp, 3);
	}

	cout << fixed << setprecision(8);
	cout << dm << endl;
	cout << sqrt(du) << endl;
	cout << pow(d3, 1.0/3.0) << endl;
	cout << dc << endl;

	return 0;
}