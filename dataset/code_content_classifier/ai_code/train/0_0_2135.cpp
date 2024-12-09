#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Flight {
    int day;
    int departure_city;
    int arrival_city;
    int cost;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Flight> flights(m);
    for (int i = 0; i < m; i++) {
        cin >> flights[i].day >> flights[i].departure_city >> flights[i].arrival_city >> flights[i].cost;
    }

    sort(flights.begin(), flights.end(), [](Flight a, Flight b) {
        return a.day < b.day;
    });

    vector<int> jury_count(n + 1, 0);
    int total_cost = 0;
    int min_cost = 1e9;
    int left = 1, right = 1;
    for (; right < m; right++) {
        jury_count[flights[right].departure_city]++;
        if (jury_count[flights[right].departure_city] == 1) {
            total_cost += flights[right].cost;
        }

        while (flights[right].day - flights[left].day >= k) {
            jury_count[flights[left].departure_city]--;
            if (jury_count[flights[left].departure_city] == 0) {
                total_cost -= flights[left].cost;
			}
			left++;
		}

		bool all_present = true;
		for (int i = 1; i <= n; i++) {
			if (jury_count[i] == 0) {
				all_present = false;
				break;
			}
		}

		if (all_present) {
			min_cost = min(min_cost, total_cost);
		}
	}

	if (min_cost == 1e9) {
		cout << -1 << endl;
	} else {
		cout << min_cost << endl;
	}

	return 0;
}