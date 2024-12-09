#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int x, s;
    cin >> x >> s;

    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> c(k), d(k);
    for(int i = 0; i < k; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < k; i++) {
        cin >> d[i];
    }

    int min_time = n * x;

    for(int i = 0; i < m; i++) {
        if(b[i] <= s) {
            int remaining_manapoints = s - b[i];
            int remaining_potions = n;
            int current_time;

            auto it = upper_bound(d.begin(), d.end(), remaining_manapoints);
			if(it != d.begin()){
				--it;
				int index = it - d.begin();
				current_time = remaining_potions * c[index];
				min_time = min(min_time, current_time);
			}
        }
    }

    auto it = upper_bound(d.begin(), d.end(), s);
	if(it != d.begin()){
		--it;
		int index = it - d.begin();
		min_time = min(min_time, n * c[index]);
	}

    cout << min_time << endl;

    return 0;
}