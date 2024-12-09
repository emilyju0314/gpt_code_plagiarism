#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

class Solver {
};
int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0)break;

		vector<int> cnts(26, 0);
		bool done = false;
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			if (done)continue;

			cnts[c - 'A']++;
			vector<tuple<int, char>> cntTmp;
			for (int j = 0; j < 26; j++) {
				cntTmp.emplace_back(make_tuple(cnts[j], (char)('A' + j)));
			}
			int remain = n - i - 1;
			sort(cntTmp.begin(), cntTmp.end(), greater<tuple<int, int>>());
			if (get<0>(cntTmp[0]) > get<0>(cntTmp[1]) + remain) {
				done = true;
				cout << get<1>(cntTmp[0]) << ' ' << i + 1 << endl;
			}
		}
		if (!done)cout << "TIE"<<endl;
	}
}
