#include<iostream>
#include<cfloat>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	float* p = new float[n];
	float* q = new float[n + 1];
	float sum, mini;
	for (int i = 0;i < n;i++) {
		cin >> p[i];
	}
	for (int i = 0;i <= n;i++) {
		cin >> q[i];
	}
	float** cost = new float* [n];
	float** coefficient = new float* [n];
	for (int i = 0;i < n;i++) {
		cost[i] = new float[n - i];
		coefficient[i] = new float[n - i];
	}
	for (int i = 0;i < n ;i++) {
		for (int j = 0;j < n - i;j++) {
			sum = 0;
			for (int k = i;k <= i + j;k++) {
				sum += p[k] + q[k];
			}
			sum += q[i + j + 1];
			coefficient[i][j] = sum;
		}
		cost[i][0] = p[i]+2*q[i]+2*q[i+1];
	}
	for (int j = 1;j <n;j++) {
		for (int i = 0;i < n - j;i++) {
			mini = p[i] + cost[i + 1][j - 1] + coefficient[i + 1][j - 1]+2*q[i];
			for (int k = 1;k < j;k++) {
				mini = min(mini, p[i + k] + cost[i][k - 1] + coefficient[i][k - 1] + cost[i + k + 1][j - k - 1] + coefficient[i + k + 1][j - k - 1]);
			}
			cost[i][j] = min(mini, p[i + j] + cost[i][j - 1] + coefficient[i][j - 1] + 2 * q[i + j + 1]);
		}
	}
	cout << cost[0][n-1] << endl;
}
