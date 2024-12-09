#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, p;
    cin >> n >> m >> k >> p;

    vector<pair<int, int>> bamboos;
    int max_initial_height = 0;

    for(int i = 0; i < n; i++) {
        int h, a;
        cin >> h >> a;
        bamboos.push_back(make_pair(h, a));
        max_initial_height = max(max_initial_height, h);
    }

    int left = 0, right = max_initial_height + m * k * p;
    while(left < right) {
        int mid = (left + right) / 2;
        vector<long long> heights;

        for(int i = 0; i < n; i++) {
            long long current_height = bamboos[i].first;
            long long growth_rate = bamboos[i].second;

            for(int j = 0; j < m; j++) {
                if(current_height > mid) break;
                heights.push_back(current_height);
                current_height += growth_rate;
            }
        }

        if(heights.size() < m * n) {
            left = mid + 1;
        } else {
            sort(heights.begin(), heights.end());

            long long total = 0;
            int index = 0;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < k && index < heights.size(); j++) {
                    total += heights[index];
                    index++;
                }
            }

            if(total <= (long long)m * mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
    }

    cout << left << endl;

    return 0;
}