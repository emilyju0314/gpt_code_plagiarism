#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define vvvel vector<vvel>
void mmin(int &a, int b) { a = min(a, b); }
void mmax(int &a, int b) { a = max(a, b); }
void sor(vel &v) { sort(v.begin(), v.end()); }
int zero() { return 0; }
signed main() {
	int n, k;
	cin >> n >> k;
	vel w(n); vel d(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> d[i];
	}
	int upp = w[0] + d[0] * k;
	int low = 0;
	while (upp - low > 1) {
		int mid = (upp + low) / 2;
		int ko = 0;
		for (int i = 0; i < n; i++) {
			ko += max((mid - w[i]+d[i]), zero()) / d[i];
		}
		if (ko < k) low = mid;
		else upp = mid;
	}
	cout << upp << endl;
	return 0;
}