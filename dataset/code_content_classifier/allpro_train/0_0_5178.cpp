#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> intervals;
    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        intervals.emplace_back(R, L); // Store the intervals as (right endpoint, left endpoint) pair
    }
    
    sort(intervals.begin(), intervals.end()); // Sort intervals based on right endpoint
    
    int total_cost = 0;
    int prev_end = 0;
    
    for (auto& interval : intervals) {
        int L = interval.second;
        int R = interval.first;
        
        if (L <= prev_end) { // If there is an overlap, move the interval to make it disjoint
            total_cost += prev_end - L;
            prev_end = prev_end; // Move the interval to the right to make it disjoint
        } else {
            prev_end = L; // No overlap, update the prev_end to the left endpoint of the interval
        }
    }
    
    cout << total_cost << endl;
    
    return 0;
}