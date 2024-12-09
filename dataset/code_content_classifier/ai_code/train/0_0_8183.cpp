#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int, int>> intervals;
    
    for(int i = 0; i < n; i++) {
        int lstart, lend;
        cin >> lstart >> lend;
        intervals.push_back(make_pair(lstart, lend));
    }
    
    sort(intervals.begin(), intervals.end());
    
    int cost = 0;
    
    for(auto interval : intervals) {
        if(x < interval.first) {
            cost += interval.first - x;
            x = interval.first;
        } else if(x > interval.second) {
            cost += x - interval.second;
            x = interval.second;
        }
    }
    
    cout << cost << endl;
    
    return 0;
}