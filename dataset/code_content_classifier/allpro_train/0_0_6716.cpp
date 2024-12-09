#include <iostream>
#include <vector>

using namespace std;

int main() {
    int L, n, p, t;
    cin >> L >> n >> p >> t;

    vector<pair<int, int>> segments;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        segments.push_back({l, r});
    }

    int maxPerformances = 0;
    int lastPerformanceEnd = 0;
    for (int i = 0; i < n; i++) {
        int lightedSegmentStart = segments[i].first;
        int lightedSegmentEnd = segments[i].second;
        
        int availableDistance = lightedSegmentStart - lastPerformanceEnd;
        int performancesInSegment = (availableDistance - t) / (p + t) + 1;
        
        maxPerformances += performancesInSegment;
        
        lastPerformanceEnd = lightedSegmentEnd;
    }
    
    int remainingDistance = L - lastPerformanceEnd;
    int performancesInRemaining = (remainingDistance - t) / (p + t) + 1;
    
    maxPerformances += performancesInRemaining;
    
    cout << maxPerformances << endl;

    return 0;
}