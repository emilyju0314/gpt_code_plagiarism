#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> segments(m); // store the indices of the segments
    for(int i = 0; i < m; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int max_diff = 0;
    vector<int> chosen_segments;
    
    // Try all possible subsets of segments
    for(int mask = 0; mask < (1 << m); mask++) {
        vector<int> b = a;

        // Apply the chosen segments to the array
        for(int i = 0; i < m; i++) {
            if(mask & (1 << i)) {
                for(int j = segments[i].first - 1; j < segments[i].second; j++) {
                    b[j]--;
                }
            }
        }

        int max_val = *max_element(b.begin(), b.end());
        int min_val = *min_element(b.begin(), b.end());
        int diff = max_val - min_val;

        if(diff > max_diff) {
            max_diff = diff;
            chosen_segments.clear();
            for(int i = 0; i < m; i++) {
                if(mask & (1 << i)) {
                    chosen_segments.push_back(i + 1);
                }
            }
        }
    }

    cout << max_diff << "\n";
    cout << chosen_segments.size() << "\n";
    for(int idx : chosen_segments) {
        cout << idx << " ";
    }

    return 0;
}