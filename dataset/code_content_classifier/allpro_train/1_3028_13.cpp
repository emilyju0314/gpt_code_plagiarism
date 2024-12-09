#include <algorithm>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int N;
	double W, ans = 0.0;
	cin >> N >> W;
	vector<pair<double, double>> vw(N);
	for (pair<double, double>& i : vw) cin >> i.first >> i.second;
	sort(vw.begin(), vw.end(), [](pair<double, double>& a, pair<double, double>& b) { return a.first / a.second > b.first / b.second; });
	for (pair<double, double>& i : vw) {
		if (W < i.second) {
			ans += W / i.second * i.first;
			break;
		}
		else {
			W -= i.second;
			ans += i.first;
		}
	}
	printf("%.6f\n", ans);
}
