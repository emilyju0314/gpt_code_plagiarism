#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    sort(intervals.begin(), intervals.end());
    
    vector<int> candidates;
    for (int i = 0; i < n; i++) {
        bool valid = true;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (!(intervals[i].second <= intervals[j].first || intervals[j].second <= intervals[i].first)) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            candidates.push_back(i+1);
        }
    }
    
    cout << candidates.size() << endl;
    for (int i = 0; i < candidates.size(); i++) {
        cout << candidates[i] << " ";
    }
    
    return 0;
}