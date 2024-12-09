#include <bits/stdc++.h>
using namespace std;
int main() {
	while(1) {
		int n, m;
		cin >> n >> m;
		if((n == 0)&&(m == 0)) {
			break;
		} else {
			vector<long long int> arr_max(n, 0);
			vector<long long int> arr_min(n, 0);
			for(int i = 0; i < m; i++) {
				int s, k, c;
				cin >> s >> k;
				for(int j = 0; j < k; j++) {
					cin >> c;
					c--;
					arr_max[c] += s;
					if(k == 1) arr_min[c] += s;
				}
			}
			long long int ans = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if(i != j) {
						if(ans < arr_max[i] - arr_min[j]) ans = arr_max[i] - arr_min[j];
					}
				}
			}
			cout << ans + 1 << endl;
		}
	}

	return 0;
}