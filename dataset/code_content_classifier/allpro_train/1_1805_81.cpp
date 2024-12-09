#include <bits/stdc++.h>

using namespace std;

const int CountOfMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int calculationDaysOfYear(int y, int m, int d) {
	int cnt = 0;

	for (int i = 1; i < m; i++) {
		cnt += CountOfMonth[i];
	}
	cnt += d;
	if (m > 2) {
		if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
			cnt++;
		}
	}
	
	return cnt;
}

int main() {
	int y1, m1, d1, y2, m2, d2,cntDays;
	int countDaysOfYear[2];

	while (cin >> y1 >> m1 >> d1 >> y2>> m2 >> d2, y1 > 0) {
		countDaysOfYear[0] = calculationDaysOfYear(y1, m1, d1);
		countDaysOfYear[1] = calculationDaysOfYear(y2, m2, d2);
		cntDays = countDaysOfYear[1] - countDaysOfYear[0];
		//cout << countDaysOfYear[0] << endl << countDaysOfYear[1] << endl;
		
		for (int i = y1; i < y2; i++) {
			cntDays += 365;
			if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
				cntDays++;
			}
		}
		cout << cntDays << endl;
	}

	return 0;
}
