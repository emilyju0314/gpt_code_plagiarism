#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> intervals;
    
    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        intervals.push_back(make_pair(L, R));
    }
    
    sort(intervals.begin(), intervals.end());
    
    int maxR = 0, additionalChairs = 0;
    
    for (int i = 0; i < N; i++) {
        if (maxR < intervals[i].first) {
            additionalChairs += intervals[i].first - maxR;
            maxR = intervals[i].first;
        }
        maxR = max(maxR, intervals[i].second);
    }
    
    if (maxR < M) {
        additionalChairs += M - maxR;
    }
    
    cout << additionalChairs << endl;
    
    return 0;
}