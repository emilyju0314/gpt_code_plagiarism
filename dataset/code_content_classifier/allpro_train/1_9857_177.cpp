#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int A[20000];
int B[4] = { 2,3,4,6 };
int main() {
	int N;
	cin >> N;
	if (N == 3) {
		cout << "2 5 63" << endl;
		return 0;
	}
	else if (N == 4) {
		cout << "2 5 20 63" << endl;
		return 0;
	}
	else if (N == 5) {
		cout << "2 5 20 30 63" << endl;
		return 0;
	}
	int p = 0, q = 0;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		A[i] = 6 * p + B[q];
		(sum += A[i]) %= 6;
		if (q == 3) p++, q = 0;
		else q++;
	}
	if (sum == 2) {
		A[4] = 6 * (p + 1);
	}
	else if (sum == 3) {
		A[5] = 6 * (p + 1);
	}
	else if (sum == 5) {
		A[5] = 6 * p + 4;
	}
	cout << A[0];
	for (int i = 1; i < N; i++) {
		cout << " " << A[i];
	}
	cout << endl;
}