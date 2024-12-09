#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	while (1) {
		int N; cin >> N;
		if (!N)break;
		const int ro = 16 * 9 * 5 * 7*11;
		vector<vector<int>>specials(4);
		specials[0].resize(13);
		specials[1].resize(17);
		specials[2].resize(19);
		specials[3].resize(23);
		vector<vector<int>>access;
		for (int i = 0; i < N; ++i) {
			int d, t; cin >> d >> t;
			vector<int>v(d);
			for (int j = 0; j < d; ++j) {
				cin >> v[(j + d - t) % d];
			}
			vector<int>av;
			if (ro%d) {
				const int num = *max_element(v.begin(), v.end());
				for (int j = 0; j < d; ++j) {
					 int p;
					if (d == 13) {
						p = 0;
					}
					else if (d == 17) {
						p = 1;

					}
					else if (d == 19) {

						p = 2;
					}
					else if (d == 23) {
						p = 3;

					}
					specials[p][j] += v[j];
				}
			}
			else {
				for (int j = 0; j < ro / d; ++j) {
					av.insert(av.end(), v.begin(), v.end());
				}
			}
			access.push_back(av);
		}
		int ans = 0;
		for (int i = 0; i < ro; ++i) {
			int sum = 0;
			for (int j = 0; j < N; ++j) {
				if (!access[j].empty()) {
					sum += access[j][i];
				}
			}
			ans = max(ans, sum);
		}
		for (int i = 0; i < 4; ++i) {
			ans += *max_element(specials[i].begin(), specials[i].end());
		}
		cout << ans << endl;
	}
	return 0;
}