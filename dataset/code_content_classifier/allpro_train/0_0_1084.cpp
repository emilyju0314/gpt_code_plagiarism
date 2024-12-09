#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<pair<int, int>> bamboos;

    for (int i = 0; i < n; i++) {
        int h, a;
        cin >> h >> a;
        bamboos.push_back(make_pair(h, a));
    }

    sort(bamboos.begin(), bamboos.end());

    long long low = 0, high = 1e18;

    while (low < high) {
        long long mid = (low + high) / 2;
        vector<long long> days(n, 0);
        long long total_cuts = 0;

        for (int i = 0; i < n; i++) {
            long long total_bamboo_height = bamboos[i].first + bamboos[i].second * m;
            long long cuts = 0;

            for (int j = 0; j < m; j++) {
                long long h = bamboos[i].first + bamboos[i].second * j;

                if (h > mid) {
                    long long cuts_needed = (h - mid + p - 1) / p;

                    if (cuts_needed <= k) {
                        cuts += cuts_needed;
                        days[min(j + k + 1, m)] -= cuts_needed;
                    } else {
                        cuts = -1;
                        break;
                    }
                }
            }

            total_cuts += cuts;

            if (cuts != -1) {
                for (int j = 1; j < m; j++) {
                    days[j] += days[j - 1];
                }
            }
        }

        bool enough_cuts = true;

        for (int i = 0; i < n; i++) {
            if (days[m - 1] < total_cuts) {
                enough_cuts = false;
                break;
            }
        }

        if (!enough_cuts) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    cout << low << endl;

    return 0;
}