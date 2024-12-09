#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string directions;
    cin >> directions;
    
    vector<int> positions(n);
    for(int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    int minCollisionTime = INT_MAX;
    unordered_map<int, int> lastPosition;

    for(int i = 0; i < n; i++) {
        if(directions[i] == 'L') {
            if(lastPosition.find(positions[i]) != lastPosition.end()) {
                int time = (i - lastPosition[positions[i]]) / 2;
                minCollisionTime = min(minCollisionTime, time);
            }
            lastPosition[positions[i]] = i;
        }
    }

    if(minCollisionTime == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minCollisionTime << endl;
    }

    return 0;
}