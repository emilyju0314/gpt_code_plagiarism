#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)




//-----------------------------------------------------------------------------------
int N;
double A[101010];
map<double, vector<int>> m;
int ans[101010];
//-----------------------------------------------------------------------------------
int main() {
	cin >> N;
	rep(i, 0, N) scanf("%f", &A[i]);
	rep(i, 0, N) m[A[i]].push_back(i);
	sort(A, A + N);

	for (auto p : m) {
		double i = p.first;
		auto v = p.second;

		int lose = A + N - upper_bound(A, A + N, i);
		int even = v.size() - 1;
		int win = N - 1 - lose - even;

		int score = win * 3 + even;
		for (int j : v) ans[j] = score;
	}

	rep(i, 0, N) printf("%d\n", ans[i]);
}