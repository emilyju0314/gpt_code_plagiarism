#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <utility>

using namespace std;

int main(){
	int N, T; cin >> N >> T;
	int tmp_ar_time_h = -1, tmp_ar_time_m = -1;

	vector<pair<string, int> > ans;

	for (int i = 0; i < N; i++) {
		int st_time_h, st_time_m;
		int ar_time_h, ar_time_m;
		string st_name, ar_name;
		scanf("%d:%d", &st_time_h, &st_time_m);
		cin >> st_name;
		scanf("%d:%d", &ar_time_h, &ar_time_m);
		cin >> ar_name;

		// cout << st_time << st_name << ar_time << ar_name << endl;

		if (tmp_ar_time_h == -1 || tmp_ar_time_m == -1) {
			tmp_ar_time_h = ar_time_h;
			tmp_ar_time_m = ar_time_m;
			continue;
		}

		int dh = st_time_h - tmp_ar_time_h;
		int dm = st_time_m - tmp_ar_time_m;

		int d = 60*dh + dm;

		if (d >= T) {
			ans.push_back(make_pair(st_name, d));
		}

		tmp_ar_time_h = ar_time_h;
		tmp_ar_time_m = ar_time_m;
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}