#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const double EPS = 1e-12;
typedef long long int64;

template<typename T>
T abs(T x){
	return x > 0 ? x : -x;
}

vector<double> solveLinearEquations(const vector<vector<double> >& A, const vector<double>& b) {
	const int n = A.size();
	vector< vector<double> > B(n, vector<double>(n + 1, 0.0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			B[i][j] = A[i][j];
		}
		B[i][n] = b[i];
	}
	for (int i = 0; i < n; ++i) {
		int pivot = i;
		for (int j = i; j < n; ++j) {
			if (abs(B[j][i]) > abs(B[pivot][i])) {
				pivot = j;
			}
		}
		B[i].swap(B[pivot]);
		if (abs(B[i][i]) < EPS) {
			return vector<double>();
		}

		for (int j = i + 1; j <= n; ++j) {
			B[i][j] /= B[i][i];
		}
		for (int j = 0; j < n; ++j) if (i!=j) {
			for (int k = i + 1; k <= n; ++k) {
				B[j][k] -= B[j][i] * B[i][k];
			}
		}
	}
	vector<double> x(n);
	for (int i = 0; i < n; ++i) {
		x[i] = B[i][n];
	}
	return x;
}

int A, B, N, M;

bool init() {
	scanf("%d%d%d%d", &A, &N, &B, &M);
	return A > 0;
}

const int MAX_COMB = 30;
int64 comb[MAX_COMB + 1][MAX_COMB + 1];

void buildCombination() {
	for (int n = 0; n <= MAX_COMB; ++n) {
		comb[n][0] = comb[n][n] = 1;
		for (int k = 1; k < n; ++k) {
			comb[n][k] = (comb[n-1][k-1] + comb[n-1][k]);
		}
	}
}

int64 calcPow(int64 x, int64 n) {
	int64 ret = 1;
	for (; n; n >>= 1, x = x * x) if (n&1) {
		ret = ret * x;
	}
	return ret;
}


inline int toIndex(int n, int m) {
	return n * M + m + 1;
}

void solve() {
	vector< vector<double> > mat(N*M + 1, vector<double>(N*M + 1, 0.0));
	vector<double> b(N*M + 1, 0.0);
	mat[0][0] = 1.0; b[0] = 1.0;
	for (int d = 0; d <= N*M; ++d) {
		for (int k = 0; k <= d; ++k) {
			int64 a = comb[d][k];
			a *= calcPow(A, k/N) * calcPow(B, (d-k)/M);
			mat[toIndex(k%N, (d-k)%M)][d < N*M ? d + 1 : 0] += a;
		}
	}

	vector<double> x = solveLinearEquations(mat, b);

	reverse(x.begin() + 1, x.end());
	for (int i = 0; i <= N*M; ++i) {
		printf("%d%c", int(round(x[i])), i == N*M ? '\n': ' ');
	}
}

int main() {
	buildCombination();
	for (;init();) {
		solve();
	}
	return 0;
}