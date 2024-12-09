#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector <int> start(n);
		vector <int> nech(n - n / 2);
		vector <int> nech2(n - n / 2);
		vector <int> chet(n / 2);
		vector <int> chet2(n / 2);
		for (int j = 0; j < n; j++) {
			int k;
			cin >> k;
			start[j] = k;
			if (j % 2 == 0) {
				nech[j / 2] = k;
			}
			else {
				chet[(j - 1) / 2] = k;
			}
		}
		sort(start.begin(), start.end());
		sort(chet.begin(), chet.end());
		sort(nech.begin(), nech.end());
		for (int ss = 0; ss < n; ss++) {
			if (ss % 2 == 0) {
				nech2[ss / 2] = start[ss];
			}
			else {
				chet2[(ss - 1) / 2] = start[ss];
			}
		}
		if (nech == nech2 && chet == chet2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
	return 0;
}