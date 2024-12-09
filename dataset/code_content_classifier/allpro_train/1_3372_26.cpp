#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int ND[] = {31,29,31,30,31,30,31,31,30,31,30,31};
int f(int n, vector<bool> m) {
	int r = 0;
	switch (n) {
	case 0:return m[0] + m[1] + m[2] + m[4] + m[5] + m[6];
	case 1:return m[2] + m[5];
	case 2:return m[0] + m[2] + m[3] + m[4] + m[6];
	case 3:return m[0] + m[2] + m[3] + m[5] + m[6];
	case 4:return m[1] + m[2] + m[3] + m[5];
	case 5:return m[0] + m[1] + m[3] + m[5] + m[6];
	case 6:return m[0] + m[1] + m[3] + m[4] + m[5] + m[6];
	case 7:return m[0] + m[2] + m[5];
	case 8:return m[0] + m[1] + m[2] + m[3] + m[4] + m[5] + m[6];
	case 9:return m[0] + m[1] + m[2] + m[3] + m[5] + m[6];
	default: throw 1;
	}
	return r;
}
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<bool>> PQ(14, vector<bool>(7, true));
	for (int i = 0; i < K; ++i) {
		int p, q;
		cin >> p >> q;
		PQ[p][q] = false;
	}
	map<int, int> yy;
	map<int, int> y229;
	for (int y = 0; y < 10000; ++y) {
		int n = f(y / 1000, PQ[0]) + f(y / 100 % 10, PQ[1]) + f(y / 10 % 10, PQ[2]) + f(y % 10, PQ[3]);
		++yy[n];
		if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
			++y229[n];
		}
	}
	map<int, int> ymd;
	for (int m = 1; m <= 12; ++m) {
		int nd = ND[m-1];
		for (int d = 1; d <= nd; ++d) {
			int n = f(m / 10, PQ[4]) + f(m % 10, PQ[5]) + f(d / 10, PQ[6]) + f(d % 10, PQ[7]);
			if (m == 2 && d == 29) {
				for (auto p : y229) {
					ymd[p.first + n] += p.second;
				}
			} else {
				for (auto p : yy) {
					ymd[p.first + n] += p.second;
				}
			}
		}
	}
	map<int, int> hms;
	for (int h = 0; h < 24; ++h) for (int m = 0; m < 60; ++m) for (int s = 0; s < 60; ++s) {
		++hms[f(h / 10, PQ[8]) + f(h % 10, PQ[9]) + f(m / 10, PQ[10]) + f(m % 10, PQ[11]) +
			f(s / 10, PQ[12]) + f(s % 10, PQ[13])];
	}
	long long r = 0;
	for (auto p : ymd) {
		int m = N - p.first;
		if (hms.count(m)) {
			r += (long long)p.second * hms[m];
		}
	}
	cout << r << endl;
}
