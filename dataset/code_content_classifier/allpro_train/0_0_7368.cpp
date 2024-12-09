#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    sort(intervals.begin(), intervals.end());
    
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        int maxCovered = 0;
        int rightmost = x;
        int j = 0;
        
        while (j < n && rightmost < y) {
            if (intervals[j].second >= rightmost) {
                maxCovered++;
                rightmost = intervals[j].second;
            }
            j++;
        }
        
        if (rightmost < y) {
            cout << "-1\n";
        } else {
            cout << maxCovered << endl;
        }
    }
    
    return 0;
}