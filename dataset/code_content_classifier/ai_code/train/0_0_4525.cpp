#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int start, end, index;
};

bool compareSegments(const Segment& s1, const Segment& s2) {
    return s1.start < s2.start;
}

int main() {
    int n;
    cin >> n;
    
    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].start >> segments[i].end;
        segments[i].index = i;
    }
    
    sort(segments.begin(), segments.end(), compareSegments);
    
    vector<pair<int, int>> result(n);
    
    int maxSum = 0, prevEnd = -1;
    for (int i = 0; i < n; i++) {
        result[segments[i].index].first = max(prevEnd+1, segments[i].start);
        result[segments[i].index].second = segments[i].start + segments[i].end - 1;
        
        maxSum += result[segments[i].index].second - result[segments[i].index].first;
        
        prevEnd = max(prevEnd, result[segments[i].index].second);
    }
    
    cout << maxSum << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }
    
    return 0;
}