#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cloud {
    int start;
    int end;
    int cost;
};

int main() {
    int n, C;
    cin >> n >> C;

    vector<Cloud> clouds(n);
    for (int i = 0; i < n; i++) {
        cin >> clouds[i].start >> clouds[i].end >> clouds[i].cost;
    }

    sort(clouds.begin(), clouds.end(), [](const Cloud& c1, const Cloud& c2) {
        return c1.end < c2.end;
    });

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        int min_time = k;
        for (int j = 0; j < n; j++) {
            if (clouds[j].end < min_time) continue;

            int remaining_candies = C;
            int total_sunny_time = 0;
            for (int p = 0; p <= j; p++) {
                if (clouds[p].start < min_time) {
                    int sunny_time = min(min_time, clouds[p].end) - clouds[p].start;
                    total_sunny_time += sunny_time;
                }
            }

            if (total_sunny_time < k) {
                for (int p = 0; p <= j; p++) {
                    int sunny_time = min(min_time, clouds[p].end) - max(min_time, clouds[p].start);
                    if (sunny_time > 0) {
                        int candies_needed = min(2, remaining_candies) * clouds[p].cost;
                        remaining_candies -= candies_needed;
                        min_time += sunny_time;
                    }
                }
            } else {
                break;
            }
        }

        cout << min_time << endl;
    }

    return 0;
}