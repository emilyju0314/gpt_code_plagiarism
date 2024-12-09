#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    vector<int> distances(n);
    for(int i = 0; i < n; i++) {
        cin >> distances[i];
    }
    
    cin >> m;
    
    vector<int> visitedStops(m);
    for(int i = 0; i < m; i++) {
        cin >> visitedStops[i];
    }
    
    vector<int> uniqueVisitedStops;
    for(int i = 0; i < m; i++) {
        if(i == 0 || visitedStops[i] != visitedStops[i-1]) {
            uniqueVisitedStops.push_back(visitedStops[i]);
        }
    }
    
    int ans = 0;
    int lastIndex = 0;
    for(int i = 1; i < uniqueVisitedStops.size(); i++) {
        int currentStop = uniqueVisitedStops[i];
        int prevStop = uniqueVisitedStops[i-1];
        
        int currentStopIndex = find(distances.begin(), distances.end(), currentStop) - distances.begin();
        int prevStopIndex = find(distances.begin(), distances.end(), prevStop) - distances.begin();
        
        if(currentStopIndex < prevStopIndex) {
            cout << "-1" << endl;
            return 0;
        }
        
        if(currentStopIndex - prevStopIndex <= 1) {
            ans += distances[currentStopIndex] - distances[prevStopIndex];
        } else {
            ans += distances[prevStopIndex + 1] - distances[prevStopIndex];
        }
        
        lastIndex = currentStopIndex;
    }
    
    cout << ans << endl;
    
    return 0;
}