#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> floors(n);
    for(int i = 0; i < n; i++) {
        cin >> floors[i];
    }
    
    sort(floors.begin(), floors.end());
    
    int totalTime = 0;
    for(int i = 0; i < n; i += k) {
        // Pick k people at a time
        for(int j = 0; j < k; j++) {
            if(i + j >= n) break;
            totalTime += 2 * (floors[n-1] - 1);
        }
    }
    
    cout << totalTime << endl;
    
    return 0;
}