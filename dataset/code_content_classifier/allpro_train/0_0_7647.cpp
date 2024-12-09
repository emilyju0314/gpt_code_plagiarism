#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    vector<pair<pair<int, int>, int>> marriages; // (man, woman, delight)
    for (int i = 0; i < k; i++) {
        int h, w, r;
        cin >> h >> w >> r;
        marriages.push_back({{h, w}, r});
    }

    vector<int> subsets;
    for (int mask = 0; mask < (1 << k); mask++) {
        int total_delight = 0;
        vector<bool> used(n + 1, false);
        
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                int man = marriages[i].first.first;
                int woman = marriages[i].first.second;
                
                if (!used[man] && !used[woman]) {
                    total_delight += marriages[i].second;
                    used[man] = true;
                    used[woman] = true;
                }
            }
        }
        subsets.push_back(total_delight);
    }

    sort(subsets.begin(), subsets.end());

    cout << subsets[t - 1] << endl;

    return 0;
}