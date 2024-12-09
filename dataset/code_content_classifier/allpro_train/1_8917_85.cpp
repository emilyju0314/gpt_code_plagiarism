#include <iostream>
using namespace std;
int n, x[100], y[100]; long long ret;
int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= n; i++) ret += x[i % n] * y[(i + 1) % n] - x[(i + 1) % n] * y[i % n];
	cout << ret / 2 << (ret % 2 ? ".5" : ".0") << endl;
}