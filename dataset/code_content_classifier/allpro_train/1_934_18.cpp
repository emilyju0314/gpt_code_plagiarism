#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long long subsolve(int N, long long C, vector<long long> X, vector<long long> V) {
	vector<long long> VS(N + 1);
	for (int i = N - 1; i >= 0; --i) {
		VS[i] = VS[i + 1] + V[i];
	}
	long long ans = 0, opt = 0, TS = 0;
	for (int i = 0; i < N; ++i) {
		ans = max(ans, opt - (C - X[i]) * 2 + VS[i]);
		TS += V[i];
		opt = max(opt, TS - X[i]);
	}
	ans = max(ans, opt);
	return ans;
}
int main() {
	int N; long long C;
	cin >> N >> C;
	vector<long long> X(N), V(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> V[i];
	}
	long long ans1 = subsolve(N, C, X, V);
	for (int i = 0; i < N; ++i) X[i] = C - X[i];
	reverse(X.begin(), X.end());
	reverse(V.begin(), V.end());
	long long ans2 = subsolve(N, C, X, V);
	cout << max(ans1, ans2) << endl;
	return 0;
}