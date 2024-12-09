#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> segments(m);
    for (int i = 0; i < m; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int max_diff = 0, num_segments = 0;
    unordered_set<int> chosen_segments;

    for (int i = 0; i < (1 << m); i++) {
        vector<int> b = a;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                for (int k = segments[j].first - 1; k < segments[j].second; k++) {
                    b[k]--;
                }
            }
        }

        int max_val = *max_element(b.begin(), b.end());
        int min_val = *min_element(b.begin(), b.end());
        int diff = max_val - min_val;
        if (diff > max_diff) {
            max_diff = diff;
            num_segments = __builtin_popcount(i);
            chosen_segments.clear();

            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    chosen_segments.insert(j + 1);
                }
            }
        }
    }

    cout << max_diff << endl;
    cout << num_segments << endl;
    for (int segment : chosen_segments) {
        cout << segment << " ";
    }
    
    return 0;
}