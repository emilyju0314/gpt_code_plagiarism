#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

int main() {
	int n, q;
	vector<int64_t> a;
	int64_t sum_t = 0;
	int64_t sum_a = 0;
	int64_t allsum = 0;
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		int64_t ai;
		cin >> ai;
		a.push_back(ai);
		if (i % 2 == n%2) sum_a += ai;
		else sum_t += ai;
		allsum += ai;
	}
	vector<int64_t> thr;
	vector<int64_t> val;
	for (int i = 1; i < n; ++i) {
		int ind1 = n - 1 - i;
		int ind2 = n - 1 - 2 * i;
		if (ind2 >= 0) {
			int64_t t = (a[ind1] + a[ind2]) / 2;
			thr.push_back(t);
			val.push_back(sum_a);
			sum_a = sum_a - a[ind1] + a[ind2];
		}
		else {
			ind2 = 0;
			int64_t t = (a[ind1] + a[ind2]) / 2;
			thr.push_back(0);
			val.push_back(sum_a);
		}
	}
	reverse(thr.begin(), thr.end());
	reverse(val.begin(), val.end());
	for (int i = 0; i < q; ++i) {
		int64_t xi;
		cin >> xi;
		auto ite = lower_bound(thr.begin(), thr.end(),xi);
		int dis = distance(thr.begin(), ite)-1;
		if (dis <= 0) dis = 0;
		cout << allsum-val[dis] << endl;
	}
	return 0;
}