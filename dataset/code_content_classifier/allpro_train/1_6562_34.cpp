#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, p[209], q[209];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i], q[i] = p[i];
	vector<int> v;
	int cyclic = 0;
	while (true) {
		bool flag = false;
		for (int i = 1; i < n; i++) {
			if (p[i - 1] > p[i]) {
				flag = true;
				int tp = i - cyclic;
				if (tp < 0) tp += n;
				for (int j = 0; j < tp; j++) v.push_back(1);
				cyclic = (cyclic + tp) % n;
				v.push_back(n - 1);
				swap(p[i], p[i - 1]);
			}
		}
		if (!flag) break;
	}
	while (cyclic % n != 0) cyclic++, v.push_back(1);
	cout << v.size() << endl;
	for (int i : v) {
		cout << i << endl;
		for (int j = i; j < n; j++) {
			swap(q[j - i], q[j]);
		}
	}
	return 0;
}