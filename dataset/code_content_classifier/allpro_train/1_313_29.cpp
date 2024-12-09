#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	map<int, int> P;
	for (int i = 0; i < N; i++) {
		for (int j = 2; j * j <= A[i]; j++) {
			if (A[i] % j == 0) {
				P[j]++;
				while (A[i] % j == 0) {
					A[i] /= j;
				}
			}
		}
		if (A[i] != 1) P[A[i]]++;
	}
	int MAX = 0;
	for (auto it = P.begin(); it != P.end(); it++) {
		MAX = max(MAX, it->second);
	}
	if (MAX <= 1) cout << "pairwise coprime" << endl;
	else if (MAX == N) cout << "not coprime" << endl;
	else cout << "setwise coprime" << endl;
}