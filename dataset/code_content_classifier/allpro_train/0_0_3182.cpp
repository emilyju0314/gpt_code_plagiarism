#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> segments(N);
    for (int i = 0; i < N; i++) {
        cin >> segments[i].first >> segments[i].second;
    }
    
    sort(segments.begin(), segments.end());
    
    long long totalDistance = 0;
    for (int i = 0; i < N; i++) {
        if (segments[i].first >= 0) {
            totalDistance += segments[i].first;
        } else if (segments[i].second <= 0) {
            totalDistance += -segments[i].second;
        } else {
            totalDistance += segments[i].first;
            totalDistance += -segments[i].second;
        }
    }
    
    cout << totalDistance * 2 << endl;
    
    return 0;
}