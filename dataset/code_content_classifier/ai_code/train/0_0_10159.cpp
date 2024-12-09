#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heights(n);
        
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        vector<pair<int, int>> photogenic_pairs;
        
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if ((heights[i] + heights[j]) % 2 == 0) {
                    photogenic_pairs.push_back({(heights[i] + heights[j]) / 2, i});
                }
            }
        }

        sort(photogenic_pairs.begin(), photogenic_pairs.end(), compare);

        vector<int> result(n);
        result[0] = photogenic_pairs[0].first;
        result[n-1] = heights[photogenic_pairs[0].second];
        
        int idx = 1;
        for (int i = 0; i < n; i++) {
            if (i == photogenic_pairs[0].second || heights[i] == photogenic_pairs[0].first) {
                continue;
            }
            result[idx] = heights[i];
            idx++;
        }

        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}